#include "playwindow.h"
#include "ui_playwindow.h"
#include "QTimer"
#include "QMessageBox"
#include "QDateTime"
#include "QFile"
#include "QTextStream"
#include "person.h"
#include "player.h"

extern Person*User;
Player* player;
static int count=0;

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

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");
    savedatetime();//save date time in file

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
        startcountdown(20);//call the function to start countdown timer
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

