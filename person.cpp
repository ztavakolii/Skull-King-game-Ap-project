#include "person.h"
#include <QCryptographicHash>
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
    client=nullptr;
    server2=nullptr;
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

QPixmap Person::get_profile_picture()
{
    return profile_picture;
}

QPixmap Person::get_playWindowBackground()
{
    return playWindowBackground;
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

void Person::set_profile_picture(QPixmap profile)
{
    profile_picture=profile;
}

void Person::set_playWindowBackground(QPixmap background)
{
    playWindowBackground = background;
}

void Person::game(bool game,bool is_server){
    in_game=game;
    server=is_server;
}

int Person::add(bool isNew){
    QString  file_name=user_name;

    if(!(QFile::exists(file_name))){//create new file

        if(isNew){
        // assignment default profile picture to player
        if(gender=="Male") {
            QPixmap p(":/new/image/icons8-boy-96.png");
            profile_picture=p;
            QPixmap b(":/new/image/b428506e-7875-42da-aeb9-0e662cce7e32.jfif");
            playWindowBackground=b;
        }
        else if(gender=="Female"){
           QPixmap p(":/new/image/icons8-girl-96.png");
            profile_picture=p;
           QPixmap b(":/new/image/b428506e-7875-42da-aeb9-0e662cce7e32.jfif");
           playWindowBackground=b;
        }
        }

        QFile f(file_name);
        f.open(QIODevice::WriteOnly);
        QDataStream out(&f);
        out<<name<<user_name<<gender<<password<<phone_code<<phone_number<<address<<cup<<coin<<profile_picture<<playWindowBackground;
        f.close();
        return 1;

    }

    return 0;//the file has already exists
}
int Person::match(int n){
    QString  file_name=user_name;
    if(!(QFile::exists(file_name)))//the file does not exist
        return 0;

    QString name,user_name,gender,password,phone_code,phone_number,address;
    int cup,coin;

    if(n==1){//check password

        QFile f(file_name);
        f.open(QIODevice::ReadOnly);
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture>>playWindowBackground;
        f.close();

//        QByteArray hashed=QCryptographicHash::hash(this->password.toUtf8(),QCryptographicHash::Sha256);
//        QString hashedPassword=QString(hashed.toHex());

        if(this->password==password)//the password is true
            return 1;

        else//the password is wrong
            return 0;

    }
    else if(n==2){//chack phone number
        QFile f(file_name);
        f.open(QIODevice::ReadOnly);
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture>>playWindowBackground;
        f.close();

        if(this->phone_code==phone_code&&this->phone_number==phone_number)//the phone_number is true
            return 1;

        else//the phone number is wrong
            return 0;

    }

}
void Person::edit_password(QString new_password){//change password in file

    QString  file_name=user_name;
    QFile f(file_name);
    f.open(QIODevice::ReadOnly);//read the previous file
    QDataStream in(&f);
    in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture>>playWindowBackground;
    f.close();
    this->password=new_password;
    if(f.remove())//remove the previous file & make new file with new password
        this->add(false);
}

void Person::edit(){
    QFile f(user_name);
    f.remove();
    add(false);
}

void Person::read_information_from_file()
{
    QString file_name=user_name;
    QFile f(file_name);
    if(f.open(QIODevice::ReadOnly)){
        QDataStream in(&f);
        in>>name>>user_name>>gender>>password>>phone_code>>phone_number>>address>>cup>>coin>>profile_picture>>playWindowBackground;
        f.close();
    }
}

void Person::write_information_in_file()
{
    QString file_name=user_name;
    QFile f(file_name);
    if(f.open(QIODevice::WriteOnly)){
        QDataStream out(&f);

//        QByteArray hashed=QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256);
//        QString hashedPassword=QString(hashed.toHex());

        out<<name<<user_name<<gender<<password<<phone_code<<phone_number<<address<<cup<<coin<<profile_picture<<playWindowBackground;
        f.close();
    }
}

void Person::set_client(QMainWindow*clientwindow,QMainWindow*personalwindow,QHostAddress serverIP)
{
    client=new Client(clientwindow,personalwindow,serverIP);
}

void Person::set_server(ServerWaitWindow* waitwindow,QString servername, int numberofclients)
{
    server2=new Server(waitwindow,servername,numberofclients);
}

Client*& Person::get_client(){
    return client;
}

Server*& Person::get_server()
{
    return server2;
}


void Person::remove(){
    QString file_name=user_name;
    QFile f(file_name);
    f.remove();
}
int Person::buy(int price,int number,int source){
    int arr[18];

    if(source == 1){
    if(coin<price)//do not have enough coin
        return 0;
    coin=coin-price;
    QString file_name=user_name;
    QFile f(file_name);
    f.remove();
    add(false);
    f.close();

    file_name=user_name+"_buy";
    QFile b1(file_name);
        if(b1.open(QIODevice::ReadOnly)){
            QDataStream in(&b1);
           // QString str;
            int a;
            for(int i=0;i<18;i++){
                in>>a;
                arr[i]=a;
            }
            b1.close();
            b1.remove();
            arr[number - 1] = 1;
        }

    QFile b(file_name);
    if(b.open(QIODevice::WriteOnly)){
        QDataStream out1(&b);
        for(int i=0;i<18;i++){
            if(arr[i] == 1)
                out1<<1;
            else
                out1<<0;
        }
        b.close();
    }
    return 1;
    }
    else if(source == 2){
    if(cup<price)//do not have enough cup
        return 0;
    cup=cup-price;
    QString file_name=user_name;
    QFile f(file_name);
    f.remove();
    add(false);
    f.close();

    file_name=user_name+"_buy";
    QFile b1(file_name);
    if(b1.open(QIODevice::ReadOnly)){
        QDataStream in(&b1);
        //QString str;
        int a;
        for(int i=0;i<18;i++){
            in>>a;
            arr[i]=a;
        }
        b1.close();
        b1.remove();
        arr[number - 1] = 1;
    }

    QFile b(file_name);
    if(b.open(QIODevice::WriteOnly)){
        QDataStream out1(&b);
        for(int i=0;i<18;i++){
            if(arr[i])
                out1<<1;
            else
                out1<<0;
        }
        b.close();
    }
    return 1;
    }
}

