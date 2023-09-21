#include "historywindow.h"
#include "ui_historywindow.h"
#include "QFile"
#include "QTextStream"
#include "person.h"
#include <QSoundEffect>
#include <vector>

extern Person* User;
extern QSoundEffect*clickSound;
using namespace std;

HistoryWindow::HistoryWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,700);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("History");

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    ui->profileImageLabel->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileImageLabel->setLineWidth(3);
    ui->profileImageLabel->setMidLineWidth(3);
    QPixmap p=User->get_profile_picture();
    p=p.scaled(QSize(61,61));
    ui->profileImageLabel->setPixmap(p);

    ui->play1Button->setStyleSheet("border:none");
    ui->play2Button->setStyleSheet("border:none");
    ui->play3Button->setStyleSheet("border:none");
    ui->play4Button->setStyleSheet("border:none");
    ui->play5Button->setStyleSheet("border:none");
    ui->play6Button->setStyleSheet("border:none");
    ui->play7Button->setStyleSheet("border:none");
    ui->play8Button->setStyleSheet("border:none");
    ui->play9Button->setStyleSheet("border:none");
    ui->play10Button->setStyleSheet("border:none");

    ui->round1Button->setStyleSheet("border:none");
    ui->round2Button->setStyleSheet("border:none");
    ui->round3Button->setStyleSheet("border:none");
    ui->round4Button->setStyleSheet("border:none");
    ui->round5Button->setStyleSheet("border:none");
    ui->round6Button->setStyleSheet("border:none");
    ui->round7Button->setStyleSheet("border:none");

    preWindow=prewindow;

//    ui->groupBox_2->hide();
//    ui->groupBox_3->hide(); // hiding rounds and hands groupboxes


//    QString file_name=User->get_user_name()+"_history";
//    QFile file(file_name);
//    file.open(QIODevice::ReadOnly);//open the history file and read the information
//    QDataStream in(&file);

//    int numberOfPlays=0;
//    in>>numberOfPlays;
//    plays=new HistoryInformation[numberOfPlays];
//    for(int i=0;i<numberOfPlays;i++){
//        in>>plays[i];
//    }
//    file.close();

//    if(numberOfPlays<=9){
//        ui->play10Label->hide();
//        ui->play10Button->hide();
//        ui->label_12->hide();
//    }
//    if(numberOfPlays<=8){
//        ui->play9Label->hide();
//        ui->play9Button->hide();
//        ui->label_11->hide();
//    }
//    if(numberOfPlays<=7){
//        ui->play8Label->hide();
//        ui->play8Button->hide();
//        ui->label_10->hide();
//    }
//    if(numberOfPlays<=6){
//        ui->play7Label->hide();
//        ui->play7Button->hide();
//        ui->label_9->hide();
//    }
//    if(numberOfPlays<=5){
//        ui->play6Label->hide();
//        ui->play6Button->hide();
//        ui->label_8->hide();
//    }
//    if(numberOfPlays<=4){
//        ui->play5Label->hide();
//        ui->play5Button->hide();
//        ui->label_7->hide();
//    }
//    if(numberOfPlays<=3){
//        ui->play4Label->hide();
//        ui->play4Button->hide();
//        ui->label_6->hide();
//    }
//    if(numberOfPlays<=2){
//        ui->play3Label->hide();
//        ui->play3Button->hide();
//        ui->label_5->hide();
//    }
//    if(numberOfPlays<=1){
//        ui->play2Label->hide();
//        ui->play2Button->hide();
//        ui->label_4->hide();
//    }
//    if(numberOfPlays<=0){
//       ui->play1Label->setText("You have not played any games.");
//        ui->play1Button->setEnabled(false);
//    }

//    for(int i=0;i<numberOfPlays;i++){
//       if(i==0){
//           ui->play1Label->setText(plays[i].getDate());
//           if(plays[i].getIsWinThePlay()==true)
//               ui->status_1->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//           else ui->status_1->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==1){
//               ui->play2Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_2->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_2->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==2){
//               ui->play3Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_3->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_3->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==3){
//               ui->play4Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_4->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_4->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==4){
//               ui->play5Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_5->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_5->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==5){
//               ui->play6Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_6->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_6->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==6){
//               ui->play7Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_7->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_7->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==7){
//               ui->play8Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_8->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_8->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==8){
//               ui->play9Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_9->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_9->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//       else if(i==9){
//               ui->play10Label->setText(plays[i].getDate());
//               if(plays[i].getIsWinThePlay()==true)
//                   ui->status_10->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
//               else ui->status_10->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
//       }
//    }


//********************************************************************************************************************




   // QString arr[10],x,condition[10];
 //   int c=0,c1=0;
//    QString file_name=User->get_user_name()+"_history";
//    QFile file(file_name);
//    file.open(QIODevice::ReadOnly);//open the history file and read the information
//    QDataStream in(&file);
//    for(int i=0;i<90;i++){
//        in>>x;
//        if(i==0||i==9||i==18||i==27||i==36||i==45||i==54||i==63||i==72||i==81){
//            arr[c]=x;
//            c++;
//        }
//        else if(i==1||i==10||i==19||i==28||i==37||i==45||i==55||i==64||i==73||i==82){
//            condition[c1]=x;
//            c1++;
//        }
//    }
//    file.close();
//    ui->date1->setText(arr[9]);
//    ui->date2->setText(arr[8]);
//    ui->date3->setText(arr[7]);
//    ui->date4->setText(arr[6]);
//    ui->date5->setText(arr[5]);
//    ui->date6->setText(arr[4]);
//    ui->date7->setText(arr[3]);
//    ui->date8->setText(arr[2]);
//    ui->date9->setText(arr[1]);
//    ui->date10->setText(arr[0]);
//    QPixmap picture(":/new/image/icons8-red-square-96.png"),picture2(":/new/image/icons8-green-square-96.png");
//    ui->label->setText(condition[9]);
//    if(condition[9]=="Lose"){
//        ui->condition_label->setPixmap(picture);
//        ui->condition->setText("Lose");
//        ui->pushButton->setEnabled(true);
//    }
//    else if(condition[9]=="Win"){
//        ui->condition_label->setPixmap(picture2);
//        ui->condition->setText("Win");
//        ui->pushButton->setEnabled(true);
//    }

//    if(condition[8]=="Lose"){
//        ui->condition_label_2->setPixmap(picture);
//        ui->condition_2->setText("Lose");
//        ui->pushButton_2->setEnabled(true);
//    }
//    else if(condition[8]=="Win"){
//        ui->condition_label_2->setPixmap(picture2);
//        ui->condition_2->setText("Win");
//        ui->pushButton_2->setEnabled(true);
//    }

//    if(condition[7]=="Lose"){
//        ui->condition_label_3->setPixmap(picture);
//        ui->condition_3->setText("Lose");
//        ui->pushButton_3->setEnabled(true);
//    }
//    else if(condition[7]=="Win"){
//        ui->condition_label_3->setPixmap(picture2);
//        ui->condition_3->setText("Win");
//        ui->pushButton_3->setEnabled(true);
//    }

//    if(condition[6]=="Lose"){
//        ui->condition_label_4->setPixmap(picture);
//        ui->condition_4->setText("Lose");
//        ui->pushButton_4->setEnabled(true);
//    }
//    else if(condition[6]=="Win"){
//        ui->condition_label_4->setPixmap(picture2);
//        ui->condition_4->setText("Win");
//        ui->pushButton_4->setEnabled(true);
//    }
//    if(condition[5]=="Lose"){
//        ui->condition_label_5->setPixmap(picture);
//        ui->condition_5->setText("Lose");
//        ui->pushButton_5->setEnabled(true);
//    }
//    else if(condition[5]=="Win"){
//        ui->condition_label_5->setPixmap(picture2);
//        ui->condition_5->setText("Win");
//        ui->pushButton_5->setEnabled(true);
//    }

//    if(condition[4]=="Lose"){
//        ui->condition_label_6->setPixmap(picture);
//        ui->condition_6->setText("Lose");
//        ui->pushButton_6->setEnabled(true);
//    }
//    else if(condition[4]=="Win"){
//        ui->condition_label_6->setPixmap(picture2);
//        ui->condition_6->setText("Win");
//        ui->pushButton_6->setEnabled(true);
//    }

//    if(condition[3]=="Lose"){
//        ui->condition_label_7->setPixmap(picture);
//        ui->condition_7->setText("Lose");
//        ui->pushButton_7->setEnabled(true);
//    }
//    else if(condition[3]=="Win"){
//        ui->condition_label_7->setPixmap(picture2);
//        ui->condition_7->setText("Win");
//        ui->pushButton_7->setEnabled(true);
//    }

//    if(condition[2]=="Lose"){
//        ui->condition_label_8->setPixmap(picture);
//        ui->condition_8->setText("Lose");
//        ui->pushButton_8->setEnabled(true);
//    }
//    else if(condition[2]=="Win"){
//        ui->condition_label_8->setPixmap(picture2);
//        ui->condition_8->setText("Win");
//        ui->pushButton_8->setEnabled(true);
//    }

//    if(condition[1]=="Lose"){
//        ui->condition_label_9->setPixmap(picture);
//        ui->condition_9->setText("Lose");
//        ui->pushButton_9->setEnabled(true);
//    }
//    else if(condition[1]=="Win"){
//        ui->condition_label_9->setPixmap(picture2);
//        ui->condition_9->setText("Win");
//        ui->pushButton_9->setEnabled(true);
//    }

//    if(condition[0]=="Lose"){
//        ui->condition_label_10->setPixmap(picture);
//        ui->condition_10->setText("Lose");
//        ui->pushButton_10->setEnabled(true);
//    }
//    else if(condition[0]=="Win"){
//        ui->condition_label_10->setPixmap(picture2);
//        ui->condition_10->setText("Win");
//        ui->pushButton_10->setEnabled(true);
//    }

}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}


void HistoryWindow::backButtonClicked()
{
    clickSound->play();
    preWindow->showMaximized();
    this->close();
}

void HistoryWindow::on_play1Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=0;
}


void HistoryWindow::on_play2Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=1;
}


void HistoryWindow::on_play3Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=2;
}


void HistoryWindow::on_play4Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=3;
}


void HistoryWindow::on_play5Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=4;
}


void HistoryWindow::on_play6Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=5;
}


void HistoryWindow::on_play7Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=6;
}


void HistoryWindow::on_play8Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=7;
}


void HistoryWindow::on_play9Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=8;
}


void HistoryWindow::on_play10Button_clicked()
{
    clickSound->play();
    ui->groupBox_2->show();
    indexOfSelectedPlay=9;
}


void HistoryWindow::on_round1Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand3->hide();
    ui->hand4->hide();
    ui->hand5->hide();
    ui->hand6->hide();
    ui->hand7->hide();
    ui->hand8->hide();
    ui->hand9->hide();
    ui->hand10->hide();
    ui->hand11->hide();
    ui->hand12->hide();
    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound1();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));
}


void HistoryWindow::on_round2Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand5->hide();
    ui->hand6->hide();
    ui->hand7->hide();
    ui->hand8->hide();
    ui->hand9->hide();
    ui->hand10->hide();
    ui->hand11->hide();
    ui->hand12->hide();
    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound2();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));
}


void HistoryWindow::on_round3Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand7->hide();
    ui->hand8->hide();
    ui->hand9->hide();
    ui->hand10->hide();
    ui->hand11->hide();
    ui->hand12->hide();
    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound3();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));

    if(hands[4].isWinTheHand==true)
       ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard5->setPixmap(QPixmap(":/new/image/"+hands[4].yourCard+".jpg"));
    ui->winingCard5->setPixmap(QPixmap(":/new/image/"+hands[4].winnerCard+".jpg"));

    if(hands[5].isWinTheHand==true)
       ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard6->setPixmap(QPixmap(":/new/image/"+hands[5].yourCard+".jpg"));
    ui->winingCard6->setPixmap(QPixmap(":/new/image/"+hands[5].winnerCard+".jpg"));
}


void HistoryWindow::on_round4Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand9->hide();
    ui->hand10->hide();
    ui->hand11->hide();
    ui->hand12->hide();
    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound4();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));

    if(hands[4].isWinTheHand==true)
       ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard5->setPixmap(QPixmap(":/new/image/"+hands[4].yourCard+".jpg"));
    ui->winingCard5->setPixmap(QPixmap(":/new/image/"+hands[4].winnerCard+".jpg"));

    if(hands[5].isWinTheHand==true)
       ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard6->setPixmap(QPixmap(":/new/image/"+hands[5].yourCard+".jpg"));
    ui->winingCard6->setPixmap(QPixmap(":/new/image/"+hands[5].winnerCard+".jpg"));

    if(hands[6].isWinTheHand==true)
       ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard7->setPixmap(QPixmap(":/new/image/"+hands[6].yourCard+".jpg"));
    ui->winingCard7->setPixmap(QPixmap(":/new/image/"+hands[6].winnerCard+".jpg"));

    if(hands[7].isWinTheHand==true)
       ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard8->setPixmap(QPixmap(":/new/image/"+hands[7].yourCard+".jpg"));
    ui->winingCard8->setPixmap(QPixmap(":/new/image/"+hands[7].winnerCard+".jpg"));
}


void HistoryWindow::on_round5Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand11->hide();
    ui->hand12->hide();
    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound5();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));

    if(hands[4].isWinTheHand==true)
       ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard5->setPixmap(QPixmap(":/new/image/"+hands[4].yourCard+".jpg"));
    ui->winingCard5->setPixmap(QPixmap(":/new/image/"+hands[4].winnerCard+".jpg"));

    if(hands[5].isWinTheHand==true)
       ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard6->setPixmap(QPixmap(":/new/image/"+hands[5].yourCard+".jpg"));
    ui->winingCard6->setPixmap(QPixmap(":/new/image/"+hands[5].winnerCard+".jpg"));

    if(hands[6].isWinTheHand==true)
       ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard7->setPixmap(QPixmap(":/new/image/"+hands[6].yourCard+".jpg"));
    ui->winingCard7->setPixmap(QPixmap(":/new/image/"+hands[6].winnerCard+".jpg"));

    if(hands[7].isWinTheHand==true)
       ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard8->setPixmap(QPixmap(":/new/image/"+hands[7].yourCard+".jpg"));
    ui->winingCard8->setPixmap(QPixmap(":/new/image/"+hands[7].winnerCard+".jpg"));

    if(hands[8].isWinTheHand==true)
       ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard9->setPixmap(QPixmap(":/new/image/"+hands[8].yourCard+".jpg"));
    ui->winingCard9->setPixmap(QPixmap(":/new/image/"+hands[8].winnerCard+".jpg"));

    if(hands[9].isWinTheHand==true)
       ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard10->setPixmap(QPixmap(":/new/image/"+hands[9].yourCard+".jpg"));
    ui->winingCard10->setPixmap(QPixmap(":/new/image/"+hands[9].winnerCard+".jpg"));
}


void HistoryWindow::on_round6Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    ui->hand13->hide();
    ui->hand14->hide();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound6();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));

    if(hands[4].isWinTheHand==true)
       ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard5->setPixmap(QPixmap(":/new/image/"+hands[4].yourCard+".jpg"));
    ui->winingCard5->setPixmap(QPixmap(":/new/image/"+hands[4].winnerCard+".jpg"));

    if(hands[5].isWinTheHand==true)
       ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard6->setPixmap(QPixmap(":/new/image/"+hands[5].yourCard+".jpg"));
    ui->winingCard6->setPixmap(QPixmap(":/new/image/"+hands[5].winnerCard+".jpg"));

    if(hands[6].isWinTheHand==true)
       ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard7->setPixmap(QPixmap(":/new/image/"+hands[6].yourCard+".jpg"));
    ui->winingCard7->setPixmap(QPixmap(":/new/image/"+hands[6].winnerCard+".jpg"));

    if(hands[7].isWinTheHand==true)
       ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard8->setPixmap(QPixmap(":/new/image/"+hands[7].yourCard+".jpg"));
    ui->winingCard8->setPixmap(QPixmap(":/new/image/"+hands[7].winnerCard+".jpg"));

    if(hands[8].isWinTheHand==true)
       ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard9->setPixmap(QPixmap(":/new/image/"+hands[8].yourCard+".jpg"));
    ui->winingCard9->setPixmap(QPixmap(":/new/image/"+hands[8].winnerCard+".jpg"));

    if(hands[9].isWinTheHand==true)
       ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard10->setPixmap(QPixmap(":/new/image/"+hands[9].yourCard+".jpg"));
    ui->winingCard10->setPixmap(QPixmap(":/new/image/"+hands[9].winnerCard+".jpg"));

    if(hands[10].isWinTheHand==true)
       ui->mark11Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark11Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard11->setPixmap(QPixmap(":/new/image/"+hands[10].yourCard+".jpg"));
    ui->winingCard11->setPixmap(QPixmap(":/new/image/"+hands[10].winnerCard+".jpg"));

    if(hands[11].isWinTheHand==true)
       ui->mark12Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark12Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard12->setPixmap(QPixmap(":/new/image/"+hands[11].yourCard+".jpg"));
    ui->winingCard12->setPixmap(QPixmap(":/new/image/"+hands[11].winnerCard+".jpg"));
}


void HistoryWindow::on_round7Button_clicked()
{
    clickSound->play();

    ui->groupBox_3->show();

    vector<Hand>hands=plays[indexOfSelectedPlay].getRound7();

    if(hands[0].isWinTheHand==true)
       ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark1Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard1->setPixmap(QPixmap(":/new/image/"+hands[0].yourCard+".jpg"));
    ui->winingCard1->setPixmap(QPixmap(":/new/image/"+hands[0].winnerCard+".jpg"));

    if(hands[1].isWinTheHand==true)
       ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark2Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard2->setPixmap(QPixmap(":/new/image/"+hands[1].yourCard+".jpg"));
    ui->winingCard2->setPixmap(QPixmap(":/new/image/"+hands[1].winnerCard+".jpg"));

    if(hands[2].isWinTheHand==true)
       ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark3Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard3->setPixmap(QPixmap(":/new/image/"+hands[2].yourCard+".jpg"));
    ui->winingCard3->setPixmap(QPixmap(":/new/image/"+hands[2].winnerCard+".jpg"));

    if(hands[3].isWinTheHand==true)
       ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark4Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard4->setPixmap(QPixmap(":/new/image/"+hands[3].yourCard+".jpg"));
    ui->winingCard4->setPixmap(QPixmap(":/new/image/"+hands[3].winnerCard+".jpg"));

    if(hands[4].isWinTheHand==true)
       ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark5Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard5->setPixmap(QPixmap(":/new/image/"+hands[4].yourCard+".jpg"));
    ui->winingCard5->setPixmap(QPixmap(":/new/image/"+hands[4].winnerCard+".jpg"));

    if(hands[5].isWinTheHand==true)
       ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark6Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard6->setPixmap(QPixmap(":/new/image/"+hands[5].yourCard+".jpg"));
    ui->winingCard6->setPixmap(QPixmap(":/new/image/"+hands[5].winnerCard+".jpg"));

    if(hands[6].isWinTheHand==true)
       ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark7Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard7->setPixmap(QPixmap(":/new/image/"+hands[6].yourCard+".jpg"));
    ui->winingCard7->setPixmap(QPixmap(":/new/image/"+hands[6].winnerCard+".jpg"));

    if(hands[7].isWinTheHand==true)
       ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark8Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard8->setPixmap(QPixmap(":/new/image/"+hands[7].yourCard+".jpg"));
    ui->winingCard8->setPixmap(QPixmap(":/new/image/"+hands[7].winnerCard+".jpg"));

    if(hands[8].isWinTheHand==true)
       ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark9Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard9->setPixmap(QPixmap(":/new/image/"+hands[8].yourCard+".jpg"));
    ui->winingCard9->setPixmap(QPixmap(":/new/image/"+hands[8].winnerCard+".jpg"));

    if(hands[9].isWinTheHand==true)
       ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark10Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard10->setPixmap(QPixmap(":/new/image/"+hands[9].yourCard+".jpg"));
    ui->winingCard10->setPixmap(QPixmap(":/new/image/"+hands[9].winnerCard+".jpg"));

    if(hands[10].isWinTheHand==true)
       ui->mark11Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark11Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard11->setPixmap(QPixmap(":/new/image/"+hands[10].yourCard+".jpg"));
    ui->winingCard11->setPixmap(QPixmap(":/new/image/"+hands[10].winnerCard+".jpg"));

    if(hands[11].isWinTheHand==true)
       ui->mark12Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark12Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard12->setPixmap(QPixmap(":/new/image/"+hands[11].yourCard+".jpg"));
    ui->winingCard12->setPixmap(QPixmap(":/new/image/"+hands[11].winnerCard+".jpg"));

    if(hands[12].isWinTheHand==true)
       ui->mark13Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark13Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard13->setPixmap(QPixmap(":/new/image/"+hands[12].yourCard+".jpg"));
    ui->winingCard13->setPixmap(QPixmap(":/new/image/"+hands[12].winnerCard+".jpg"));

    if(hands[13].isWinTheHand==true)
       ui->mark14Label->setPixmap(QPixmap(":/new/image/icons8-medal2-100.png"));
    else ui->mark14Label->setPixmap(QPixmap(":/new/image/icons8-unlike-100.png"));
    ui->yourCard14->setPixmap(QPixmap(":/new/image/"+hands[13].yourCard+".jpg"));
    ui->winingCard14->setPixmap(QPixmap(":/new/image/"+hands[13].winnerCard+".jpg"));
}

void HistoryWindow::showEvent(QShowEvent *event)
{
    ui->groupBox_2->hide();
    ui->groupBox_3->hide(); // hiding rounds and hands groupboxes


    QString file_name=User->get_user_name()+"_history";
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);//open the history file and read the information
    QDataStream in(&file);

    int numberOfPlays=0;
    in>>numberOfPlays;
    plays=new HistoryInformation[numberOfPlays];
    for(int i=0;i<numberOfPlays;i++){
       in>>plays[i];
    }
    file.close();

    if(numberOfPlays<=9){
       ui->play10Label->hide();
       ui->play10Button->hide();
       ui->label_12->hide();
    }
    if(numberOfPlays<=8){
       ui->play9Label->hide();
       ui->play9Button->hide();
       ui->label_11->hide();
    }
    if(numberOfPlays<=7){
       ui->play8Label->hide();
       ui->play8Button->hide();
       ui->label_10->hide();
    }
    if(numberOfPlays<=6){
       ui->play7Label->hide();
       ui->play7Button->hide();
       ui->label_9->hide();
    }
    if(numberOfPlays<=5){
       ui->play6Label->hide();
       ui->play6Button->hide();
       ui->label_8->hide();
    }
    if(numberOfPlays<=4){
       ui->play5Label->hide();
       ui->play5Button->hide();
       ui->label_7->hide();
    }
    if(numberOfPlays<=3){
       ui->play4Label->hide();
       ui->play4Button->hide();
       ui->label_6->hide();
    }
    if(numberOfPlays<=2){
       ui->play3Label->hide();
       ui->play3Button->hide();
       ui->label_5->hide();
    }
    if(numberOfPlays<=1){
       ui->play2Label->hide();
       ui->play2Button->hide();
       ui->label_4->hide();
    }
    if(numberOfPlays<=0){
       ui->play1Label->setText("You have not played any games.");
       ui->play1Button->setEnabled(false);
    }

    for(int i=0;i<numberOfPlays;i++){
       if(i==0){
               ui->play1Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_1->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_1->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==1){
               ui->play2Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_2->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_2->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==2){
               ui->play3Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_3->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_3->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==3){
               ui->play4Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_4->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_4->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==4){
               ui->play5Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_5->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_5->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==5){
               ui->play6Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_6->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_6->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==6){
               ui->play7Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_7->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_7->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==7){
               ui->play8Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_8->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_8->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==8){
               ui->play9Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_9->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_9->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
       else if(i==9){
               ui->play10Label->setText(plays[i].getDate());
               if(plays[i].getIsWinThePlay()==true)
                   ui->status_10->setPixmap(QPixmap(":/new/image/icons8-win-100.png"));
               else ui->status_10->setPixmap(QPixmap(":/new/image/icons8-failure-64.png"));
       }
    }

    QMainWindow::showEvent(event);
}

