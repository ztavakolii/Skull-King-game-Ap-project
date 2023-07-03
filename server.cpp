#include "server.h"
#include "ui_server.h"
#include <QHostInfo>
#include "person.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <QRegularExpression>


extern Person* User;
extern PlayWindow*playWindow;
extern Player*player;
int numberOfPlayers;
int indexOfWinnerPreviousHand;
int indexOfBeginnerOfHand;
bool isCardSelected=false;
QString codeOfSelectedCard;

using namespace std;

Server::Server(ServerWaitWindow* waitwindow,QString servername,int maxnumberofclients,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    waitWindow=waitwindow;

    Player serverPlayer;
    serverPlayer.setName(User->get_name());
    serverPlayer.setProfile(User->get_profile_picture());
    serverPlayer.setcupsNumber(User->get_cup());

    players.push_back(serverPlayer);

    serverName=servername;
    maxNumberOfClients=maxnumberofclients;
    numberOfConnectedClients=0;
    auto list=QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    // if the computer disconnect from internet in this line the program stops,
    //then we must check connection to internet
    serverIP=list[5]; // for laptop

    server=new QTcpServer;
    server->listen(QHostAddress::Any,8080);
    while(!server->isListening())
        server->listen(QHostAddress::Any,8080);
    connect(server,SIGNAL(newConnection()),this,SLOT(acceptNewConnection()));
    connect(this,SIGNAL(writeSignal(QByteArray,QTcpSocket*)),this,SLOT(writeInPlayerSocket(QByteArray,QTcpSocket*)));
    connect(this,SIGNAL(readSignal(QByteArray*,QTcpSocket*)),this,SLOT(readFromSocket(QByteArray*,QTcpSocket*)));
    connect(this,SIGNAL(playersListChange()),waitWindow,SLOT(showConnectedClients()));
    connect(this,SIGNAL(playStartSignal()),this,SLOT(playStartSlot()));
}

Server::~Server()
{
    delete ui;
    for(vector<std::thread>::iterator it=readingFromPlayersSocketThreads.begin();
         it!=readingFromPlayersSocketThreads.end();it++){
        it->join();
    }
}

void Server::setNumberOfConnectedClientsChangeStatus(bool status)
{
    unique_lock lck(mx);
    numberOfConnectedClientsChangeStatus=status;
}

bool Server::getNumberOfConnectedClientsChangeStatus()
{
    shared_lock lck(mx);
    return numberOfConnectedClientsChangeStatus;
}

int Server::getMaxNumberOfClients()
{
    return maxNumberOfClients;
}

QHostAddress Server::getServerIP()
{
    return serverIP;
}

QByteArray Server::readPlayersList()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<numberOfConnectedClients; // the number of connected clients
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        out<<(*it).getName()<<(*it).getCupsNumber()<<(*it).getProfile();
    }
    return information;
}

void Server::serverDeleted()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'d'<<'s';
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
    server->close();
}

void Server::playStarted()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'p';
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket()); //************************ ***** write in multiple thread?
    }
    numberOfPlayers=players.size();
    gameLogicControl();
}

void Server::serverWantsToStopPlay()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'s'<<'t'<<User->get_name();
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
}

void Server::serverWantsToResumePlay()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'r'<<'s';
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
}

void Server::serverWantsToExit()
{
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'e'<<'t'<<User->get_name();
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
    playWindow->exitCodeReceived(User->get_name());
}

void Server::sentExchangeRequestToClients(QByteArray information)
{
    QString clientName,clientName2;
    int number;
    QDataStream in(&information,QIODevice::ReadOnly);
    QByteArray sentinformation;
    QDataStream out(&sentinformation,QIODevice::WriteOnly);
    in>>clientName>>number;
    clientName2=clientName;
    out<<'e'<<'c'<<clientName;
    for(int i=0;i<number;i++){
        in>>clientName;
        if(clientName!=User->get_name()){
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                if(it->getName()==clientName){
                writeInPlayerSocket(sentinformation,it->getSocket());
                break;
                }
            }
        }
        else{ // an exchange request for server player
            // show exchange request for server in GUI and receive respons
            playWindow->showExchangeRequest(clientName2);
        }
    }
}

void Server::exchangeTwoCardRandomly(QString senderRequest, QString receiverRequest)
{
    QByteArray sentinformation;
    QDataStream out(&sentinformation,QIODevice::WriteOnly);
    if(senderRequest!=User->get_name()){
    out<<'r'<<'p'<<receiverRequest;
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
            if(it->getName()==senderRequest){
                emit writeSignal(sentinformation,it->getSocket());
                break;
            }
    }
    }
    else{
    playWindow->exchangeReplyReceived(receiverRequest);
    }

    int cardIndexOfSenderRequest;
    int cardIndexOfReceiverRequest;
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
    if(it->getName()==senderRequest){
            cardIndexOfSenderRequest=rand()%(it->getCasrdsSet().size());
    }
    if(it->getName()==receiverRequest){
            cardIndexOfReceiverRequest=rand()%(it->getCasrdsSet().size());
    }
    }
    sentinformation.clear();
    if(senderRequest!=User->get_name()){
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
    if(it->getName()==senderRequest){
            // 'e' - 'x' - previous card - new card
            out<<'e'<<'x'<<it->getCasrdsSet()[cardIndexOfSenderRequest]<<it->getCasrdsSet()[cardIndexOfReceiverRequest];
            emit writeSignal(sentinformation,it->getSocket());
            break;
    }
    }
    }
    else{
    // if sender was server
    playWindow->exchangeTwoCard(players[0].getCasrdsSet()[cardIndexOfSenderRequest],players[0].getCasrdsSet()[cardIndexOfReceiverRequest]);
    }
    sentinformation.clear();
    if(receiverRequest!=User->get_name()){
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
    if(it->getName()==receiverRequest){
            // 'e' - 'x' - previous card - new card
            out<<'e'<<'x'<<it->getCasrdsSet()[cardIndexOfReceiverRequest]<<it->getCasrdsSet()[cardIndexOfSenderRequest];
            emit writeSignal(sentinformation,it->getSocket());
            break;
    }
    }
    }
    else{
    // if receiver was server
    playWindow->exchangeTwoCard(players[0].getCasrdsSet()[cardIndexOfReceiverRequest],players[0].getCasrdsSet()[cardIndexOfSenderRequest]);
    }
}

void Server::gameLogicControl()
{
    QByteArray sentinformation;
    QDataStream out(&sentinformation,QIODevice::WriteOnly);

    {
    // sending number of players to clients
    out<<'n'<<numberOfPlayers;
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){ // for clients
     writeInPlayerSocket(sentinformation,it->getSocket());
    }
    playWindow->setNumberOfPlayers(numberOfPlayers); // for server
    }

    {//sending list of players to clients
    sentinformation.clear();
    out<<'l';
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
     out<<it->getName()<<it->getProfile()<<it->getScore();
    }
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
     writeInPlayerSocket(sentinformation,it->getSocket());
    }
    playWindow->setPlayersForserverplayer(sentinformation);
    }

    for(int Round=1;Round<=7;Round++){

    {
     //sending number of round to clients
     sentinformation.clear();
     out<<'r'<<'o'<<Round;
     for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){ // for clients
            writeInPlayerSocket(sentinformation,it->getSocket());
     }
     playWindow->set_round(Round);
    }

    {
     // shuffle cards
     shuffleCards(Round);
     // send players
     for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
            sentinformation.clear();
            out<<'c';
            for(int i=0;i<2*Round;i++){
                out<<it->getCasrdsSet()[i];
            }
            writeInPlayerSocket(sentinformation,it->getSocket());
     }
     player->setCards(players[0].getCasrdsSet());
     playWindow->setCardsIcon();
    }

    for(int Hand=1;Hand<=2*Round;Hand++){

     {
            // send clients number of hand
            sentinformation.clear();
            out<<'h'<<Hand;
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                writeInPlayerSocket(sentinformation,it->getSocket());
            }
            playWindow->set_hand(Hand);
     }

     {
            if(Hand==1){ //determining the beginner of hand
                indexOfBeginnerOfHand=determineBeginnerOfFirstHand();
            }
            else{
                indexOfBeginnerOfHand=indexOfWinnerPreviousHand;
            }
     }
     int currentTurn,preTurn; // these are indexes
     int winnerIndex;
     QString winnerCard,codeOfplayingFieldCard;
     std::vector<QString>cardsOfHand;
    for(int i=0;i<numberOfPlayers;i++){
            if(i==0)
                currentTurn=indexOfBeginnerOfHand;
            else
                currentTurn=(preTurn+1 < numberOfPlayers ? preTurn+1 : preTurn+1-numberOfPlayers);
            {//send next turn to clients
                sentinformation.clear();
                out<<'t'<<currentTurn;
                for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                    writeInPlayerSocket(sentinformation,it->getSocket());
                }
                playWindow->rotate_bottle(currentTurn);
            }

            {
                sentinformation.clear();
                out<<'y';
                writeInPlayerSocket(sentinformation,players[currentTurn].getSocket());
            }
            while(isCardSelected==false);
            isCardSelected=false;
            cardsOfHand.push_back(codeOfSelectedCard);
            {//send code of selected card to clients
                sentinformation.clear();
                out<<'s'<<'w'<<codeOfSelectedCard<<currentTurn;
                for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                    writeInPlayerSocket(sentinformation,it->getSocket());
                }
                playWindow->showCard(currentTurn,codeOfSelectedCard);
            }
            if(i==0){
                winnerIndex=indexOfBeginnerOfHand;
                winnerCard=codeOfSelectedCard;
                codeOfplayingFieldCard=codeOfSelectedCard.remove(QRegularExpression("\\d+"));
            }
            {
                if(codeOfSelectedCard.contains("skullking")||codeOfSelectedCard.contains("queen")
                    ||codeOfSelectedCard.contains("pirate")||codeOfSelectedCard.contains("flag")
                    ||codeOfSelectedCard.contains(codeOfplayingFieldCard)){
                if(codeOfSelectedCard.contains("skullking")||codeOfSelectedCard.contains("queen")||
                    codeOfSelectedCard.contains("pirate")){
                    if(winnerCard.contains("skullking")||winnerCard.contains("queen")||
                        winnerCard.contains("pirate")){
                        if(codeOfSelectedCard=="skullking"&&winnerCard=="pirate"){
                            winnerCard=codeOfSelectedCard;
                            winnerIndex=currentTurn;
                        }
                        else if(codeOfSelectedCard=="pirate"&&winnerCard=="queen"){
                            winnerCard=codeOfSelectedCard;
                            winnerIndex=currentTurn;
                        }
                        else if(codeOfSelectedCard=="queen"&&winnerCard=="skullking"){
                            winnerCard=codeOfSelectedCard;
                            winnerIndex=currentTurn;
                        }
                    }
                    else{
                        winnerCard=codeOfSelectedCard;
                        winnerIndex=currentTurn;
                    }
                }
                else{
                    if(codeOfSelectedCard.contains("flag")){
                        if(winnerCard.contains("flag")){
                            int numberofcurrentcard,numberofwinnercard;
                            numberofcurrentcard=codeOfSelectedCard.toInt();
                            numberofwinnercard=winnerCard.toInt();
                            if(numberofcurrentcard>numberofwinnercard){
                                winnerCard=codeOfSelectedCard;
                                winnerIndex=currentTurn;
                            }
                        }
                        else{
                            winnerCard=codeOfSelectedCard;
                            winnerIndex=currentTurn;
                        }
                    }
                    else{
                        if(winnerCard.contains("skullking")==false&&winnerCard.contains("queen")==false
                            &&winnerCard.contains("pirate")==false&&winnerCard.contains("flag")==false){
                            int numberofcurrentcard,numberofwinnercard;
                            numberofcurrentcard=codeOfSelectedCard.toInt();
                            numberofwinnercard=winnerCard.toInt();
                            if(numberofcurrentcard>numberofwinnercard){
                                winnerCard=codeOfSelectedCard;
                                winnerIndex=currentTurn;
                            }
                        }
                    }
                }
                }
            }
    }
    {// sending name of current hand winner to clients;
            sentinformation.clear();
            out<<'w'<<'h'<<players[winnerIndex].getName();
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                writeInPlayerSocket(sentinformation,it->getSocket());
            }
            playWindow->showWinnerOfCurrentHand(players[winnerIndex].getName());
    }

    players[winnerIndex].setScore(players[winnerIndex].getScore()+
                                  std::count(cardsOfHand.begin(),cardsOfHand.end(),"queen")*20
                                  +std::count(cardsOfHand.begin(),cardsOfHand.end(),"skullking")*15
                                  +std::count(cardsOfHand.begin(),cardsOfHand.end(),"pirate")*10);
    players[winnerIndex].setNumberOfHandsWonInCurrentRoundIncreament();
    indexOfWinnerPreviousHand=winnerIndex;

    {//sending scores to clients
            sentinformation.clear();
            out<<'s'<<'c';
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                out<<it->getScore();
            }
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                writeInPlayerSocket(sentinformation,it->getSocket());
            }
            playWindow->setScoresForServerPlayer(sentinformation);
    }
    }
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
    if(it->getNumberOfHandsSaidWon()==0){
            if(it->getNumberOfHandsWonInCurrentRound()==0)
                it->setScore(it->getScore()+10*Round);
    }
    else{
            int saidwon=it->getNumberOfHandsSaidWon();
            int won=it->getNumberOfHandsWonInCurrentRound();
            if(saidwon>=won)
                it->setScore(it->getScore()+10*won);
            else it->setScore(it->getScore()+10*(saidwon-won));
    }
    }
    {//sending scores to clients
    sentinformation.clear();
    out<<'s'<<'c';
    for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
            out<<it->getScore();
    }
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
            writeInPlayerSocket(sentinformation,it->getSocket());
    }
    playWindow->setScoresForServerPlayer(sentinformation);
    }
    }
}
//card name - numeric code
//---------------------------------------------------------------------------------------------------
// parrot1   1| parrot2   2|parrot3   3|parrot4   4|parrot5   5|parrot6   6|parrot7   7|parrot8   8|
//---------------------------------------------------------------------------------------------------
// map1    9|map2   10|map3   11|map4   12|map5   13|map6   14|map7   15|map8   16|treasure1   17|
//---------------------------------------------------------------------------------------------------
//treasure2   18|treasure3   19|treasure4   20|treasure5   21|treasure6   22|treasure7   23|
//---------------------------------------------------------------------------------------------------
//treasure8   24|flag1   25|flag2   26|flag3   27|flag4   28|flag5   29|flag6   30|flag7   31|
//---------------------------------------------------------------------------------------------------
//flag8   32|skullking1   33|skullking2   34|skullking3   35|queen1   36|queen2   37|queen3   38|
//---------------------------------------------------------------------------------------------------
//pirate1   39|pirate2   40|pirate3   41|pirate4   42|parrot9    43|parrot10   44|parrot11   45|
//---------------------------------------------------------------------------------------------------
//map9   46|map10   47|map11   48|treasure9   49|treasure10   50|treasure11   51|flag9   52|
//---------------------------------------------------------------------------------------------------
//flag10   53|flag11   54|skullking4   55|queen4   56
void Server::shuffleCards(int Round)
{
    std::vector<QString>cardsName{"parrot1","parrot2","parrot3","parrot4","parrot5","parrot6","parrot7","parrot8"
    ,"map1","map2","map3","map4","map5","map6","map7","map8","treasure1","treasure2","treasure3","treasure4"
    "treasure5","treasure6","treasure7","treasure8","flag1","flag2","flag3","flag4","flag5","flag6","flag7",
        "flag8","skullking","skullking","skullking","queen","queen","queen","pirate","pirate","pirate","pirate"
    ,"parrot9","parrot10","parrot11","map9","map10","map11","treasure9","treasure10","treasure11",
                                   "falg9","falg10","falg11","skullking","queen"};

    vector<int>numericCodes;
    vector<QString>cards;

    if(numberOfPlayers==4){
    while(true){
    int generatedNumber=rand()%56;
    if(std::find(numericCodes.begin(),numericCodes.end(),generatedNumber)==numericCodes.end())
    numericCodes.push_back(generatedNumber);
    if(numericCodes.size()==8*Round)
    break;
    }

    for(int i=0;i<2*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[0].clearCardsVector();
    players[0].setCards(cards);

    cards.clear();
    for(int i=2*Round;i<4*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[1].clearCardsVector();
    players[1].setCards(cards);

    cards.clear();
    for(int i=4*Round;i<6*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[2].clearCardsVector();
    players[2].setCards(cards);

    cards.clear();
    for(int i=6*Round;i<8*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[3].clearCardsVector();
    players[3].setCards(cards);
    }

    else if(numberOfPlayers==3){
    while(true){
    int generatedNumber=rand()%42;
    if(std::find(numericCodes.begin(),numericCodes.end(),generatedNumber)==numericCodes.end())
    numericCodes.push_back(generatedNumber);
    if(numericCodes.size()==6*Round)
    break;
    }

    for(int i=0;i<2*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[0].clearCardsVector();
    players[0].setCards(cards);

    cards.clear();
    for(int i=2*Round;i<4*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[1].clearCardsVector();
    players[1].setCards(cards);

    cards.clear();
    for(int i=4*Round;i<6*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[2].clearCardsVector();
    players[2].setCards(cards);
    }

    else if(numberOfPlayers==2){
    while(true){
    int generatedNumber=rand()%42;
    if(std::find(numericCodes.begin(),numericCodes.end(),generatedNumber)==numericCodes.end())
    numericCodes.push_back(generatedNumber);
    if(numericCodes.size()==4*Round)
    break;
    }

    for(int i=0;i<2*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[0].clearCardsVector();
    players[0].setCards(cards);

    cards.clear();
    for(int i=2*Round;i<4*Round;i++){
    cards.push_back(cardsName[numericCodes[i]]);
    }
    players[1].clearCardsVector();
    players[1].setCards(cards);
    }
}

int Server::determineBeginnerOfFirstHand()
{
    std::vector<int> randomnumbers;
    while(true){
    int generated=rand()%8;
    if(std::find(randomnumbers.begin(),randomnumbers.end(),generated)==randomnumbers.end())
    randomnumbers.push_back(generated);
    if(randomnumbers.size()==numberOfPlayers)
    break;
    }
    auto maxelement=std::max_element(randomnumbers.begin(),randomnumbers.end());
    int maxindex=std::distance(randomnumbers.begin(),maxelement);
    return maxindex;
}

void Server::readFromPlayersocket(QTcpSocket* socket)
{
    char mainCode, subCode;
    QString clientName,clientName2,senderRequest,receiverRequest,cardCode;
    int clientCupNumber,number;
    QPixmap clientProfilePicture;

    // mainCode                 | Received information
    //----------------------------------------------------------------------------------------
    // 'a' "add"                | client name - client's cups number - client's profile picture
    //----------------------------------------------------------------------------------------
    // 'd' "delete"             | deleted client's name
    //----------------------------------------------------------------------------------------
    // 'e' "exit"               | 't' - The name of the player who want to exit
    //----------------------------------------------------------------------------------------
    // 's' "stop"               |'t' - The name of player who want to stop play
    //----------------------------------------------------------------------------------------
    // 'r' "resume"             | 's'
    //----------------------------------------------------------------------------------------
    // 'e' "exchange"           | 'c'- name of player who want to exchange cart - number of players - names of players
    //----------------------------------------------------------------------------------------
    // 'c' "chosen card"        | card code
    //----------------------------------------------------------------------------------------
    // 'r' "reply exchange card"| 'p' - name of sernder of request - name of receiver of request
    //----------------------------------------------------------------------------------------

    while(true){
        if(socket->waitForReadyRead(-1))
        {
            QByteArray receivedInformation="";
        emit readSignal(&receivedInformation,socket);
            while(receivedInformation=="");
        QDataStream in(&receivedInformation,QIODevice::ReadOnly);
        in>>mainCode;

        QByteArray sentinformation;
        QDataStream out(&sentinformation,QIODevice::WriteOnly);

        switch(mainCode){

        case 'a':

            in>>clientName>>clientCupNumber>>clientProfilePicture;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                if(it->getSocket()==socket){
                    it->setName(clientName);
                    it->setcupsNumber(clientCupNumber);
                    it->setProfile(clientProfilePicture);
                    emit playersListChange();
                    break;
                }
            }
            sentinformation.clear();
            out<<'b'<<serverName<<maxNumberOfClients+1<<numberOfConnectedClients+1;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                out<<it->getName()<<it->getCupsNumber()<<it->getProfile();
            }
           // writeInPlayerSocket(sentinformation,socket);
            emit writeSignal(sentinformation,socket);

            sentinformation.clear();
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                out<<'a'<<clientName<<clientCupNumber<<clientProfilePicture;
                //writeInPlayerSocket(sentinformation,it->getSocket());
                emit writeSignal(sentinformation,it->getSocket());
                sentinformation.clear();
            }
            { unique_lock lck3(mx2);
            numberOfConnectedClients++;
                if(numberOfConnectedClients==maxNumberOfClients)
                    emit playStartSignal();
            }
            break;

        case 'd':
            in>>clientName;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                if(it->getName()==clientName){
                    players.erase(it);
                    emit playersListChange();
                    break;
                }
            }
            sentinformation.clear();
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                sentinformation.clear();
                out<<'d'<<'c'<<clientName;
                //writeInPlayerSocket(sentinformation,it->getSocket());
                emit writeSignal(sentinformation,it->getSocket());
            }
            {
            unique_lock lck1(mx);
            numberOfConnectedClientsChangeStatus=true;
            unique_lock lck2(mx2);
            numberOfConnectedClients--;
            }
            break;
        case 'e':
           in>>subCode;
            switch(subCode){
            case 't':
            in>>clientName;
            sentinformation.clear();
            out<<'e'<<'t'<<clientName;
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                    emit writeSignal(sentinformation,it->getSocket());
            }
            playWindow->exitCodeReceived(clientName);
            break;

            case 'c':
            sentExchangeRequestToClients(receivedInformation);
            break;
            }
            break;

        case 's':
            in>>subCode;
            switch(subCode){
            case 't':
            in>>clientName;
            sentinformation.clear();
            out<<'s'<<'t'<<clientName;
           for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                    if(it->getName()!=clientName){
                        emit writeSignal(sentinformation,it->getSocket());
                    }
            }
           playWindow->stopCodeReceived(false,clientName);
            break;
            }

            break;

        case 'c':
            in>>codeOfSelectedCard;
            isCardSelected=true;
            break;

        case 'r':
            in>>subCode;
            switch(subCode){
            case 's':
            sentinformation.clear();
            out<<'r'<<'s';
            for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
                    emit writeSignal(sentinformation,it->getSocket());
            }
            playWindow->resumeCodeReceived();
            break;

            case 'p':
            in>>senderRequest>>receiverRequest;
            exchangeTwoCardRandomly(senderRequest,receiverRequest);
            break;
            }
            break;
        }
        }
    }
}

void Server::writeInPlayerSocket(QByteArray information, QTcpSocket *socket)
{
    socket->write(information);
}

void Server::readFromSocket(QByteArray *information, QTcpSocket *socket)
{
    *information=socket->readAll();
}

void Server::playStartSlot()
{
    playStarted();
    playWindow->showMaximized();
}

void Server::acceptNewConnection()
{
    if(numberOfConnectedClients < maxNumberOfClients){
    Player newPlayer;
    newPlayer.setSocket(server->nextPendingConnection());
    players.push_back(newPlayer);
    readingFromPlayersSocketThreads.push_back(std::thread(&Server::readFromPlayersocket,this,newPlayer.getSocket()));
    unique_lock lck1(mx);
    numberOfConnectedClientsChangeStatus=true;
    unique_lock lck2(mx2);
    numberOfConnectedClients++;
    }
    else {
    QTcpSocket*socket=server->nextPendingConnection();
    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'r';   // 'r' "reject"
    writeInPlayerSocket(information,socket);
    socket->disconnectFromHost();
    }
}
