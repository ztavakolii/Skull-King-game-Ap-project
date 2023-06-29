#include "editprofilewindow.h"
#include "ui_editprofilewindow.h"

#include <QMessageBox>
#include <QFile>
#include "person.h"

extern Person* User;

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

    if(User->get_gender()=="Male"){
        ui->addressTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->countryPhoneCodesComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->genderComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->nameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->passwordLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->phoneNumberLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
        ui->usernameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    }
    else if(User->get_gender()== "Female"){
        ui->addressTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->countryPhoneCodesComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->genderComboBox->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->nameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->passwordLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->phoneNumberLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
        ui->usernameLineEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    }

    ui->background->showFullScreen();

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    ui->editProfileImageButton->setStyleSheet("border:none");
    ui->editProfileImageButton->setIcon(QIcon(":/new/image/icons8-brush-80.png"));
    ui->editProfileImageButton->setIconSize(QSize(30,30));
    //connect editProfileButton to a slot


    ui->addressTextEdit->setText(User->get_address());
    ui->nameLineEdit->setText(User->get_name());
    ui->passwordLineEdit->setText(User->get_password());
    ui->profileImageLabel->setPixmap(User->get_profile_picture());
    ui->usernameLineEdit->setText(User->get_user_name());

    QStringList countryPhoneCodes={"+98","+1","+86","+33","+49","+62","+81","+55","+61","+54","+39","+30","+34","+90","+852","+32","+964","+353","+52","+68"};
    ui->countryPhoneCodesComboBox->addItems(countryPhoneCodes);
    ui->phoneNumberLineEdit->setValidator(new QIntValidator(ui->phoneNumberLineEdit));
    ui->countryPhoneCodesComboBox->setCurrentText(User->get_phone_code());
    ui->phoneNumberLineEdit->setText(User->get_phone_number());


    QStringList genderList={"Male","Female"};
    ui->genderComboBox->addItems(genderList);
    ui->genderComboBox->setCurrentText(User->get_gender());


    ui->eyeButton->setStyleSheet("border:none");
    connect(ui->eyeButton,SIGNAL(clicked(bool)),this,SLOT(changePasswordLineEditMode()));

    ui->editButton->setStyleSheet("border:none");
    connect(ui->editButton,SIGNAL(clicked(bool)),this,SLOT(editButtonClicked()));

    ui->cancelButton->setStyleSheet("border:none");
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(cancelButtonClicked()));

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
    QMessageBox message;
    message.setText("By deleting your account, all your information and game history will be deleted. Are you sure about deleting your account?");
    message.setIcon(QMessageBox::Warning);
    message.setWindowIcon(QIcon(":/new/image/gamename.png"));
    message.setStyleSheet("background-color: rgb(236, 197, 119)");
    message.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    message.exec();
    if(message.Yes){
        // delete all files
        register_loginWindow->showMaximized();
        this->close();
    }
}

void EditProfileWindow::editButtonClicked()
{
    if(ui->addressTextEdit->toPlainText().length()>0
        && ui->countryPhoneCodesComboBox->currentText().length()>0
        && ui->genderComboBox->currentText().length()>0
        && ui->nameLineEdit->text().length()>0
        && ui->passwordLineEdit->text().length()>0
        && ui->phoneNumberLineEdit->text().length()>0
        && ui->usernameLineEdit->text().length()>0){

        QString fileName=ui->usernameLineEdit->text();
        if((!QFile::exists(fileName) && fileName!=User->get_user_name())
            || fileName==User->get_user_name()){
            if(ui->passwordLineEdit->text().length()>=8){ // Here is better that password security be checked with regex
                if(ui->phoneNumberLineEdit->text().length()>=10){ //this condition may be inappropriate
                    fileName=User->get_user_name();
                    QFile f(fileName);
                    f.remove();

                     User->set_address(ui->addressTextEdit->toPlainText());
                     User->set_gender(ui->genderComboBox->currentText());
                     User->set_name(ui->nameLineEdit->text());
                     User->set_password(ui->passwordLineEdit->text());
                     User->set_phone_code(ui->countryPhoneCodesComboBox->currentText());
                     User->set_phone_number(ui->phoneNumberLineEdit->text());
                     User->set_profile_picture(ui->profileImageLabel->pixmap());
                     User->set_user_name(ui->usernameLineEdit->text());

                     User->write_information_in_file();

                     QMessageBox message;
                     message.setText("Your personal information edited seccessfully.");
                     message.setIcon(QMessageBox::Information);
                     message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                     message.setStyleSheet("background-color: rgb(236, 197, 119)");
                     message.exec();
                }
                else{
                QMessageBox message;
                message.setText("The phonenumber should have 10 digits!");
                message.setIcon(QMessageBox::Critical);
                message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                message.setStyleSheet("background-color: rgb(236, 197, 119)");
                message.exec();
                }
            }
            else{
                QMessageBox message;
                message.setText("The password should have at least 8 characters!");
                message.setIcon(QMessageBox::Critical);
                message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                message.setStyleSheet("background-color: rgb(236, 197, 119)");
                message.exec();
            }

    }
        else{
            QMessageBox message;
            message.setText("The account with this username has already exists!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
    }
    }
    else {
        QMessageBox message;
        message.setText("The form is not completely filled!");
        message.setIcon(QMessageBox::Critical);
        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
        message.setStyleSheet("background-color: rgb(236, 197, 119)");
        message.exec();
    }

}

void EditProfileWindow::cancelButtonClicked()
{
    ui->addressTextEdit->setText(User->get_address());
    ui->countryPhoneCodesComboBox->setCurrentText(User->get_phone_code());
    ui->genderComboBox->setCurrentText(User->get_gender());
    ui->nameLineEdit->setText(User->get_name());
    ui->passwordLineEdit->setText(User->get_password());
    ui->usernameLineEdit->setText(User->get_user_name());
    ui->profileImageLabel->setPixmap(User->get_profile_picture());
    ui->phoneNumberLineEdit->setText(User->get_phone_number());
}
