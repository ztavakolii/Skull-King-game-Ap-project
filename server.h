#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QTcpServer>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <QByteArray>
#include <QDataStream>
#include "player.h"
#include "serverwaitwindow.h"
=======
#include "ui_server.h"
#include "QTcpServer"
//#include <channel.h>
>>>>>>> Vania

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(ServerWaitWindow* waitwindow,QString servername,int numberofclients,QWidget *parent = nullptr);
    ~Server();
    void setNumberOfConnectedClientsChangeStatus(bool status);
    bool getNumberOfConnectedClientsChangeStatus();
    int getMaxNumberOfClients();
    QHostAddress getServerIP();
    QByteArray readPlayersList();
    void serverDeleted();
    void playStarted();



private:
    Ui::Server *ui;
<<<<<<< HEAD
   // QMainWindow*preWindow;
    QTcpServer*server;
    QString serverName;
    int maxNumberOfClients;//this is the number of clients that server accept
    int numberOfConnectedClients;
    QHostAddress serverIP;
    std::vector<Player>players; //list of clients
    std::vector<std::thread> readingFromPlayersSocketThreads;
    bool numberOfConnectedClientsChangeStatus;
    std::shared_mutex mx; // this is for mangement writing in newConnectionStatus
                          //by acceptNewConnection and setNewConnectionStatus functions
    std::shared_mutex mx2;
    ServerWaitWindow*waitWindow;
//    void readFromPlayersocket(QTcpSocket*socket);
//    void writeInPlayerSocket(QByteArray&information,QTcpSocket*socket);

signals:
    void writeSignal(QByteArray information,QTcpSocket*socket);
    void readSignal(QByteArray* information,QTcpSocket*socket);
    void playersListChange();

private slots:
    void acceptNewConnection();
    void readFromPlayersocket(QTcpSocket*socket);
    void writeInPlayerSocket(QByteArray information,QTcpSocket*socket);
    void readFromSocket(QByteArray* information,QTcpSocket*socket);
=======
    QMainWindow*preWindow;
public:
>>>>>>> Vania

};

#endif // SERVER_H
