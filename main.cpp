#include "register_login.h"

#include <QApplication>
#include "person.h"
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QFont>

Person* User;
QSoundEffect*backgroundSound;
QSoundEffect*clickSound;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    User=new Person("","","","","","","",0,0);

    register_login w(&a);
    w.show();

    backgroundSound=new QSoundEffect;
    backgroundSound->setSource(QUrl::fromLocalFile(":/voices/49 Trailer - King of Cards (online-audio-converter.com).wav"));
    backgroundSound->setVolume(0.05);
    backgroundSound->play();
    backgroundSound->setLoopCount(QSoundEffect::Infinite);

    clickSound=new QSoundEffect;
    clickSound->setSource(QUrl::fromLocalFile(":/voices/clickSound.wav"));
    clickSound->setVolume(1.0);

    QFont defaultFont("Pixeto");
    a.setFont(defaultFont);
    return a.exec();
}
