#include "personalwindow.h"
#include "ui_personalwindow.h"
#include "person.h"
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QSoundEffect>

extern Person* User;
extern QSoundEffect*clickSound;

PersonalWindow::PersonalWindow(QMainWindow* prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonalWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,700);

    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Profile");

    ui->background->showFullScreen();


    // I must allocate memory for store Window



    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    ui->storeButton->setStyleSheet("border:none");
    connect(ui->storeButton,SIGNAL(clicked(bool)),this,SLOT(storeButtonClicked()));

    ui->historyButton->setStyleSheet("border:none");
    connect(ui->historyButton,SIGNAL(clicked(bool)),this,SLOT(historyButtonClicked()));


    if(User->get_gender()=="Male")
    {
        ui->playImageLabel->setGeometry(995,360,110,110);
        ui->playTextLabel->setGeometry(955,410,70,30);
        ui->playButton->setGeometry(950,350,180,130);
        ui->playButton->setStyleSheet("border:none");
        QPixmap p(":/new/image/pngwing.com (6).png");
        ui->playImageLabel->setPixmap(p);
    }
    else if(User->get_gender()=="Female")
    {
        ui->playImageLabel->setGeometry(990,365,90,97);
        ui->playTextLabel->setGeometry(1080,400,70,30);
        ui->playButton->setGeometry(970,350,180,130);
        ui->playButton->setStyleSheet("border:none");
        QPixmap p(":/new/image/pngwing.com (4).png");
        ui->playImageLabel->setPixmap(p);
    }
    connect(ui->playButton,SIGNAL(clicked(bool)),this,SLOT(playButtonClicked()));

    ui->profileImageLabel->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileImageLabel->setLineWidth(3);
    ui->profileImageLabel->setMidLineWidth(3);
    ui->profileImageLabel->setPixmap(User->get_profile_picture());

    ui->nameLineEdit->setReadOnly(true);
    if(User->get_gender()=="Male")
    ui->nameLineEdit->setStyleSheet("background-color:rgb(0, 0, 0);color:rgb(0, 170, 255);");
    else if(User->get_gender()=="Female")
    ui->nameLineEdit->setStyleSheet("background-color:rgb(0, 0, 0);color:rgb(255, 85, 127);");
    // read the player's name from file and set the text of nameLineEdit with player's name
    ui->nameLineEdit->setText(" "+User->get_name());

    ui->editProfileButton->setIcon(QIcon(":/new/image/icons8-edit-80.png"));
    ui->editProfileButton->setStyleSheet("border:none");
    ui->editProfileButton->setIconSize(QSize(30,30));
    connect(ui->editProfileButton,SIGNAL(clicked(bool)),this,SLOT(editProfileButtonClicked()));

    // set the number of cups and number of coins from file
    ui->coinNumberLabel->setText(QString::number(User->get_coin()));
    ui->cupNumberLabel->setText(QString::number(User->get_cup()));

}

PersonalWindow::~PersonalWindow()
{
    delete ui;
}

void PersonalWindow::showEvent(QShowEvent *event)
{
    User->read_information_from_file();

    if(User->get_gender()=="Male")
    {
    ui->playImageLabel->setGeometry(995,360,110,110);
    ui->playTextLabel->setGeometry(955,410,70,30);
    ui->playButton->setGeometry(950,350,180,130);
    ui->playButton->setStyleSheet("border:none");
    QPixmap p(":/new/image/pngwing.com (6).png");
    ui->playImageLabel->setPixmap(p);
    }
    else if(User->get_gender()=="Female")
    {
    ui->playImageLabel->setGeometry(990,365,90,97);
    ui->playTextLabel->setGeometry(1080,400,70,30);
    ui->playButton->setGeometry(970,350,180,130);
    ui->playButton->setStyleSheet("border:none");
    QPixmap p(":/new/image/pngwing.com (4).png");
    ui->playImageLabel->setPixmap(p);
    }

    if(User->get_gender()=="Male")
    ui->nameLineEdit->setStyleSheet("background-color:rgb(0, 0, 0);color:rgb(0, 170, 255);");
    else if(User->get_gender()=="Female")
    ui->nameLineEdit->setStyleSheet("background-color:rgb(0, 0, 0);color:rgb(255, 85, 127);");

    ui->profileImageLabel->setPixmap(User->get_profile_picture());
    ui->nameLineEdit->setText(" "+User->get_name());
    ui->coinNumberLabel->setText(QString::number(User->get_coin()));
    ui->cupNumberLabel->setText(QString::number(User->get_cup()));

    QMainWindow::showEvent(event);
}

void PersonalWindow::backButtonClicked()
{
    clickSound->play();
    preWindow->showMaximized();
    this->close();
}

void PersonalWindow::storeButtonClicked()
{
    clickSound->play();
    Buy=new buy(this);
    Buy->showMaximized();
    this->close();
}

void PersonalWindow::historyButtonClicked()
{
    clickSound->play();
    historyWindow=new HistoryWindow(this);
    historyWindow->showMaximized();
    this->close();
}

void PersonalWindow::playButtonClicked()
{
    clickSound->play();
    serverOrClientWindow=new ServerOrClientWindow(this);
    serverOrClientWindow->showMaximized();
    this->close();
}

void PersonalWindow::editProfileButtonClicked()
{
    clickSound->play();
    editProfileWindow=new EditProfileWindow(preWindow,this);
    editProfileWindow->showMaximized();
    this->close();
}


