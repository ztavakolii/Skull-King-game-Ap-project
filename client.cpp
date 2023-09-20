#include "client.h"
#include "ui_client.h"

Client::Client(QMainWindow*clientwindow,QMainWindow*personalwindow,QHostAddress serverIP,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    clientWindow=clientwindow;
    personalWindow=personalwindow;

    socket=new QTcpSocket;

    connectionStatus=false;
    receiveStatus=false;
    sendStatus=false;

    socket->connectToHost(serverIP,8080);

    connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(socketWriteBytes()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    connect(this,SIGNAL(readSignal(QByteArray*)),this,SLOT(readInformation(QByteArray*)));

}

Client::~Client()
{
    delete ui;
}

void Client::socketConnected()
{
    if(socket->waitForConnected(-1)){
    std::unique_lock lck(mx);
    connectionStatus=true;
    clientWaitWindow=new ClientWaitWindow(personalWindow,clientWindow);
    clientWaitWindow->showMaximized();
    clientWindow->close();
    }
}

void Client::socketReadyRead()
{
    std::unique_lock lck(mx2);
    receiveStatus=true;
}

void Client::socketDisconnected()
{
    std::unique_lock lck(mx);
    connectionStatus=false;
}

void Client::socketWriteBytes()
{
    std::unique_lock lck(mx3);
    sendStatus=true;
}

void Client::writeInformation(QByteArray&information){
    socket->write(information);
    socket->waitForBytesWritten(-1);
}

void Client::readInformation(QByteArray*information)
{
    *information = socket->readAll();
    std::unique_lock lck(mx2);
    receiveStatus=false;
}

void Client::closeSocket()
{
    socket->disconnectFromHost();
    std::unique_lock lck(mx);
    connectionStatus=false;
}

bool Client::getConnectionStatus()
{
    std::shared_lock lck(mx);
    return connectionStatus;
}

bool Client::getReceiveStatus()
{
    std::shared_lock lck(mx2);
    return receiveStatus;
}

bool Client::getSendStatus()
{
    std::shared_lock lck(mx3);
    return sendStatus;
}

void Client::setReceiveStatus(bool b)
{
    std::unique_lock lck(mx2);
    receiveStatus=b;
}


