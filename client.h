#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTCPSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QHostAddress serverIP,QWidget *parent = nullptr);
    ~Client();
    void writeInformation(QByteArray&information);
    QByteArray readInformation();
    void closeSocket();

private:
    Ui::Client *ui;
  //  QMainWindow*preWindow;
    QTcpSocket*socket;
    bool connectionStatus; //if connection lost it becomes false
    bool receiveStatus;//If information is written to the socket by the server, it is true, otherwise it is false

private slots:
    void socketConnected();
    void socketReadyRead();
    void socketDisconnected();

};

#endif // CLIENT_H
