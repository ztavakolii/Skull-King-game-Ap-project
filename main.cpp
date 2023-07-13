#include "register_login.h"

#include <QApplication>
#include "person.h"
#include <ctime>
#include <cstdlib>
#include <QSoundEffect>
#include <QMediaPlayer>

Person* User;
QMediaPlayer*backgroundSound;

int main(int argc, char *argv[])
{
    std::srand(std::time(NULL));
    QApplication a(argc, argv);
    User=new Person("","","","","","","",0,0);
    backgroundSound=new QMediaPlayer;
    backgroundSound->setSource(QUrl::fromLocalFile(":/voices/01. Abordage.wav"));
    backgroundSound->play();
    backgroundSound->setLoops(QSoundEffect::Infinite);
    register_login w(&a);
    w.show();
    return a.exec();
}
