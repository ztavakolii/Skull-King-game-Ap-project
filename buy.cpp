#include "buy.h"
#include "ui_buy.h"
#include "QMessageBox"
#include "person.h"
#include <QSoundEffect>
#include <QFile>
#include <QTextStream>

extern Person *User;
extern QSoundEffect*clickSound;

int arr[25];

buy::buy(QMainWindow *previousWindow,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy)
{
    ui->setupUi(this);
    setFixedSize(1280,700);

    prewindow=previousWindow;
    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Store");

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));


    QString file_name=User->get_user_name()+"_buy";
    QFile f(file_name);
    if(f.open(QIODevice::ReadOnly)){
        QDataStream in(&f);
        QString str;
        for(int i=0;i<25;i++){
            in>>str;
            arr[i]=str.toInt();
        }
        f.close();
    }

//    if(arr[0]){//item1
//        ui->lock->hide();
//        ui->buy_2->setEnabled(false);
//    }
//    else
//        ui->buy_2->setEnabled(true);

//    if(arr[1]){//item2
//        ui->lock_2->hide();
//        ui->buy_1->setEnabled(false);
//    }
//    else
//        ui->buy_1->setEnabled(true);

//    if(arr[2]){//item3
//        ui->lock_3->hide();
//        ui->pushButton->setEnabled(false);
//    }
//    else
//        ui->pushButton->setEnabled(true);

//    if(arr[3]){//item4
//        ui->lock_4->hide();
//        ui->pushButton_2->setEnabled(false);
//    }
//    else
//        ui->pushButton_2->setEnabled(true);

//    if(arr[4]){//item5
//        ui->lock_5->hide();
//        ui->pushButton_3->setEnabled(false);
//    }
//    else
//        ui->pushButton_3->setEnabled(true);

//    if(arr[5]){//item6
//        ui->lock_6->hide();
//        ui->pushButton_4->setEnabled(false);
//    }
//    else
//        ui->pushButton_4->setEnabled(true);

//    if(arr[6]){//item7
//        ui->lock_7->hide();
//        ui->pushButton_5->setEnabled(false);
//    }
//    else
//        ui->pushButton_5->setEnabled(true);

//    if(arr[7]){//item8
//        ui->lock_8->hide();
//        ui->pushButton_6->setEnabled(false);
//    }
//    else
//        ui->pushButton_6->setEnabled(true);

//    if(arr[8]){//item9
//        ui->lock_9->hide();
//        ui->pushButton_7->setEnabled(false);
//    }
//    else
//        ui->pushButton_7->setEnabled(true);

//    if(arr[9]){//item10
//        ui->lock_10->hide();
//        ui->pushButton_8->setEnabled(false);
//    }
//    else
//        ui->pushButton_8->setEnabled(true);

//    if(arr[10]){//item11
//        ui->lock_11->hide();
//        ui->pushButton_9->setEnabled(false);
//    }
//    else
//        ui->pushButton_9->setEnabled(true);

//    if(arr[11]){//item12
//        ui->lock_12->hide();
//        ui->pushButton_10->setEnabled(false);
//    }
//    else
//        ui->pushButton_10->setEnabled(true);

//    if(arr[12]){//item13
//        ui->lock_13->hide();
//        ui->pushButton_11->setEnabled(false);
//    }
//    else
//        ui->pushButton_11->setEnabled(true);

//    if(arr[13]){//item14
//        ui->lock_14->hide();
//        ui->pushButton_12->setEnabled(false);
//    }
//    else
//        ui->pushButton_12->setEnabled(true);

//    if(arr[14]){//item15
//        ui->lock_15->hide();
//        ui->pushButton_13->setEnabled(false);
//    }
//    else
//        ui->pushButton_13->setEnabled(true);

//    if(arr[15]){//item16
//        ui->lock_16->hide();
//        ui->pushButton_14->setEnabled(false);
//    }
//    else
//        ui->pushButton_14->setEnabled(true);

//    if(arr[16]){//item17
//        ui->lock_17->hide();
//        ui->pushButton_15->setEnabled(false);
//    }
//    else
//        ui->pushButton_15->setEnabled(true);

//    if(arr[17]){//item18
//        ui->lock_18->hide();
//        ui->pushButton_16->setEnabled(false);
//    }
//    else
//        ui->pushButton_16->setEnabled(true);

//    if(arr[18]){//item19
//        ui->lock_19->hide();
//        ui->pushButton_17->setEnabled(false);
//    }
//    else
//        ui->pushButton_17->setEnabled(true);

//    if(arr[19]){//item20
//        ui->lock_20->hide();
//        ui->pushButton_18->setEnabled(false);
//    }
//    else
//        ui->pushButton_18->setEnabled(true);

//    if(arr[20]){//item21
//        ui->lock_21->hide();
//        ui->pushButton_19->setEnabled(false);
//    }
//    else
//        ui->pushButton_19->setEnabled(true);

//    if(arr[21]){//item22
//        ui->lock_22->hide();
//        ui->pushButton_20->setEnabled(false);
//    }
//    else
//        ui->pushButton_20->setEnabled(true);

//    if(arr[22]){//item23
//        ui->lock_23->hide();
//        ui->pushButton_21->setEnabled(false);
//    }
//    else
//        ui->pushButton_21->setEnabled(true);

//    if(arr[23]){//item24
//        ui->lock_24->hide();
//        ui->pushButton_22->setEnabled(false);
//    }
//    else
//        ui->pushButton_22->setEnabled(true);

//    if(arr[24]){//item25
//        ui->lock_25->hide();
//        ui->pushButton_23->setEnabled(false);
//    }
//    else
//        ui->pushButton_23->setEnabled(true);



    ui->article_1->setStyleSheet("border:none");
    ui->article_2->setStyleSheet("border:none");
    ui->article_3->setStyleSheet("border:none");
    ui->article_4->setStyleSheet("border:none");
    ui->article_5->setStyleSheet("border:none");
    ui->article_6->setStyleSheet("border:none");
    ui->article_7->setStyleSheet("border:none");
    ui->article_8->setStyleSheet("border:none");
    ui->article_9->setStyleSheet("border:none");
    ui->article_10->setStyleSheet("border:none");
    ui->article_11->setStyleSheet("border:none");
    ui->article_12->setStyleSheet("border:none");
    ui->article_13->setStyleSheet("border:none");
    ui->article_14->setStyleSheet("border:none");
    ui->article_15->setStyleSheet("border:none");
    ui->article_16->setStyleSheet("border:none");
    ui->article_17->setStyleSheet("border:none");
    ui->article_18->setStyleSheet("border:none");

    ui->choose_1->setStyleSheet("border:none");
    ui->choose_2->setStyleSheet("border:none");
    ui->choose_3->setStyleSheet("border:none");
    ui->choose_4->setStyleSheet("border:none");
    ui->choose_5->setStyleSheet("border:none");
    ui->choose_6->setStyleSheet("border:none");
    ui->choose_7->setStyleSheet("border:none");
    ui->choose_8->setStyleSheet("border:none");
    ui->choose_9->setStyleSheet("border:none");
    ui->choose_10->setStyleSheet("border:none");
    ui->choose_11->setStyleSheet("border:none");
    ui->choose_12->setStyleSheet("border:none");
    ui->choose_13->setStyleSheet("border:none");
    ui->choose_14->setStyleSheet("border:none");
    ui->choose_15->setStyleSheet("border:none");
    ui->choose_16->setStyleSheet("border:none");
    ui->choose_17->setStyleSheet("border:none");
    ui->choose_18->setStyleSheet("border:none");


}

buy::~buy()
{
    delete ui;
}

//void buy::on_back_button_clicked()
//{
//    clickSound->play();
//    prewindow->showMaximized();
//    this->close();
//}


//void buy::on_buy_2_clicked()
//{
//    clickSound->play();

//    int price=ui->label_26->text().toInt();
//    if(User->buy(price,0)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock->hide();
//}


//void buy::on_buy_1_clicked()
//{
//    clickSound->play();

//    int price=ui->label_27->text().toInt();
//    if(User->buy(price,1)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_2->hide();
//}


//void buy::on_pushButton_clicked()
//{
//    clickSound->play();

//    int price=ui->label_28->text().toInt();
//    if(User->buy(price,2)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_3->hide();
//}


//void buy::on_pushButton_2_clicked()
//{
//    clickSound->play();

//    int price=ui->label_29->text().toInt();
//    if(User->buy(price,3)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_4->hide();
//}


//void buy::on_pushButton_3_clicked()
//{
//    clickSound->play();

//    int price=ui->label_30->text().toInt();
//    if(User->buy(price,4)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_5->hide();
//}


//void buy::on_pushButton_4_clicked()
//{
//    clickSound->play();

//    int price=ui->label_31->text().toInt();
//    if(User->buy(price,5)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_6->hide();
//}


//void buy::on_pushButton_5_clicked()
//{
//    clickSound->play();

//    int price=ui->label_32->text().toInt();
//    if(User->buy(price,6)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_7->hide();
//}


//void buy::on_pushButton_6_clicked()
//{
//    clickSound->play();

//    int price=ui->label_33->text().toInt();
//    if(User->buy(price,7)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_8->hide();
//}


//void buy::on_pushButton_7_clicked()
//{
//    clickSound->play();

//    int price=ui->label_34->text().toInt();
//    if(User->buy(price,8)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_9->hide();
//}


//void buy::on_pushButton_8_clicked()
//{
//    clickSound->play();

//    int price=ui->label_35->text().toInt();
//    if(User->buy(price,9)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_10->hide();
//}


//void buy::on_pushButton_9_clicked()
//{
//    clickSound->play();

//    int price=ui->label_36->text().toInt();
//    if(User->buy(price,10)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_11->hide();
//}


//void buy::on_pushButton_10_clicked()
//{
//    clickSound->play();

//    int price=ui->label_37->text().toInt();
//    if(User->buy(price,11)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_12->hide();
//}


//void buy::on_pushButton_11_clicked()
//{
//    clickSound->play();

//    int price=ui->label_38->text().toInt();
//    if(User->buy(price,12)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_13->hide();
//}


//void buy::on_pushButton_12_clicked()
//{
//    clickSound->play();

//    int price=ui->label_39->text().toInt();
//    if(User->buy(price,13)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_14->hide();
//}


//void buy::on_pushButton_13_clicked()
//{
//    clickSound->play();

//    int price=ui->label_40->text().toInt();
//    if(User->buy(price,14)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_15->hide();
//}


//void buy::on_pushButton_14_clicked()
//{
//    clickSound->play();

//    int price=ui->label_41->text().toInt();
//    if(User->buy(price,15)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_16->hide();
//}


//void buy::on_pushButton_15_clicked()
//{
//    clickSound->play();

//    int price=ui->label_42->text().toInt();
//    if(User->buy(price,16)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_17->hide();
//}


//void buy::on_pushButton_16_clicked()
//{
//    clickSound->play();

//    int price=ui->label_44->text().toInt();
//    if(User->buy(price,17)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_18->hide();
//}


//void buy::on_pushButton_17_clicked()
//{
//    clickSound->play();

//    int price=ui->label_45->text().toInt();
//    if(User->buy(price,18)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_19->hide();
//}


//void buy::on_pushButton_18_clicked()
//{
//    clickSound->play();

//    int price=ui->label_43->text().toInt();
//    if(User->buy(price,19)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_20->hide();
//}


//void buy::on_pushButton_19_clicked()
//{
//    clickSound->play();

//    int price=ui->label_46->text().toInt();
//    if(User->buy(price,20)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_21->hide();
//}


//void buy::on_pushButton_20_clicked()
//{
//    clickSound->play();

//    int price=ui->label_47->text().toInt();
//    if(User->buy(price,21)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_22->hide();
//}


//void buy::on_pushButton_21_clicked()
//{
//    clickSound->play();

//    int price=ui->label_48->text().toInt();
//    if(User->buy(price,22)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_23->hide();
//}


//void buy::on_pushButton_22_clicked()
//{
//    clickSound->play();

//    int price=ui->label_49->text().toInt();
//    if(User->buy(price,23)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_24->hide();
//}


//void buy::on_pushButton_23_clicked()
//{
//    clickSound->play();

//    int price=ui->label_50->text().toInt();
//    if(User->buy(price,24)==0){
//        QMessageBox message;
//        message.setText("You do not have enough coins to buy this item!");
//        message.setIcon(QMessageBox::Critical);
//        message.setWindowIcon(QIcon(":/new/image/gamename.png"));
//        message.setStyleSheet("background-color: rgb(236, 197, 119)");
//        message.exec();
//    }
//    else
//        ui->lock_25->hide();
//}

//void buy::showEvent(QShowEvent *event)
//{
//    QString file_name=User->get_user_name()+"_buy";
//    QFile f(file_name);
//    if(f.open(QIODevice::ReadOnly)){
//        QDataStream in(&f);
//        QString str;
//        for(int i=0;i<25;i++){
//            in>>str;
//            arr[i]=str.toInt();
//        }
//        f.close();
//    }

//    if(arr[0]){//item1
//        ui->lock->hide();
//        ui->buy_2->setEnabled(false);
//    }
//    else
//        ui->buy_2->setEnabled(true);

//    if(arr[1]){//item2
//        ui->lock_2->hide();
//        ui->buy_1->setEnabled(false);
//    }
//    else
//        ui->buy_1->setEnabled(true);

//    if(arr[2]){//item3
//        ui->lock_3->hide();
//        ui->pushButton->setEnabled(false);
//    }
//    else
//        ui->pushButton->setEnabled(true);

//    if(arr[3]){//item4
//        ui->lock_4->hide();
//        ui->pushButton_2->setEnabled(false);
//    }
//    else
//        ui->pushButton_2->setEnabled(true);

//    if(arr[4]){//item5
//        ui->lock_5->hide();
//        ui->pushButton_3->setEnabled(false);
//    }
//    else
//        ui->pushButton_3->setEnabled(true);

//    if(arr[5]){//item6
//        ui->lock_6->hide();
//        ui->pushButton_4->setEnabled(false);
//    }
//    else
//        ui->pushButton_4->setEnabled(true);

//    if(arr[6]){//item7
//        ui->lock_7->hide();
//        ui->pushButton_5->setEnabled(false);
//    }
//    else
//        ui->pushButton_5->setEnabled(true);

//    if(arr[7]){//item8
//        ui->lock_8->hide();
//        ui->pushButton_6->setEnabled(false);
//    }
//    else
//        ui->pushButton_6->setEnabled(true);

//    if(arr[8]){//item9
//        ui->lock_9->hide();
//        ui->pushButton_7->setEnabled(false);
//    }
//    else
//        ui->pushButton_7->setEnabled(true);

//    if(arr[9]){//item10
//        ui->lock_10->hide();
//        ui->pushButton_8->setEnabled(false);
//    }
//    else
//        ui->pushButton_8->setEnabled(true);

//    if(arr[10]){//item11
//        ui->lock_11->hide();
//        ui->pushButton_9->setEnabled(false);
//    }
//    else
//        ui->pushButton_9->setEnabled(true);

//    if(arr[11]){//item12
//        ui->lock_12->hide();
//        ui->pushButton_10->setEnabled(false);
//    }
//    else
//        ui->pushButton_10->setEnabled(true);

//    if(arr[12]){//item13
//        ui->lock_13->hide();
//        ui->pushButton_11->setEnabled(false);
//    }
//    else
//        ui->pushButton_11->setEnabled(true);

//    if(arr[13]){//item14
//        ui->lock_14->hide();
//        ui->pushButton_12->setEnabled(false);
//    }
//    else
//        ui->pushButton_12->setEnabled(true);

//    if(arr[14]){//item15
//        ui->lock_15->hide();
//        ui->pushButton_13->setEnabled(false);
//    }
//    else
//        ui->pushButton_13->setEnabled(true);

//    if(arr[15]){//item16
//        ui->lock_16->hide();
//        ui->pushButton_14->setEnabled(false);
//    }
//    else
//        ui->pushButton_14->setEnabled(true);

//    if(arr[16]){//item17
//        ui->lock_17->hide();
//        ui->pushButton_15->setEnabled(false);
//    }
//    else
//        ui->pushButton_15->setEnabled(true);

//    if(arr[17]){//item18
//        ui->lock_18->hide();
//        ui->pushButton_16->setEnabled(false);
//    }
//    else
//        ui->pushButton_16->setEnabled(true);

//    if(arr[18]){//item19
//        ui->lock_19->hide();
//        ui->pushButton_17->setEnabled(false);
//    }
//    else
//        ui->pushButton_17->setEnabled(true);

//    if(arr[19]){//item20
//        ui->lock_20->hide();
//        ui->pushButton_18->setEnabled(false);
//    }
//    else
//        ui->pushButton_18->setEnabled(true);

//    if(arr[20]){//item21
//        ui->lock_21->hide();
//        ui->pushButton_19->setEnabled(false);
//    }
//    else
//        ui->pushButton_19->setEnabled(true);

//    if(arr[21]){//item22
//        ui->lock_22->hide();
//        ui->pushButton_20->setEnabled(false);
//    }
//    else
//        ui->pushButton_20->setEnabled(true);

//    if(arr[22]){//item23
//        ui->lock_23->hide();
//        ui->pushButton_21->setEnabled(false);
//    }
//    else
//        ui->pushButton_21->setEnabled(true);

//    if(arr[23]){//item24
//        ui->lock_24->hide();
//        ui->pushButton_22->setEnabled(false);
//    }
//    else
//        ui->pushButton_22->setEnabled(true);

//    if(arr[24]){//item25
//        ui->lock_25->hide();
//        ui->pushButton_23->setEnabled(false);
//    }
//    else
//        ui->pushButton_23->setEnabled(true);

//    QWidget::showEvent(event);
//}


void buy::on_backButton_clicked()
{
    clickSound->play();
    prewindow->showMaximized();
    this->close();
}

