#include "historywindow.h"
#include "ui_historywindow.h"
#include "QFile"
#include "QTextStream"
#include "person.h"

extern Person* User;

HistoryWindow::HistoryWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("History");
    ui->back_button->setStyleSheet("border:none");
    ui->pushButton->setStyleSheet("border:none");
    ui->pushButton_2->setStyleSheet("border:none");
    ui->pushButton_3->setStyleSheet("border:none");
    ui->pushButton_4->setStyleSheet("border:none");
    ui->pushButton_5->setStyleSheet("border:none");
    ui->pushButton_6->setStyleSheet("border:none");
    ui->pushButton_7->setStyleSheet("border:none");
    ui->pushButton_8->setStyleSheet("border:none");
    ui->pushButton_9->setStyleSheet("border:none");
    ui->pushButton_10->setStyleSheet("border:none");


    preWindow=prewindow;

    QString arr[10],x,condition[10];
    int c=0,c1=0;
    QString file_name=User->get_user_name()+"_history";
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);//open the history file and read the information
    QDataStream in(&file);
    for(int i=0;i<90;i++){
        in>>x;
        if(i==0||i==9||i==18||i==27||i==36||i==45||i==54||i==63||i==72||i==81){
            arr[c]=x;
            c++;
        }
        else if(i==1||i==10||i==19||i==28||i==37||i==45||i==55||i==64||i==73||i==82){
            condition[c1]=x;
            c1++;
        }
    }
    file.close();
    ui->date1->setText(arr[9]);
    ui->date2->setText(arr[8]);
    ui->date3->setText(arr[7]);
    ui->date4->setText(arr[6]);
    ui->date5->setText(arr[5]);
    ui->date6->setText(arr[4]);
    ui->date7->setText(arr[3]);
    ui->date8->setText(arr[2]);
    ui->date9->setText(arr[1]);
    ui->date10->setText(arr[0]);
    QPixmap picture(":/new/image/icons8-red-squar-96.png");
    if(condition[9]=="Lose"){
        ui->condition_label->setPixmap(picture);
        ui->condition->setText("Lose");
    }
    if(condition[8]=="Lose"){
        ui->condition_label_2->setPixmap(picture);
        ui->condition_2->setText("Lose");
    }
    if(condition[7]=="Lose"){
        ui->condition_label_3->setPixmap(picture);
        ui->condition_3->setText("Lose");
    }
    if(condition[6]=="Lose"){
        ui->condition_label_4->setPixmap(picture);
        ui->condition_4->setText("Lose");
    }
    if(condition[5]=="Lose"){
        ui->condition_label_5->setPixmap(picture);
        ui->condition_5->setText("Lose");
    }
    if(condition[4]=="Lose"){
        ui->condition_label_6->setPixmap(picture);
        ui->condition_6->setText("Lose");
    }
    if(condition[3]=="Lose"){
        ui->condition_label_7->setPixmap(picture);
        ui->condition_7->setText("Lose");
    }
    if(condition[2]=="Lose"){
        ui->condition_label_8->setPixmap(picture);
        ui->condition_8->setText("Lose");
    }
    if(condition[1]=="Lose"){
        ui->condition_label_9->setPixmap(picture);
        ui->condition_9->setText("Lose");
    }
    if(condition[0]=="Lose"){
        ui->condition_label_10->setPixmap(picture);
        ui->condition_10->setText("Lose");
    }

}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::on_back_button_clicked()
{
    preWindow->showMaximized();
    this->close();
}

