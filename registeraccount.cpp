#include "registeraccount.h"
#include "register_login.h"
#include "ui_register_login.h"
#include "ui_registeraccount.h"
#include "person.h"
#include "QMessageBox"
#include <QFile>
#include <QTextStream>
#include <QSoundEffect>
#include <QCryptographicHash>

using namespace std;

extern Person*User;
extern QSoundEffect*clickSound;

RegisterAccount::RegisterAccount(QMainWindow *prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);
    setFixedSize(1280,700);

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
    QStringList genderes={"Male","Female"};
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
    clickSound->play();
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
    clickSound->play();
    prewindow->showMaximized();
    this->close();
}

void RegisterAccount::on_register_button_clicked(bool checked)
{
    clickSound->play();
    if(ui->name_l->text().length()>0&&ui->user_name_l->text().length()>0&&ui->comboBox_2->currentText().length()>0&&ui->password_l->text().length()>0&&ui->comboBox->currentText().length()>0&&ui->phone_l->text().length()){
        QRegularExpression passwordRegex("^(?=.*[a-zA-Z])(?=.*[0-9]).{6,}$");
        QString password=ui->password_l->text();
        QRegularExpressionMatch Match=passwordRegex.match(password);
        if(!Match.hasMatch())//invalid password
        {
            QMessageBox message;
            message.setText("The password must be at least 6 digits long and contain lowercase or uppercase letters and numbers.");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else if(ui->phone_l->text().length()<10){
        QMessageBox message;
        message.setText("The phonenumber should have 10 digits!");
        message.setIcon(QMessageBox::Critical);
        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
        message.setStyleSheet("background-color: rgb(236, 197, 119)");
        message.exec();
        }
        else{
            Person user(ui->name_l->text(),ui->user_name_l->text(),ui->comboBox_2->currentText(),ui->password_l->text(),ui->comboBox->currentText(),ui->phone_l->text(),ui->address_t->toPlainText(),0,1000);
            if(user.add(true)==0)//repetitious user_name
            {
                QMessageBox message;
                message.setText("The account with this username has already exists!");
                message.setIcon(QMessageBox::Critical);
                message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                message.setStyleSheet("background-color: rgb(236, 197, 119)");
                message.exec();
            }
            else{//finish create_account process

                User->set_user_name(user.get_user_name());
                User->read_information_from_file();

                QString f_name=User->get_user_name()+"_buy";//build a file for items that will buy in future
                QFile b(f_name);
                b.open(QIODevice::WriteOnly);
                QDataStream out1(&b);
                for(int i=0;i<18;i++)
                    out1<<0;
                b.close();

                QString file_name=User->get_user_name()+"_history";//build a file for history
                QFile h(file_name);
                h.open(QIODevice::WriteOnly);
                QDataStream out(&h);
                out<<0;
//                for(int i=0;i<20;i++)
//                    out<<"";
                h.close();

                personalwindow=new PersonalWindow(prewindow);
                personalwindow->showMaximized();
                this->close();
            }
        }

    }

    else//uncomplete form
    {
        QMessageBox message;
        message.setText("The form is not completely filled!");
        message.setIcon(QMessageBox::Critical);
        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
        message.setStyleSheet("background-color: rgb(236, 197, 119)");
        message.exec();
    }

}

