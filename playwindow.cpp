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
#include <QLabel>
#include <QPropertyAnimation>

extern Person*User;
Player* player;
int number_of_player=3,count=0;

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Play");

    ui->back_ground->showFullScreen();

    QPixmap picture(":/new/image/icons8-pause-button-96.png");
    ui->stop_label->setPixmap(picture);

    ui->time_lcd->hide();
    ui->bottle->hide();
    ui->groupBox->hide();
    ui->ok_button->setEnabled(false);

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");
     ui->exchange_button->setStyleSheet("border:none");
     ui->ok_button->setStyleSheet("border:none");
    savedatetime();//save date time in file
//    start_hand();
//    rotate();

     // round and hand labels in begining of play must be hide and when play starts, we must show them
    set_round_hand(1,1);

    User->set_coin(User->get_coin()-50);//take 50 coin
    User->edit();


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
        if(count!=2){
        QPixmap p(":/new/image/icons8-play-button-96.png"); //must be stop picture
        ui->stop_label->setPixmap(p);
        startcountdown(20);
        }
        count++;
    }
    else{
        countdowntimer->stop();//stop the timer
        ui->time_lcd->hide();//hide timer
        QPixmap p(":/new/image/icons8-pause-button-96.png");
        ui->stop_label->setPixmap(p);
    }
    if(count==3)
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
        ui->time_lcd->show();//show timer
        ui->time_lcd->display(QString::number(remainingtime));
        remainingtime--;
    }
    else{
    //counttime is finish
        countdowntimer->stop();//stop the timer
        ui->time_lcd->hide();//hide timer
        QPixmap p(":/new/image/icons8-pause-button-96.png");
        ui->stop_label->setPixmap(p);
    }
}

void PlayWindow::set_round_hand(int round, int hand)
{
    QString r="Round "+QString::number(round)+"/7",h="Hand "+QString::number(hand)+"/"+QString::number(round*2);
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

void PlayWindow::start_hand()
{
    if(number_of_player==2){

    }
    else if(number_of_player==3){
        QLabel pic1,pic2,pic3;
        QPixmap p1(":/new/image/4914363 - Copy (4).jpg"),p2(":/new/image/4914363 - Copy (4).jpg"),p3(":/new/image/4914363 - Copy (4).jpg");
        pic1.setGeometry(600,70,141,121);
        pic2.setGeometry(990,270,141,121);
        pic3.setGeometry(170,270,141,121);
        pic1.setPixmap(p1);
        pic2.setPixmap(p2);
        pic3.setPixmap(p3);
        pic1.show();
        pic2.show();
        pic3.show();

    }
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
    ui->checkBox1->setChecked(false);
    ui->checkBox2->setChecked(false);
    ui->checkBox3->setChecked(false);

}

//void PlayWindow::rotate()
//{
//    ui->bottle->show();
//    QPropertyAnimation* rotationAnimation=new QPropertyAnimation(ui->bottle,"rotation");
//    rotationAnimation->setDuration(5000);//time for rotation
//    rotationAnimation->setStartValue(0);//the start degree
//    rotationAnimation->setEndValue(120);//the end degree
//    rotationAnimation->start();
//    QObject::connect(rotationAnimation,&QPropertyAnimation::finished,rotationAnimation,&QPropertyAnimation::stop);
//    if(number_of_player==2){

//    }
//    else if(number_of_player==3){

//    }
//    else{

//    }
//}

