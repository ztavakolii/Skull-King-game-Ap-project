#include "buy.h"
#include "ui_buy.h"
#include "QMessageBox"
#include "person.h"

extern Person User;

buy::buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Store");
    if(ui->lock_2->isHidden())
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}

buy::~buy()
{
    delete ui;
}

void buy::on_pushButton_clicked()
{
    int price=ui->text_2->text().toInt();
    if(User.buy(price)==0)
        QMessageBox::critical(this,"Error","You do not have enough coins to buy this item!");
    else
        ui->lock_2->hide();
}

