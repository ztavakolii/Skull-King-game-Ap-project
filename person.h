#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QPixmap>
#include "client.h"
#include "server.h"
#include "serverwaitwindow.h"

class Person
{

public:
    Person(QString,QString,QString,QString,QString,QString,QString,int,int);
    QString get_name();
    QString get_user_name();
    QString get_gender();
    QString get_password();
    QString get_phone_code();
    QString get_phone_number();
    QString get_address();
    QPixmap get_profile_picture();
    Client*get_client();
    Server*get_server();
    int get_cup();
    int get_coin();
    bool get_isserver();
    bool get_in_game();
    void set_name(QString);
    void set_user_name(QString);
    void set_gender(QString);
    void set_password(QString);
    void set_phone_code(QString);
    void set_phone_number(QString);
    void set_address(QString);
    void set_cup(int);
    void set_coin(int);
    void set_profile_picture(QPixmap profile);
    void game(bool,bool);//the person is in the game
    int add();//add the information of person in to files
    int match(int);//chack that the information is true or not
    void edit_password(QString);//change the password
    void edit();//edit information in file
    void read_information_from_file();
    void write_information_in_file();
    void set_client(QMainWindow*clientwindow,QMainWindow*personalwindow,QHostAddress serverIP);
    void set_server(ServerWaitWindow* waitwindow,QString servername,int numberofclients);
    void remove();//remove the file
    int buy(int,int);//for buy some item



private:
    QString name,user_name,gender,password,phone_code,phone_number,address;
    int coin,cup;
    bool in_game,server;
    QPixmap profile_picture;
    Client*client;
    Server*server2;
};

#endif // PERSON_H
