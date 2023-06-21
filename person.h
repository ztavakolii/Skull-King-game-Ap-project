#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
private:
    QString name,user_name,gender,password,phone_code,phone_number,address,power;
    int coin;
    bool in_game,server;
public:
    Person(QString,QString,QString,QString,QString,QString,QString,QString,int);
    QString get_name();
    QString get_user_name();
    QString get_gender();
    QString get_password();
    QString get_phone_code();
    QString get_phone_number();
    QString get_address();
    QString get_power();
    int get_coin();
    bool get_isserver();
    bool get_in_game();
    void edit(QString,QString,QString,QString,QString,QString,QString,QString,int);//edit information
    void game(bool,bool);//the person is in the game
};

#endif // PERSON_H
