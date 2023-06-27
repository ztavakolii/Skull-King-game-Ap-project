#include "clientwaitwindow.h"
#include "ui_clientwaitwindow.h"

ClientWaitWindow::ClientWaitWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWaitWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Waiting for the server to complete");
}

ClientWaitWindow::~ClientWaitWindow()
{
    delete ui;
}
