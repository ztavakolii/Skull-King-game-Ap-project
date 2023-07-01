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
int number_of_player=4,count=0;

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
//    ui->bottle->hide();
    ui->groupBox->hide();
    ui->pic1->hide();
    ui->pic2->hide();
    ui->pic3->hide();
    ui->pic4->hide();
    ui->card1->hide();
    ui->card2->hide();
    ui->card3->hide();
    ui->card4->hide();
    ui->ok_button->setEnabled(false);

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");
     ui->exchange_button->setStyleSheet("border:none");
     ui->ok_button->setStyleSheet("border:none");
    savedatetime();//save date time in file
//    start_hand();
//    rotate();
    placeLabelsAroundCircle(200,1);//for images
    placeLabelsAroundCircle(200,2);//for cards

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
        if(remainingtime<=10)
        ui->time_lcd->setStyleSheet("color:red;");
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

//void PlayWindow::start_hand()
//{
//    if(number_of_player==2){

//    }
//    else if(number_of_player==3){
//        QLabel pic1,pic2,pic3;
//        QPixmap p1(":/new/image/4914363 - Copy (4).jpg"),p2(":/new/image/4914363 - Copy (4).jpg"),p3(":/new/image/4914363 - Copy (4).jpg");
//        pic1.setGeometry(600,70,141,121);
//        pic2.setGeometry(990,270,141,121);
//        pic3.setGeometry(170,270,141,121);
//        pic1.setPixmap(p1);
//        pic2.setPixmap(p2);
//        pic3.setPixmap(p3);
//        pic1.show();
//        pic2.show();
//        pic3.show();

//    }
//}

void PlayWindow::placeLabelsAroundCircle(int radius,int n)
{
    QPixmap p1(":/new/image/icons8-pause-button-96.png"),p2,p3,p4;
    float angle;
    if(number_of_player==2)
        angle=180.0;
    else if(number_of_player==3)
        angle=120.0;
    else if(number_of_player==4)
        angle=90.0;
    for(int i=0;i<number_of_player;i++){
        int x=radius*qCos(qDegreesToRadians(angle*i));
        int y=radius*qSin(qDegreesToRadians(angle*i));
        if(n==1){
            if(i==0){
                ui->pic1->move(x+630,y+250);
                ui->pic1->show();
                ui->pic1->setPixmap(p1);
            }
            else if(i==1){
                ui->pic2->move(x+630,y+250);
                ui->pic2->show();
                ui->pic2->setPixmap(p1);
            }
            else if(i==2){
                ui->pic3->move(x+630,y+250);
                ui->pic3->show();
                ui->pic3->setPixmap(p1);
            }
            else if(i==3){
                ui->pic4->move(x+630,y+250);
                ui->pic4->show();
                ui->pic4->setPixmap(p1);
            }
        }
        else if(n==2){
            if(i==0){
                ui->card1->move(x+650,y+215);
                ui->card1->show();
            }
            else if(i==1){
                ui->card2->move(x+650,y+215);
                ui->card2->show();
            }
            else if(i==2){
                ui->card3->move(x+650,y+215);
                ui->card3->show();
            }
            else if(i==3){
                ui->card4->move(x+650,y+215);
                ui->card4->show();
            }
        }
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

