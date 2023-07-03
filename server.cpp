#include "server.h"
#include "ui_server.h"
#include <QHostInfo>
#include "person.h"
#include <ctime>
#include <cstdlib>


extern Person* User;
extern PlayWindow*playWindow;

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

void Server::readFromPlayersocket(QTcpSocket* socket)
{
    char mainCode, subCode;
    QString clientName,clientName2,senderRequest,receiverRequest;
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
    // 'c' "chosen card"        | card code - index of player that play this card
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
