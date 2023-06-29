#include "server.h"
#include "ui_server.h"
#include <QHostInfo>
#include "person.h"

extern Person* User;

using namespace std;

Server::Server(QString servername,int maxnumberofclients,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    Player serverPlayer;
    serverPlayer.setName(User->get_name());
    serverPlayer.setProfile(User->get_profile_picture());
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
    QDataStream out(information);
    out<<players.size(); // the number of connected clients
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        out<<(*it).getName()<<(*it).getCupsNumber()<<(*it).getProfile();
    }
    return information;
}

void Server::serverDeleted()
{
    QByteArray information;
    QDataStream out(information);
    out<<'d'<<'s';
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
    server->close();
}

void Server::playStarted()
{
    QByteArray information;
    QDataStream out(information);
    out<<'p';
    for(vector<Player>::iterator it=players.begin()+1;it!=players.end();it++){
        writeInPlayerSocket(information,it->getSocket());
    }
}

void Server::readFromPlayersocket(QTcpSocket* socket)
{
    char mainCode;
    QString clientName;
    int clientCupNumber;
    QPixmap clientProfilePicture;

    // mainCode         | Received information
    //----------------------------------------------------------------------------------------
    // 'a' "add"        | client name - client's cups number - client's profile picture
    //----------------------------------------------------------------------------------------
    // 'd' "delete"     | deleted client's name
    //----------------------------------------------------------------------------------------

    while(true){
        while(!socket->waitForReadyRead(-1));
        QByteArray receivedInformation;
        QDataStream in(receivedInformation);
        in>>mainCode;

        QByteArray sentinformation;
        QDataStream out(sentinformation);

        switch(mainCode){

        case 'a':

            in>>clientName>>clientCupNumber>>clientProfilePicture;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                if(it->getSocket()==socket){
                    it->setName(clientName);
                    it->setcupsNumber(clientCupNumber);
                    it->setProfile(clientProfilePicture);
                    break;
                }
            }

            out<<'b'<<serverName<<maxNumberOfClients+1<<numberOfConnectedClients+1;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                out<<it->getName()<<it->getCupsNumber()<<it->getProfile();
            }
            writeInPlayerSocket(sentinformation,socket);

            sentinformation.clear();
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                out<<'a'<<clientName<<clientCupNumber<<clientProfilePicture;
                writeInPlayerSocket(sentinformation,it->getSocket());
                sentinformation.clear();
            }

            break;

        case 'd':
            in>>clientName;
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                if(it->getName()==clientName){
                    players.erase(it);
                    break;
                }
            }
            for(vector<Player>::iterator it=players.begin();it!=players.end();it++){
                sentinformation.clear();
                out<<'d'<<'c'<<clientName;
                writeInPlayerSocket(sentinformation,it->getSocket());
            }
            unique_lock lck1(mx);
            numberOfConnectedClientsChangeStatus=true;
            unique_lock lck2(mx2);
            numberOfConnectedClients--;
            break;

        }
    }
}

void Server::writeInPlayerSocket(QByteArray &information, QTcpSocket *socket)
{
    socket->write(information);
}

void Server::acceptNewConnection()
{
    if(numberOfConnectedClients<maxNumberOfClients){
    Player newPlayer;
    newPlayer.setSocket(server->nextPendingConnection());
    players.push_back(newPlayer);
   // std::thread t(readFromPlayersocket,newPlayer.getSocket());
    readingFromPlayersSocketThreads.push_back(std::thread(&Server::readFromPlayersocket,this,newPlayer.getSocket()));
    unique_lock lck1(mx);
    numberOfConnectedClientsChangeStatus=true;
    unique_lock lck2(mx2);
    numberOfConnectedClients++;
    }
    else {
    QTcpSocket*socket=server->nextPendingConnection();
    QByteArray information;
    QDataStream out(information);
    out<<'r';   // 'r' "reject"
    writeInPlayerSocket(information,socket);
    socket->disconnectFromHost();
    }
}
