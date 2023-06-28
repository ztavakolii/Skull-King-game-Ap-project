#include "client.h"
#include "ui_client.h"

Client::Client(QHostAddress serverIP,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    socket=new QTcpSocket;

    connectionStatus=false;
    receiveStatus=false;
    sendStatus=false;

    connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(socketWriteBytes()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));

    socket->connectToHost(serverIP,16000);

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

void Client::socketWriteBytes()
{
    sendStatus=true;
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
    socket->disconnectFromHost();
    connectionStatus=false;
}

bool Client::getConnectionStatus()
{
    return connectionStatus;
}

bool Client::getReceiveStatus()
{
    return receiveStatus;
}

bool Client::getSendStatus()
{
    return sendStatus;
}

