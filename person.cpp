#include "person.h"

Person::Person(QString name,QString user_name,QString gender,QString password,QString phone_code,QString phone_number,QString address,QString power,int coin)
{
    this->name=name;
    this->user_name=user_name;
    this->gender=gender;
    this->password=password;
    this->phone_code=phone_code;
    this->phone_number=phone_number;
    this->address=address;
    this->power=power;
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
QString Person::get_power(){
    return power;
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
void Person::edit(QString name,QString user_name,QString gender,QString password,QString phone_code,QString phone_number,QString address,QString power,int coin){
    this->name=name;
    this->user_name=user_name;
    this->gender=gender;
    this->password=password;
    this->phone_code=phone_code;
    this->phone_number=phone_number;
    this->address=address;
    this->power=power;
    this->coin=coin;
    in_game=false;
    server=false;
}
void Person::game(bool game,bool is_server){
    in_game=game;
    server=is_server;
}
