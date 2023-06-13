#include "registeraccount.h"
#include "ui_registeraccount.h"

RegisterAccount::RegisterAccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);
}

RegisterAccount::~RegisterAccount()
{
    delete ui;
}
