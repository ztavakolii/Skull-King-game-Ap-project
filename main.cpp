#include "register_login.h"

#include <QApplication>

#include "person2.h"


Person2 User("","","","","","","",0,0);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    register_login w(&a);
    w.show();
    return a.exec();
}
