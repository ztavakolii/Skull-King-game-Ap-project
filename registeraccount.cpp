#include "registeraccount.h"
#include "register_login.h"
#include "ui_register_login.h"
#include "ui_registeraccount.h"
#include "person.h"
#include <windows.h>
#include "QMessageBox"
using namespace std;

Person User("","","","","","","",0,0);

RegisterAccount::RegisterAccount(QMainWindow *prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);

    this->prewindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Register Account");

    ui->back_ground->showFullScreen();

    ui->back_button->setStyleSheet("border:none");
    ui->back_button->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->back_button->setIconSize(QSize(40,40));

    ui->eye_p->setStyleSheet("border:none");
    QStringList countryPhoneCodes={"+98","+1","+86","+33","+49","+62","+81","+55","+61","+54","+39","+30","+34","+90","+852","+32","+964","+353","+52","+68"};
    ui->comboBox->addItems(countryPhoneCodes);
    ui->phone_l->setValidator(new QIntValidator(ui->phone_l));
    QStringList genderes={"Female","Male"};
    ui->comboBox_2->addItems(genderes);

    ui->guideTextEdit->setReadOnly(true);
    ui->guideTextEdit->setText("Hello my friend, welcome to our army. Register that we need a good commander in wars.\n\nSkull King");

    ui->register_button->setStyleSheet("border:none");
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

void RegisterAccount::on_register_button_clicked(bool checked)
{
    if(ui->name_l->text().length()>0&&ui->user_name_l->text().length()>0&&ui->comboBox_2->currentText().length()>0&&ui->password_l->text().length()>0&&ui->comboBox->currentText().length()>0&&ui->phone_l->text().length()){
        if(ui->password_l->text().length()<8)//invalid password
            QMessageBox::critical(this,"Error","The password should have at least 8 characters!");
        else if(ui->phone_l->text().length()<10)
            QMessageBox::critical(this,"Error","The phone_number should have 10 digits!");
        else{
            Person user(ui->name_l->text(),ui->user_name_l->text(),ui->comboBox_2->currentText(),ui->password_l->text(),ui->comboBox->currentText(),ui->phone_l->text(),ui->address_t->toPlainText(),0,0);
            if(user.add()==0)//repetitious user_name
                QMessageBox::critical(this,"Error","The account with this username has already exists!");

            else{//finish create_account process

                User.set_user_name(user.get_user_name());
                User.read_information_from_file();
                personalwindow=new PersonalWindow(prewindow);
                personalwindow->showMaximized();
                this->close();
            }
        }

    }

    else//uncomplete form
        QMessageBox::critical(this,"Error","The form is not completely filled!");

}

