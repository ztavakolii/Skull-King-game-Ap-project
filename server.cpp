#include "server.h"
#include "ui_server.h"

Server::Server(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Become a Server");

}

Server::~Server()
{
    delete ui;
}
