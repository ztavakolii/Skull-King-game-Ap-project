#include "playwindow.h"
#include "ui_playwindow.h"
#include "QTimer"
#include "QMessageBox"
#include "QDateTime"
#include "QFile"
#include "QTextStream"
#include "person.h"
#include "player.h"
#include "thread"

extern Person*User;
Player* player;
static int count=0;
int number_of_player=2;

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    QPixmap picture(":/new/image/icons8-pause-button-96.png");

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Play");
    ui->back_ground->showFullScreen();
    ui->stop_label->setPixmap(picture);
    ui->time_label->hide();
    ui->bottle->hide();
    ui->groupBox->hide();
    ui->ok_button->setEnabled(false);

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");
     ui->exchange_button->setStyleSheet("border:none");
     ui->ok_button->setStyleSheet("border:none");
    savedatetime();//save date time in file
    set_round_hand(1,1);


    User->set_coin(User->get_coin()-50);//take 50 coin
    User->edit();

//    ui->
//    player->

}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::savedatetime(){
    QDateTime currentDateTime=QDateTime::currentDateTime();
    QString dateTimeString=currentDateTime.toString("yyyy-MM-ddhh:mm:ss"),file_name,arr[20];
    file_name=User->get_user_name()+"_history";
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);//open the history file and read the information
    QDataStream in(&file);
    for(int i=0;i<10;i++)
        in>>arr[i];
    file.close();
    file.remove();
    file.open(QIODevice::WriteOnly);//create new history file and write the information in it
    QDataStream out(&file);
    for(int i=2;i<20;i++)
        out<<arr[i];
    out<<dateTimeString;
}

void PlayWindow::startcountdown(int n){
    remainingtime=n;//The remaining time for the countdown
    countdowntimer=new QTimer(this);//create a new QTimer object
    connect(countdowntimer,SIGNAL(timeout()),this,SLOT(f()));
    countdowntimer->start(1000);//start the timer with a timeout of 1 second
}

void PlayWindow::on_stop_button_clicked()
{
    QPixmap pixmap1(":/new/image/icons8-play-button-96.png");
    QPixmap labelpixmap=ui->stop_label->pixmap();
    QImage image1=pixmap1.toImage();
    QImage image=labelpixmap.toImage();
    if(image1!=image){//change the image
        count++;
        QPixmap p(":/new/image/icons8-play-button-96.png");
        ui->stop_label->setPixmap(p);
        startcountdown(20);

    }
    else{
    QPixmap p(":/new/image/icons8-pause-button-96.png");
    ui->stop_label->setPixmap(p);
    }
    if(count==2)
        ui->stop_button->setEnabled(false);
}

void PlayWindow::on_exit_button_clicked()
{
    QMessageBox message;
    message.setText("Are you sure you want to exit the game?");
    message.setIcon(QMessageBox::Warning);
    message.setWindowIcon(QIcon(":/new/image/gamename.png"));
    message.setStyleSheet("background-color: rgb(236,197,119)");
    message.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    message.exec();
    if(message.Yes){
        //back to the page personalwindow
        //server or client code
        this->close();
    }
    //    else
    }

void PlayWindow::f()
{
    if(remainingtime>=0){
        ui->time_label->show();//show number
        ui->time_label->setText(QString::number(remainingtime));
        remainingtime--;
    }
    else{
    //counttime is finish
        countdowntimer->stop();//stop the timer
        ui->time_label->hide();//hide number
        //        if(n==20){
        //        QPixmap p(":/new/image/icons8-pause-button-96.png");
        //        ui->stop_label->setPixmap(p);
        //        }
    }
}

void PlayWindow::set_round_hand(int round, int hand)
{
    QString r="Round "+QString::number(round)+"/7",h="hand "+QString::number(hand)+"/"+QString::number(round*2);
    ui->round_label->setText(r);
    ui->hand_label->setText(h);
}

void PlayWindow::handle_loop(int loop)//for stop loop of the game
{
    if(loop==1)//start the stop loop
        eventLoop.exec();
    else//stop the loop
        eventLoop.quit();
}

void PlayWindow::on_exchange_button_clicked()
{
    ui->groupBox->show();
    ui->ok_button->setEnabled(true);
    if(number_of_player==2){
        ui->player2->hide();
        ui->player3->hide();
        ui->checkBox2->hide();
        ui->checkBox3->hide();
    }
    else if(number_of_player==3){
        ui->player3->hide();
        ui->checkBox3->hide();
    }
}


void PlayWindow::on_ok_button_clicked()
{
    //send to server
    ui->groupBox->hide();
    ui->ok_button->setEnabled(false);
}

