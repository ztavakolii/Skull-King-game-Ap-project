#include "register_login.h"
#include "ui_register_login.h"


register_login::register_login(QApplication*a,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::register_login)
{
    ui->setupUi(this);
    showMaximized();
    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Welcome");

    ui->background->showFullScreen();

    exitButton= ui->exitGameButton;
    registerAccountButton= ui->registerAccountButton;
    loginButton= ui->loginButton;

    loginWindow=new login(this);
    registerAccountWindow=new RegisterAccount;

    loginButton->setStyleSheet("border:none");
    registerAccountButton->setStyleSheet("border:none");
    exitButton->setStyleSheet("border:none");

    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(loginButton,SIGNAL(clicked(bool)),this,SLOT(showLoginWindow()));
    connect(registerAccountButton,SIGNAL(clicked(bool)),this,SLOT(showRegisterAccountWindow()));



}

register_login::~register_login()
{
    delete ui;
}

void register_login::showLoginWindow()
{
    loginWindow->showMaximized();
    this->close();
}

void register_login::showRegisterAccountWindow()
{
    registerAccountWindow->showMaximized();
    this->close();
}

