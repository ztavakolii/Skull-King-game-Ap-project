#include "buy.h"
#include "ui_buy.h"

buy::buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy)
{
    ui->setupUi(this);
}

buy::~buy()
{
    delete ui;
}
