#include "person2.h"
#include "ui_person2.h"
#include <QFile>
#include <QTextStream>

Person2::Person2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Person2)
{
    ui->setupUi(this);
}

Person2::~Person2()
{
    delete ui;
}

Person2::Person2(QString name,QString user_name,QString gender,QString password,QString phone_code,QString phone_number,QString address,int cup,int coin,QWidget *parent)
:    QWidget(parent),
    ui(new Ui::Person2){
    this->name=name;
    this->user_name=user_name;
    this->gender=gender;
    this->password=password;
    this->phone_code=phone_code;
    this->phone_number=phone_number;
    this->address=address;
    this->cup=cup;
    this->coin=coin;
    in_game=false;
    server=false;
}

QString Person2::get_name(){
    return name;
}

QString Person2::get_user_name(){
    return user_name;
}

QString Person2::get_gender(){
    return gender;
}

QString Person2::get_password(){
    return password;
}

QString Person2::get_phone_code(){
    return phone_code;
}

QString Person2::get_phone_number(){
    return phone_number;
}

QString Person2::get_address(){
    return address;
}

QPixmap Person2::get_profile_picture()
{
    return profile_picture;
}

int Person2::get_cup(){
    return cup;
}

int Person2::get_coin(){
    return coin;
}

bool Person2::get_isserver(){
    return server;
}

bool Person2::get_in_game(){
    return in_game;
}

void Person2::set_name(QString name){
    this->name=name;
}

void Person2::set_user_name(QString user_name){
    this->user_name=user_name;
}

void Person2::set_gender(QString gender){
    this->gender=gender;
}

void Person2::set_password(QString password){
    this->password=password;
}

void Person2::set_phone_code(QString phone_code){
    this->phone_code=phone_code;
}

void Person2::set_phone_number(QString phone_number){
    this->phone_number=phone_number;
}

void Person2::set_address(QString address){
    this->address=address;
}

void Person2::set_cup(int cup){
    this->cup=cup;
}

void Person2::set_coin(int coin){
    this->coin=coin;
}

void Person2::set_profile_picture(QPixmap profile)
{
    profile_picture=profile;
}

void Person2::game(bool game,bool is_server){
    in_game=game;
    server=is_server;
}

int Person2::add(){
    QString  file_name=user_name;

    if(!(QFile::exists(file_name))){//create new file

        // assignment default profile picture to player
        if(gender=="Male") {
            QPixmap p(":/new/image/icons8-boy-96.png");
            profile_picture=p;
        }
        else if(gender=="Female"){
            QPixmap p(":/new/image/icons8-girl-96.png");
            profile_picture=p;
        }

        QFile f(file_name);
        f.open(QIODevice::WriteOnly);
        QDataStream out(&f);
        out<<name<<user_name<<gender<<password<<phone_code<<phone_number<<address<<cup<<coin<<profile_picture;
        f.close();
        return 1;

    }

    return 0;//the file has already exists
}
int Person2::match(int n){
    QString  file_name=user_name;
    if(!(QFile::exists(file_name)))//the file does not exist
        return 0;

    QString name,user_name,gender,password,phone_code,phone_number,address;
    int cup,coin;

    if(n==1){//check password

        QFile f(file_name);
        f.open(QIODevice::ReadOnly);
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture;
        f.close();

        if(this->password==password)//the password is true
            return 1;

        else//the password is wrong
            return 0;

    }
    else if(n==2){//chack phone number
        QFile f(file_name);
        f.open(QIODevice::ReadOnly);
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture;
        f.close();

        if(this->phone_code==phone_code&&this->phone_number==phone_number)//the phone_number is true
            return 1;

        else//the phone number is wrong
            return 0;

    }

}
void Person2::edit_password(QString new_password){//change password in file

    QString  file_name=user_name;
    QFile f(file_name);
    f.open(QIODevice::ReadOnly);//read the previous file
    QDataStream in(&f);
    in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture;
    f.close();
    this->password=new_password;
    if(f.remove())//remove the previous file & make new file with new password
        this->add();
}

void Person2::read_information_from_file()
{
    QString file_name=user_name;
    QFile f(file_name);
    if(f.open(QIODevice::ReadOnly)){
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture;
        f.close();
    }
}

void Person2::write_information_in_file()
{
    QString file_name=user_name;
    QFile f(file_name);
    if(f.open(QIODevice::WriteOnly)){
        QDataStream out(&f);
        out<<name<<user_name<<gender<<password<<phone_code<<phone_number<<address<<cup<<coin<<profile_picture;
        f.close();
    }
}
