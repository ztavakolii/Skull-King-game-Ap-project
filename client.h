#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTCPSocket>
#include <shared_mutex>
#include <mutex>
#include "clientwaitwindow.h"


namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QMainWindow*clientwindow,QMainWindow*personalwindow,QHostAddress serverIP,QWidget *parent = nullptr);
    ~Client();
    void writeInformation(QByteArray&information);
    //QByteArray readInformation();
    void closeSocket();
    bool getConnectionStatus();
    bool getReceiveStatus();
    bool getSendStatus();
    //void emitReadSignal(QByteArray*information);
    void setReceiveStatus(bool b);// i must set a shared mutex for receiveStatus for reading and writing

private:
    Ui::Client *ui;
  //  QMainWindow*preWindow;
    QTcpSocket*socket;
    bool connectionStatus; //if connection lost it becomes false
    bool receiveStatus;//If information is written to the socket by the server, it is true, otherwise it is false
    bool sendStatus;
    std::shared_mutex mx;// the mutex of reading and writing in connectionStatus
    std::shared_mutex mx2;//the mutex of reading and writing in receiveStatus
    std::shared_mutex mx3;//the mutex of reading and writing in sendStatus
    ClientWaitWindow* clientWaitWindow;
    QMainWindow*clientWindow;
    QMainWindow*personalWindow;
signals:
    void readSignal(QByteArray*information);

private slots:
    void socketConnected();
    void socketReadyRead();
    void socketDisconnected();
    void socketWriteBytes();
    void readInformation(QByteArray*information);

};

#endif // CLIENT_H
