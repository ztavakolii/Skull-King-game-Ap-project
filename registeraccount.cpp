#include "registeraccount.h"
#include "register_login.h"
#include "ui_register_login.h"
#include "ui_registeraccount.h"
#include "person.h"
#include <windows.h>
#include "QMessageBox"
using namespace std;
RegisterAccount::RegisterAccount(QMainWindow *prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);

    this->prewindow=prewindow;
    //i must past the prewindow pointer to personal window constructor
    personalwindow=new PersonalWindow(prewindow);
    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Register Account");
    ui->back_ground->showFullScreen();
    ui->eye_p->setStyleSheet("border:none");
    QStringList countryPhoneCodes={"+98","+1","+86","+33","+49","+62","+81","+55","+61","+54","+39","+30","+34","+90","+852","+32","+964","+353","+52","+68"};
    ui->comboBox->addItems(countryPhoneCodes);
    ui->phone_l->setValidator(new QIntValidator(ui->phone_l));
    QStringList genderes={"Female","Male"};
    ui->comboBox_2->addItems(genderes);
}

RegisterAccount::~RegisterAccount()
{
    delete ui;
}

void RegisterAccount::on_eye_p_clicked()
{
    if(ui->password_l->echoMode()==QLineEdit::Password){
        ui->password_l->setEchoMode(QLineEdit::Normal);
        QPixmap p(":/new/image/icons8-eye-unchecked-50.png");
        ui->eye_label->setPixmap(p);
    }
    else if(ui->password_l->echoMode()==QLineEdit::Normal){
        ui->password_l->setEchoMode(QLineEdit::Password);
        QPixmap p(":/new/image/icons8-eye-checked-50.png");
        ui->eye_label->setPixmap(p);
    }
}


void RegisterAccount::on_back_button_clicked()
{
    prewindow->showMaximized();
    this->close();
}


void RegisterAccount::on_login_pushbutton_clicked()
{
    if(ui->name_l->text().length()>0&&ui->user_name_l->text().length()>0&&ui->comboBox_2->currentText().length()>0&&ui->password_l->text().length()>0&&ui->comboBox->currentText().length()>0&&ui->phone_l->text().length()){
        if(ui->password_l->text().length()<8)//invalid password
            QMessageBox::information(this,"Error","The password should have at least 8 characters!");
        else if(ui->phone_l->text().length()<10)
            QMessageBox::information(this,"Error","The phonenumber should have 10 characters!");
        else{
            Person user(ui->name_l->text(),ui->user_name_l->text(),ui->comboBox_2->currentText(),ui->password_l->text(),ui->comboBox->currentText(),ui->phone_l->text(),ui->address_t->toPlainText(),0,0);
            if(user.add()==0)//repetitious user_name
                QMessageBox::information(this,"Error","The account with this username has already exists!");

            else{//finish create_account process
                personalwindow->showMaximized();
                this->close();
            }
        }

    }

    else//uncomplete form
        QMessageBox::information(this,"Error","The form is not completely filled!");

}

