#include "editprofilewindow.h"
#include "ui_editprofilewindow.h"

#include <QMessageBox>

EditProfileWindow::EditProfileWindow(QMainWindow*register_loginwindow,QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfileWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;
    register_loginWindow=register_loginwindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Edit profile");

    ui->background->showFullScreen();

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    ui->editProfileImageButton->setStyleSheet("border:none");
    ui->editProfileImageButton->setIcon(QIcon(":/new/image/icons8-brush-80.png"));
    ui->editProfileImageButton->setIconSize(QSize(30,30));
    //connect editProfileButton to a slot

    QStringList countryPhoneCodes={"+98","+1","+86","+33","+49","+62","+81","+55","+61","+54","+39","+30","+34","+90","+852","+32","+964","+353","+52","+68"};
    ui->countryPhoneCodesComboBox->addItems(countryPhoneCodes);
    ui->phoneNumberLineEdit->setValidator(new QIntValidator(ui->phoneNumberLineEdit));

    QStringList genderList={"Male","Female"};
    ui->genderComboBox->addItems(genderList);

    ui->eyeButton->setStyleSheet("border:none");
    connect(ui->eyeButton,SIGNAL(clicked(bool)),this,SLOT(changePasswordLineEditMode()));

    ui->editButton->setStyleSheet("border:none");
    // connect edit button to a slot

    ui->cancelButton->setStyleSheet("border:none");
    //connect cancel button to a slot

    ui->deleteAccountButton->setStyleSheet("border:none");
    connect(ui->deleteAccountButton,SIGNAL(clicked(bool)),this,SLOT(deleteAccountButtonClicked()));


}

EditProfileWindow::~EditProfileWindow()
{
    delete ui;
}

void EditProfileWindow::backButtonClicked()
{
    preWindow->showMaximized();
    this->close();
}

void EditProfileWindow::changePasswordLineEditMode()
{
    if(ui->passwordLineEdit->echoMode()==QLineEdit::Password){
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
        QPixmap p(":/new/image/icons8-eye-unchecked-50.png");
        ui->eyeLabel->setPixmap(p);
    }
    else if(ui->passwordLineEdit->echoMode()==QLineEdit::Normal){
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
        QPixmap p(":/new/image/icons8-eye-checked-50.png");
        ui->eyeLabel->setPixmap(p);
    }
}

void EditProfileWindow::deleteAccountButtonClicked()
{
    QMessageBox*message=new QMessageBox(this);
    message->warning(this,"Delete Account","By deleting your account, all your information and game history will be deleted. Are you sure about deleting your account?","Confirm","Cancel");

    //setStyleSheet doesn't work fix it
    // message->setStyleSheet("background-color:rgb(236, 197, 119)");
   //message->setPalette(QPalette(QColor(0,0,0),QColor(236, 197, 119)));

    //this connect doesn't work
    connect(message->defaultButton(),SIGNAL(clicked(bool)),this,SLOT(confirmDeleteAccountClicked()));

}

void EditProfileWindow::confirmDeleteAccountClicked()
{
    // delete all files of this player

    register_loginWindow->show();
    this->close();
}
