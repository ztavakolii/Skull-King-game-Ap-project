#include "client.h"
#include "ui_client.h"

Client::Client(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Become Client");
}

Client::~Client()
{
    delete ui;
}
