#ifndef PERSON2_H
#define PERSON2_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QApplication>


namespace Ui {
class Person2;
}

class Person2 : public QWidget
{
    Q_OBJECT

public:
    explicit Person2(QWidget *parent = nullptr);
    ~Person2();
    Person2(QString,QString,QString,QString,QString,QString,QString,int,int,QWidget *parent = nullptr);
    QString get_name();
    QString get_user_name();
    QString get_gender();
    QString get_password();
    QString get_phone_code();
    QString get_phone_number();
    QString get_address();
    QPixmap get_profile_picture();
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
    void read_information_from_file();
    void write_information_in_file();

private:
    Ui::Person2 *ui;
    QString name,user_name,gender,password,phone_code,phone_number,address;
    int coin,cup;
    bool in_game,server;
    QPixmap profile_picture;

};

#endif // PERSON2_H
