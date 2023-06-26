#include "personalwindow.h"
#include "ui_personalwindow.h"

PersonalWindow::PersonalWindow(QMainWindow* prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonalWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Profile");

    ui->background->showFullScreen();


    // I must allocate memory for store Window
    historyWindow=new HistoryWindow(this);
    serverOrClientWindow=new ServerOrClientWindow(this);
    editProfileWindow=new EditProfileWindow(preWindow,this);



    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    ui->storeButton->setStyleSheet("border:none");
    connect(ui->storeButton,SIGNAL(clicked(bool)),this,SLOT(storeButtonClicked()));

    ui->historyButton->setStyleSheet("border:none");
    connect(ui->historyButton,SIGNAL(clicked(bool)),this,SLOT(historyButtonClicked()));


//if(gender==male)
    {
        ui->playImageLabel->setGeometry(995,360,110,110);
        ui->playTextLabel->setGeometry(955,410,70,30);
        ui->playButton->setGeometry(950,350,180,130);
        ui->playButton->setStyleSheet("border:none");
        QPixmap p(":/new/image/pngwing.com (6).png");
        ui->playImageLabel->setPixmap(p);
    }
    //else if(gender ==female)
//    {
//        ui->playImageLabel->setGeometry(990,365,90,97);
//        ui->playTextLabel->setGeometry(1080,400,70,30);
//        ui->playButton->setGeometry(970,350,180,130);
//        ui->playButton->setStyleSheet("border:none");
//        QPixmap p(":/new/image/pngwing.com (4).png");
//        ui->playImageLabel->setPixmap(p);
//    }
    connect(ui->playButton,SIGNAL(clicked(bool)),this,SLOT(playButtonClicked()));

    ui->profileImageLabel->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileImageLabel->setLineWidth(3);
    ui->profileImageLabel->setMidLineWidth(3);
    //set the profile picture from picture that there is in the file
    // if the player doen't choose profile picture,Enter the following
    //two photos into the file

    //if(gender == male && doesn't have profile image)
    {
        QPixmap p(":/new/image/Portrait_02-prince.png");
        ui->profileImageLabel->setPixmap(p);
    }
   //else if(gender == female && doesn't have profile image)
    {
        QPixmap p(":/new/image/Portrait_05-girl.png");
        ui->profileImageLabel->setPixmap(p);
    }

    ui->nameLineEdit->setReadOnly(true);
    //if(gender == male)
    ui->nameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    //else if(gender == femal)
    ui->nameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    // read the player's name from file and set the text of nameLineEdit with player's name

    ui->editProfileButton->setIcon(QIcon(":/new/image/icons8-edit-80.png"));
    ui->editProfileButton->setStyleSheet("border:none");
    ui->editProfileButton->setIconSize(QSize(30,30));
    connect(ui->editProfileButton,SIGNAL(clicked(bool)),this,SLOT(editProfileButtonClicked()));

    // set the number of cups and number of coins from file


}

PersonalWindow::~PersonalWindow()
{
    delete ui;
}

void PersonalWindow::backButtonClicked()
{
    preWindow->showMaximized();
    this->close();
}

void PersonalWindow::storeButtonClicked()
{

}

void PersonalWindow::historyButtonClicked()
{
    historyWindow->showMaximized();
    this->close();
}

void PersonalWindow::playButtonClicked()
{
    serverOrClientWindow->showMaximized();
    this->close();
}

void PersonalWindow::editProfileButtonClicked()
{
    editProfileWindow->showMaximized();
    this->close();
}
