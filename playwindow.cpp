#include "playwindow.h"
#include "ui_playwindow.h"
#include "QTimer"
#include "QMessageBox"

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Play");

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");

}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::startcountdown(){
    int remainingtime=20;//The remaining time for the countdown
    countdowntimer=new QTimer(this);//create a new QTimer object
    connect(countdowntimer,&QTimer::timeout,[this,&remainingtime](){
        //this function is called every time the timer  times out
        if(remainingtime>0){
            ui->time_label->setText(QString::number(remainingtime));
            remainingtime--;
        }
        else{
            //counttime is finish
            countdowntimer->stop();//stop the timer
        }
    });
    countdowntimer->start(1000);//start the timer with a timeout of 1 second
}

void PlayWindow::on_stop_button_clicked()
{
    QPixmap pixmap1(":/new/image/icons8-play-button-96.png");
    QPixmap labelpixmap=ui->stop_label->pixmap();
    QImage image1=pixmap1.toImage();
    QImage image=labelpixmap.toImage();
    if(image1!=image){//change the image
        QPixmap p(":/new/image/icons8-play-button-96.png");
        ui->stop_label->setPixmap(p);
    }
    else{//change the image
        QPixmap p(":/new/image/icons8-pause-button-96.png");
        ui->stop_label->setPixmap(p);
    }
    startcountdown();//call the function to start countdown timer
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
    else
}

