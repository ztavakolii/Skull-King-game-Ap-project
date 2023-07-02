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
#include <vector>

using namespace std;

extern Person*User;
Player* player;
vector<player>players;
static int count=0;
int number_of_player=2;

PlayWindow::PlayWindow(QMainWindow*personalwindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    personalWindow=personalwindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Play");

    ui->back_ground->showFullScreen();

    QPixmap picture(":/new/image/icons8-pause-button-96.png");
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

     // round and hand labels in begining of play must be hide and when play starts, we must show them
    set_round_hand(1,1);

    User->set_coin(User->get_coin()-50);//take 50 coin
    User->edit();

    if(User->get_client()!=nullptr){
        t=new std::thread(&PlayWindow::readInformationSentByServer,this);
    }
    else t=nullptr;
}

PlayWindow::~PlayWindow()
{
    delete ui;
    if(t!=nullptr)
        t->join();
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
        QPixmap p(":/new/image/icons8-play-button-96.png"); //must be stop picture
     //   ui->stop_button->setToolTip("Resume");
        ui->stop_label->setPixmap(p);
        //activate buttons
    }
    else{
    QPixmap p(":/new/image/icons8-pause-button-96.png");
     //   ui->stop_button->setToolTip("Stop");
    ui->stop_label->setPixmap(p);
    startcountdown(20);
    count++;
    // inactivated buttons
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

void PlayWindow::readInformationSentByServer()
{
    QString clientName;

    char mainCode,subCode;

    // mainCode                     | Received Information
    //-----------------------------------------------------------------------------------------------
    // 'e' "exit"                   | 't' - The name of the player who want to exit
    //-----------------------------------------------------------------------------------------------
    // 's' "stop"                   | 't' - The name of player who want to stop play
    //-----------------------------------------------------------------------------------------------
    // 'r' "resume"                 | 's'
    //-----------------------------------------------------------------------------------------------
    // 'e' "exchange"               | 'c' "change" - plyer's name who requested to change the card
    //-----------------------------------------------------------------------------------------------
    // 'h' "hand"                   | number of hand
    //-----------------------------------------------------------------------------------------------
    // 'r' "round"                  | 'o' - number of round
    //-----------------------------------------------------------------------------------------------
    // 'r' "reply exchange"         | 'p' - player's name who accept the request of exchanging card
    //-----------------------------------------------------------------------------------------------
    // 'n' "number of players"      | number of players
    //-----------------------------------------------------------------------------------------------
    // 'l' "list of players"        | player name - player profile picture - player score for each player
    //-----------------------------------------------------------------------------------------------
    // 'c' "player's cards"         | codes of player's cards
    //-----------------------------------------------------------------------------------------------
    // 't' "next turn"              | the index of players vector that must choose a card
    //-----------------------------------------------------------------------------------------------
    // 'y' "you"                    | it tells the player that it is her/his turn to play a card
    //-----------------------------------------------------------------------------------------------
    // 's' "show card"              | 'w' - card code - the index of players vector that play this card
    //-----------------------------------------------------------------------------------------------
    // 'w' "winner"                 | 'h' "hand" - name or index of player that wins the hand
    //-----------------------------------------------------------------------------------------------
    // 'w' "winner"                 | 'w' "whole" - name or index of player that wins the play
    //-----------------------------------------------------------------------------------------------
    // 's' "score"                  | 'c' - the score of all players after each hand
    //-----------------------------------------------------------------------------------------------

    while(true){
        if(User->get_client()->getReceiveStatus()==true){
            QByteArray receivedInformation="";/*=User->get_client()->readInformation()*/
            emit User->get_client()->readSignal(&receivedInformation);
            while(receivedInformation=="");
            QDataStream in(&receivedInformation,QIODevice::ReadOnly);
            in>>mainCode;

            switch(mainCode){
            case 'e':
                in>>subCode;
                switch(subcode){
                case 't':
                    in>>clientName;
                    exitCodeReceived(clientName);
                    break;

                case 'c':

                    break;
                }
                break;

            case 's':
                in>>subCode;
                switch(subCode){
                case 't':

                    break;

                case 'w':

                    break;

                case 'c':

                    break;
                }
                break;

            case 'r':
                in>>subCode;
                switch(subCode){
                case 's':

                    break;

                case 'o':

                    break;

                case 'p':

                    break;
                }
                break;

            case 'h':

                break;

            case 'n':

                break;

            case 'l':

                break;

            case 'c':

                break;

            case 't':

                break;

            case 'y':

                break;

            case 'w':
                in>>subCode;
                switch(subCode){
                case 'h':

                    break;

                case 'w':

                    break;
                }
                break;
            }
        }
    }
}

void PlayWindow::exitCodeReceived(QString clientName)
{
    // write in guideTextEdit the client name ....
    // QTimer and LCD number (25 s)
    User->set_coin(User->get_coin()+(number_of_player*50)/(number_of_player-1));
    personalWindow->showMaximized();
    this->close();
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

