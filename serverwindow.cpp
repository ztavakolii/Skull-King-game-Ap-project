#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include "person.h"
#include"serverwaitwindow.h"

extern Person *User;

ServerWindow::ServerWindow(QMainWindow*prewindow,QMainWindow*personalwindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;
    personalWindow=personalwindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Become Server");

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    if(User->get_gender()=="Male"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->serverNamelineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->maxNumberOfClientsComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    }
    else if(User->get_gender()=="Female"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->serverNamelineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->maxNumberOfClientsComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    }

    ui->guideTextEdit->setReadOnly(true);
    ui->guideTextEdit->setText("Commander, now you have to choose a powerful name for your server, then decide on the number of clients you want to fight.\n\nSkull King");

    QStringList numbers={"1","2","3"};
    ui->maxNumberOfClientsComboBox->addItems(numbers);

    ui->confirmButton->setStyleSheet("border:none");
    connect(ui->confirmButton,SIGNAL(clicked(bool)),this,SLOT(confirmButtonClicked()));

}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::backButtonClicked()
{
    preWindow->showMaximized();
    this->close();
}

void ServerWindow::confirmButtonClicked()
{
    if(ui->serverNamelineEdit->text().length()==0){
        QMessageBox*message=new QMessageBox(this);
        message->critical(this,"Become Server","You must Enter a Server name.");
        //set style sheet of this message
    }
    else{
        User->set_server(ui->serverNamelineEdit->text(),ui->maxNumberOfClientsComboBox->currentText().toInt());
        serverWaitWindow=new ServerWaitWindow(personalWindow);
        serverWaitWindow->showMaximized();
        this->close();
    }
}
