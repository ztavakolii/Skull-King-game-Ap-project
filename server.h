#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <QByteArray>
#include <QDataStream>
#include "player.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QString servername,int numberofclients,QWidget *parent = nullptr);
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

    void readFromPlayersocket(QTcpSocket*socket);
    void writeInPlayerSocket(QByteArray&information,QTcpSocket*socket);

private slots:
    void acceptNewConnection();

};

#endif // SERVER_H
