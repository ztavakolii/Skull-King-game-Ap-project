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

    serverWindow=new Server(this);
    clientWindow=new Client(this);

    ui->background->showFullScreen();

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    //if(gender == male)
    {
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    }
    //else if(gender == female)
    {
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    }
    ui->guideTextEdit->setReadOnly(true);
    QString guide="I am glad that you accepted the command of our army in this war.Commander give your first order, everyone obeys.\nServer or client?\n\nskull king";
    ui->guideTextEdit->setText(guide);

    ui->serverButton->setStyleSheet("border:none");
    connect(ui->serverButton,SIGNAL(clicked(bool)),this,SLOT(serverButtonClicked()));

    ui->clientButton->setStyleSheet("border:none");
    connect(ui->clientButton,SIGNAL(clicked(bool)),this,SLOT(clientButtonClicked()));


}

ServerOrClientWindow::~ServerOrClientWindow()
{
    delete ui;
}

void ServerOrClientWindow::backButtonClicked()
{
    preWindow->showMaximized();
    this->close();
}

void ServerOrClientWindow::serverButtonClicked()
{
    serverWindow->showMaximized();
    this->close();
}

void ServerOrClientWindow::clientButtonClicked()
{
    clientWindow->showMaximized();
    this->close();
}
