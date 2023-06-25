#include "person.h"
#include <QFile>
#include <QTextStream>
Person::Person(QString name,QString user_name,QString gender,QString password,QString phone_code,QString phone_number,QString address,int cup,int coin)
{
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

QString Person::get_name(){
    return name;
}

QString Person::get_user_name(){
    return user_name;
}

QString Person::get_gender(){
    return gender;
}

QString Person::get_password(){
    return password;
}

QString Person::get_phone_code(){
    return phone_code;
}

QString Person::get_phone_number(){
    return phone_number;
}

QString Person::get_address(){
    return address;
}

int Person::get_cup(){
    return cup;
}

int Person::get_coin(){
    return coin;
}

bool Person::get_isserver(){
    return server;
}

bool Person::get_in_game(){
    return in_game;
}

void Person::set_name(QString name){
    this->name=name;
}

void Person::set_user_name(QString user_name){
    this->user_name=user_name;
}

void Person::set_gender(QString gender){
    this->gender=gender;
}

void Person::set_password(QString password){
    this->password=password;
}

void Person::set_phone_code(QString phone_code){
    this->phone_code=phone_code;
}

void Person::set_phone_number(QString phone_number){
    this->phone_number=phone_number;
}

void Person::set_address(QString address){
    this->address=address;
}

void Person::set_cup(int cup){
    this->cup=cup;
}

void Person::set_coin(int coin){
    this->coin=coin;
}

void Person::game(bool game,bool is_server){
    in_game=game;
    server=is_server;
}

int Person::add(){
    QString  file_name=user_name;

    if(!(QFile::exists(file_name))){//create new file

    QFile f(file_name);
    f.open(QIODevice::WriteOnly);
    QDataStream cout(&f);
    cout<<name<<user_name<<gender<<password<<phone_code<<phone_number<<address<<cup<<coin;
    f.close();
    return 1;

    }

    return 0;//the file has already exists
}
//int Person::match(int n){
//     QString  file_name=user_name;
//    if(!(QFile::exists(file_name)))//the file does not exist
//        return 0;

//    QString name,user_name,gender,password,phone_code,phone_number,address;
//    int cup,coin;

//    if(n==1){//check password

//        QFile f(file_name);
//        f.open(QIODevice::ReadOnly);
//        QDataStream cin(&f);
//        cin>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin;
//        f.close();

//        if(this->password==password)//the password is true
//            return 1;

//        else//the password is wrong
//            return 0;

//     }
//    else if(n==2){//chack phone number
//        QFile f(file_name);
//        f.open(QIODevice::ReadOnly);
//        QDataStream cin(&f);
//        cin>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin;
//        f.close();

//        if(this->phone_code==phone_code&&this->phone_number==phone_number){//the phone_number is true
//            this->name=name;
//            this->user_name=user_name;
//            this->gender=gender;
//            this->password=password;
//            this->phone_code=phone_code;
//            this->phone_number=phone_number;
//            this->address=address;
//            this->cup=cup;
//            this->coin=coin;
//            return 1;
//        }

//        else//the phone number is wrong
//            return 0;

//    }

//}
