#include "register_login.h"

#include <QApplication>
#include "person.h"

Person* User;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User=new Person("","","","","","","",0,0);
    register_login w(&a);
    w.show();
    return a.exec();
}
