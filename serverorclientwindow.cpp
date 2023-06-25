#include "serverorclientwindow.h"
#include "ui_serverorclientwindow.h"

ServerOrClientWindow::ServerOrClientWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerOrClientWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Server or Client?");
}

ServerOrClientWindow::~ServerOrClientWindow()
{
    delete ui;
}
