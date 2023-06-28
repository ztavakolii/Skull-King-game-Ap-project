#include "serverwaitwindow.h"
#include "ui_serverwaitwindow.h"

ServerWaitWindow::ServerWaitWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWaitWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Waiting for the server to complete");
}

ServerWaitWindow::~ServerWaitWindow()
{
    delete ui;
}
