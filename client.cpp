#include "client.h"
#include "ui_client.h"

Client::Client(QHostAddress serverIP,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    socket=new QTcpSocket;
    socket->connectToHost(serverIP,8080);
    connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));

}

Client::~Client()
{
    delete ui;
}

void Client::socketConnected()
{
    connectionStatus=true;
}

void Client::socketReadyRead()
{
    receiveStatus=true;
}

void Client::socketDisconnected()
{
    connectionStatus=false;
}

void Client::writeInformation(QByteArray&information){
    socket->write(information);
}

QByteArray Client::readInformation()
{
    receiveStatus=false;
    return socket->readAll();
}

void Client::closeSocket()
{
    socket->close();
}

