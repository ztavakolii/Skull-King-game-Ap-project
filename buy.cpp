#include "buy.h"
#include "ui_buy.h"
#include "QMessageBox"
#include "person.h"
#include <QSoundEffect>
#include <QFile>
#include <QTextStream>

extern Person *User;
extern QSoundEffect*clickSound;

int arr[18];

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


//    QString file_name=User->get_user_name()+"_buy";
//    QFile f(file_name);
//    if(f.open(QIODevice::ReadOnly)){
//        QDataStream in(&f);
//        QString str;
//        for(int i=0;i<18;i++){
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

    ui->default_1->setStyleSheet("border:none");
    ui->default_2->setStyleSheet("border:none");

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

void buy::showEvent(QShowEvent *event)
{
    QString file_name=User->get_user_name()+"_buy";
    QFile f(file_name);
    if(f.open(QIODevice::ReadOnly)){
        QDataStream in(&f);
        //QString str;
        int a;
        for(int i=0;i<18;i++){
            in>>a;
            arr[i]=a;
        }
        f.close();
    }

    if(arr[0]){
        ui->lock_1->hide();
        ui->choose_1->show();
        ui->article_1->setEnabled(false);
    }
    else{
        ui->choose_1->hide();
        ui->article_1->setEnabled(true);
    }

    if(arr[1]){
        ui->lock_2->hide();
        ui->choose_2->show();
        ui->article_2->setEnabled(false);
    }
    else{
        ui->choose_2->hide();
        ui->article_2->setEnabled(true);
    }

    if(arr[2]){
        ui->lock_3->hide();
        ui->choose_3->show();
        ui->article_3->setEnabled(false);
    }
    else{
        ui->choose_3->hide();
        ui->article_3->setEnabled(true);
    }

    if(arr[3]){
        ui->lock_4->hide();
        ui->choose_4->show();
        ui->article_4->setEnabled(false);
    }
    else{
        ui->choose_4->hide();
        ui->article_4->setEnabled(true);
    }

    if(arr[4]){
        ui->lock_5->hide();
        ui->choose_5->show();
        ui->article_5->setEnabled(false);
    }
    else{
        ui->choose_5->hide();
        ui->article_5->setEnabled(true);
    }

    if(arr[5]){
        ui->lock_6->hide();
        ui->choose_6->show();
        ui->article_6->setEnabled(false);
    }
    else{
        ui->choose_6->hide();
        ui->article_6->setEnabled(true);
    }

    if(arr[6]){
        ui->lock_7->hide();
        ui->choose_7->show();
        ui->article_7->setEnabled(false);
    }
    else{
        ui->choose_7->hide();
        ui->article_7->setEnabled(true);
    }


    if(arr[7]){
        ui->lock_8->hide();
        ui->choose_8->show();
        ui->article_8->setEnabled(false);
    }
    else{
        ui->choose_8->hide();
        ui->article_8->setEnabled(true);
    }

    if(arr[8]){
        ui->lock_9->hide();
        ui->choose_9->show();
        ui->article_9->setEnabled(false);
    }
    else{
        ui->choose_9->hide();
        ui->article_9->setEnabled(true);
    }

    if(arr[9]){
        ui->lock_10->hide();
        ui->choose_10->show();
        ui->article_10->setEnabled(false);
    }
    else{
        ui->choose_10->hide();
        ui->article_10->setEnabled(true);
    }

    if(arr[10]){
        ui->lock_11->hide();
        ui->choose_11->show();
        ui->article_11->setEnabled(false);
    }
    else{
        ui->choose_11->hide();
        ui->article_11->setEnabled(true);
    }

    if(arr[11]){
        ui->lock_12->hide();
        ui->choose_12->show();
        ui->article_12->setEnabled(false);
    }
    else{
        ui->choose_12->hide();
        ui->article_12->setEnabled(true);
    }

    if(arr[12]){
        ui->lock_13->hide();
        ui->choose_13->show();
        ui->article_13->setEnabled(false);
    }
    else{
        ui->choose_13->hide();
        ui->article_13->setEnabled(true);
    }

    if(arr[13]){
        ui->lock_14->hide();
        ui->choose_14->show();
        ui->article_14->setEnabled(false);
    }
    else{
        ui->choose_14->hide();
        ui->article_14->setEnabled(true);
    }

    if(arr[14]){
        ui->lock_15->hide();
        ui->choose_15->show();
        ui->article_15->setEnabled(false);
    }
    else{
        ui->choose_15->hide();
        ui->article_15->setEnabled(true);
    }

    if(arr[15]){
        ui->lock_16->hide();
        ui->choose_16->show();
        ui->article_16->setEnabled(false);
    }
    else{
        ui->choose_16->hide();
        ui->article_16->setEnabled(true);
    }

    if(arr[16]){
        ui->lock_17->hide();
        ui->choose_17->show();
        ui->article_17->setEnabled(false);
    }
    else{
        ui->choose_17->hide();
        ui->article_17->setEnabled(true);
    }

    if(arr[17]){
        ui->lock_18->hide();
        ui->choose_18->show();
        ui->article_18->setEnabled(false);
    }
    else{
        ui->choose_18->hide();
        ui->article_18->setEnabled(true);
    }
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

    QWidget::showEvent(event);
}


void buy::on_backButton_clicked()
{
    clickSound->play();
    prewindow->showMaximized();
    this->close();
}


void buy::on_article_1_clicked()
{
    clickSound->play();

        int price=ui->price_1->text().toInt();
        if(User->buy(price,1,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_1->hide();
            ui->choose_1->show();
            ui->article_1->setEnabled(false);
        }
}


void buy::on_article_2_clicked()
{
        clickSound->play();

        int price=ui->price_2->text().toInt();
        if(User->buy(price,2,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_2->hide();
            ui->choose_2->show();
            ui->article_2->setEnabled(false);
        }
}


void buy::on_article_3_clicked()
{
        clickSound->play();

        int price=ui->price_3->text().toInt();
        if(User->buy(price,3,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_3->hide();
            ui->choose_3->show();
            ui->article_3->setEnabled(false);
        }
}


void buy::on_article_4_clicked()
{
        clickSound->play();

        int price=ui->price_4->text().toInt();
        if(User->buy(price,4,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_4->hide();
            ui->choose_4->show();
            ui->article_4->setEnabled(false);
        }
}


void buy::on_article_5_clicked()
{
        clickSound->play();

        int price=ui->price_5->text().toInt();
        if(User->buy(price,5,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_5->hide();
            ui->choose_5->show();
            ui->article_5->setEnabled(false);
        }
}


void buy::on_article_6_clicked()
{
        clickSound->play();

        int price=ui->price_6->text().toInt();
        if(User->buy(price,6,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_6->hide();
            ui->choose_6->show();
            ui->article_6->setEnabled(false);
        }
}


void buy::on_article_7_clicked()
{
        clickSound->play();

        int price=ui->price_7->text().toInt();
        if(User->buy(price,7,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_7->hide();
            ui->choose_7->show();
            ui->article_7->setEnabled(false);
        }
}


void buy::on_article_8_clicked()
{
        clickSound->play();

        int price=ui->price_8->text().toInt();
        if(User->buy(price,8,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_8->hide();
            ui->choose_8->show();
            ui->article_8->setEnabled(false);
        }
}


void buy::on_article_9_clicked()
{
        clickSound->play();

        int price=ui->price_9->text().toInt();
        if(User->buy(price,9,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_9->hide();
            ui->choose_9->show();
            ui->article_9->setEnabled(false);
        }
}


void buy::on_article_10_clicked()
{
        clickSound->play();

        int price=ui->price_10->text().toInt();
        if(User->buy(price,10,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_10->hide();
            ui->choose_10->show();
            ui->article_10->setEnabled(false);
        }
}


void buy::on_article_11_clicked()
{
        clickSound->play();

        int price=ui->price_11->text().toInt();
        if(User->buy(price,11,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_11->hide();
            ui->choose_11->show();
            ui->article_11->setEnabled(false);
        }
}


void buy::on_article_12_clicked()
{
        clickSound->play();

        int price=ui->price_12->text().toInt();
        if(User->buy(price,12,1)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_12->hide();
            ui->choose_12->show();
            ui->article_12->setEnabled(false);
        }
}


void buy::on_choose_1_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_1->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_2_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_2->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_3_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_3->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_4_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_4->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_5_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_5->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_6_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_6->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_7_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_7->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_8_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_8->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_9_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_9->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_10_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_10->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_11_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_11->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_12_clicked()
{
        clickSound->play();

        User->set_profile_picture(ui->object_12->pixmap());
        User->write_information_in_file();
}


void buy::on_article_13_clicked()
{
        clickSound->play();

        int price=ui->price_13->text().toInt();
        if(User->buy(price,13,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_13->hide();
            ui->choose_13->show();
            ui->article_13->setEnabled(false);
        }
}


void buy::on_article_14_clicked()
{
        clickSound->play();

        int price=ui->price_14->text().toInt();
        if(User->buy(price,14,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_14->hide();
            ui->choose_14->show();
            ui->article_14->setEnabled(false);
        }
}


void buy::on_article_15_clicked()
{
        clickSound->play();

        int price=ui->price_15->text().toInt();
        if(User->buy(price,15,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_15->hide();
            ui->choose_15->show();
            ui->article_15->setEnabled(false);
        }
}


void buy::on_article_16_clicked()
{
        clickSound->play();

        int price=ui->price_16->text().toInt();
        if(User->buy(price,16,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_16->hide();
            ui->choose_16->show();
            ui->article_16->setEnabled(false);
        }
}


void buy::on_article_17_clicked()
{
        clickSound->play();

        int price=ui->price_17->text().toInt();
        if(User->buy(price,17,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_17->hide();
            ui->choose_17->show();
            ui->article_17->setEnabled(false);
        }
}


void buy::on_article_18_clicked()
{
        clickSound->play();

        int price=ui->price_18->text().toInt();
        if(User->buy(price,18,2)==0){
            QMessageBox message;
            message.setText("You do not have enough coins to buy this item!");
            message.setIcon(QMessageBox::Critical);
            message.setWindowIcon(QIcon(":/new/image/gamename.png"));
            message.setStyleSheet("background-color: rgb(236, 197, 119)");
            message.exec();
        }
        else{
            ui->lock_18->hide();
            ui->choose_18->show();
            ui->article_18->setEnabled(false);
        }
}


void buy::on_choose_13_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_13->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_14_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_14->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_15_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_15->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_16_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_16->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_17_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_17->pixmap());
        User->write_information_in_file();
}


void buy::on_choose_18_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(ui->object_18->pixmap());
        User->write_information_in_file();
}


void buy::on_default_1_clicked()
{
        clickSound->play();

        if(User->get_gender() == "Male")
            User->set_profile_picture(QPixmap(":/new/image/icons8-boy-96.png"));
        else if(User->get_gender() == "Female")
            User->set_profile_picture(QPixmap(":/new/image/icons8-girl-96.png"));

        User->write_information_in_file();
}




void buy::on_default_2_clicked()
{
        clickSound->play();

        User->set_playWindowBackground(QPixmap(":/new/image/b428506e-7875-42da-aeb9-0e662cce7e32.jfif"));
        User->write_information_in_file();
}

