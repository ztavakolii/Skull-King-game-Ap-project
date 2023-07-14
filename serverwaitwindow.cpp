#include "serverwaitwindow.h"
#include "ui_serverwaitwindow.h"
#include "person.h"
#include <QMessageBox>
#include <QSoundEffect>

extern Person* User;
extern PlayWindow*playWindow;
extern QSoundEffect*clickSound;

ServerWaitWindow::ServerWaitWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWaitWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,700);

    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Waiting for the server to complete");

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    ui->backButton->hide();//hiding backButton

    ui->profileLabel1->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileLabel2->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileLabel3->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);

    ui->background->showFullScreen();

    if(User->get_gender()=="Male"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    }
    else if(User->get_gender()=="Female"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    }

    ui->guideTextEdit->setReadOnly(true);

    ui->deleteServerButton->setStyleSheet("border:none");
    connect(ui->deleteServerButton,SIGNAL(clicked(bool)),this,SLOT(deleteServerButtonClicked()));

    ui->PlayButton->setStyleSheet("border:none");
    connect(ui->PlayButton,SIGNAL(clicked(bool)),this,SLOT(playButtonClicked()));
    ui->PlayButton->setToolTip("Click me, if you want to start the game with the same number of present clients.");
    ui->PlayButton->hide();
    ui->label_11->hide();
    ui->label_12->hide();


    ui->profileLabel1->hide();
    ui->nameLabel1->hide();
    ui->cupLabel1->hide();
    ui->cupNumberLabel1->hide();
    ui->label_3->hide();

    ui->profileLabel2->hide();
    ui->nameLabel2->hide();
    ui->cupLabel2->hide();
    ui->cupNumberLabel2->hide();
    ui->label_4->hide();

    ui->profileLabel3->hide();
    ui->nameLabel3->hide();
    ui->cupLabel3->hide();
    ui->cupNumberLabel3->hide();
    ui->label_5->hide();

}

ServerWaitWindow::~ServerWaitWindow()
{
    delete ui;
}

void ServerWaitWindow::setGuideTextEdit()
{
    ui->guideTextEdit->setText("Commander, now we have to wait until the number of clients connected to your server reaches "
                               +QString::number(User->get_server()->getMaxNumberOfClients())
                               +" people, after \nthat the war will begin.\nI was informed that the IP of your server is "+
                               User->get_server()->getServerIP().toString()+"\nSkull King");
}

QMainWindow *ServerWaitWindow::getPreWindow()
{
    return preWindow;
}

void ServerWaitWindow::backButtonClicked()
{
    clickSound->play();
    preWindow->showMaximized();
    this->close();
}

void ServerWaitWindow::deleteServerButtonClicked()
{
    clickSound->play();

    QMessageBox message;
    message.setText("Are you sure you want to delete your server?");
    message.setIcon(QMessageBox::Warning);
    message.setWindowIcon(QIcon(":/new/image/gamename.png"));
    message.setStyleSheet("background-color: rgb(236, 197, 119)");
    message.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    int result=message.exec();
    if(result==QMessageBox::Yes){
        deleteServer();
    }
}

void ServerWaitWindow::playButtonClicked()
{
    clickSound->play();

    //User->get_server()->playStarted();
    playWindow=new PlayWindow(preWindow);
    playWindow->showMaximized();
    this->close();
    User->get_server()->playStarted();
}

void ServerWaitWindow::deleteServer()
{
    User->get_server()->serverDeleted();
    preWindow->showMaximized();
    this->close();
}

void ServerWaitWindow::showConnectedClients()
{
    QByteArray information;
    QDataStream in(&information,QIODevice::ReadOnly);
    QString clientName;
    int clientCupNumber,numberOfConnectedClients;
    QPixmap clientProfilePicture;
            information=User->get_server()->readPlayersList();
            in>>numberOfConnectedClients;
            if(numberOfConnectedClients==0){
                ui->PlayButton->hide();
                ui->label_11->hide();
                ui->label_12->hide();


                ui->profileLabel1->hide();
                ui->nameLabel1->hide();
                ui->cupLabel1->hide();
                ui->cupNumberLabel1->hide();
                ui->label_3->hide();

                ui->profileLabel2->hide();
                ui->nameLabel2->hide();
                ui->cupLabel2->hide();
                ui->cupNumberLabel2->hide();
                ui->label_4->hide();

                ui->profileLabel3->hide();
                ui->nameLabel3->hide();
                ui->cupLabel3->hide();
                ui->cupNumberLabel3->hide();
                ui->label_5->hide();
            }
            else if(numberOfConnectedClients==1){
                ui->PlayButton->show();
                ui->label_11->show();
                ui->label_12->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                    QPixmap scaledImage(clientProfilePicture);
                    scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel1->setPixmap(scaledImage);
                ui->nameLabel1->setText(clientName);
                ui->cupNumberLabel1->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel1->show();
                ui->nameLabel1->show();
                ui->cupLabel1->show();
                ui->cupNumberLabel1->show();
                ui->label_3->show();

                ui->profileLabel2->hide();
                ui->nameLabel2->hide();
                ui->cupLabel2->hide();
                ui->cupNumberLabel2->hide();
                ui->label_4->hide();

                ui->profileLabel3->hide();
                ui->nameLabel3->hide();
                ui->cupLabel3->hide();
                ui->cupNumberLabel3->hide();
                ui->label_5->hide();
            }
            else if(numberOfConnectedClients==2){
                ui->PlayButton->show();
                ui->label_11->show();
                ui->label_12->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                QPixmap scaledImage(clientProfilePicture);
                scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel1->setPixmap(scaledImage);
                ui->nameLabel1->setText(clientName);
                ui->cupNumberLabel1->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel1->show();
                ui->nameLabel1->show();
                ui->cupLabel1->show();
                ui->cupNumberLabel1->show();
                ui->label_3->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                QPixmap scaledImage(clientProfilePicture);
                scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel2->setPixmap(scaledImage);
                ui->nameLabel2->setText(clientName);
                ui->cupNumberLabel2->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel2->show();
                ui->nameLabel2->show();
                ui->cupLabel2->show();
                ui->cupNumberLabel2->show();
                ui->label_4->show();

                ui->profileLabel3->hide();
                ui->nameLabel3->hide();
                ui->cupLabel3->hide();
                ui->cupNumberLabel3->hide();
                ui->label_5->hide();
            }
            else if(numberOfConnectedClients==3){
                ui->PlayButton->show();
                ui->label_11->show();
                ui->label_12->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                QPixmap scaledImage(clientProfilePicture);
                scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel1->setPixmap(scaledImage);
                ui->nameLabel1->setText(clientName);
                ui->cupNumberLabel1->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel1->show();
                ui->nameLabel1->show();
                ui->cupLabel1->show();
                ui->cupNumberLabel1->show();
                ui->label_3->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                QPixmap scaledImage(clientProfilePicture);
                scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel2->setPixmap(scaledImage);
                ui->nameLabel2->setText(clientName);
                ui->cupNumberLabel2->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel2->show();
                ui->nameLabel2->show();
                ui->cupLabel2->show();
                ui->cupNumberLabel2->show();
                ui->label_4->show();

                in>>clientName>>clientCupNumber>>clientProfilePicture;
                {
                QPixmap scaledImage(clientProfilePicture);
                scaledImage=scaledImage.scaled(50,50);
                ui->profileLabel3->setPixmap(scaledImage);
                ui->nameLabel3->setText(clientName);
                ui->cupNumberLabel3->setText(QString::number(clientCupNumber));
                }

                ui->profileLabel3->show();
                ui->nameLabel3->show();
                ui->cupLabel3->show();
                ui->cupNumberLabel3->show();
                ui->label_5->show();
            }
        }

