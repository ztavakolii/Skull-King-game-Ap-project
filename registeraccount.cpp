#include "registeraccount.h"
#include "ui_registeraccount.h"

RegisterAccount::RegisterAccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Register Account");


}

RegisterAccount::~RegisterAccount()
{
    delete ui;
}
