#include "buy.h"
#include "ui_buy.h"
#include "QMessageBox"
#include "person.h"

extern Person User;

buy::buy(QMainWindow *previousWindow,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy)
{
    ui->setupUi(this);

    prewindow=previousWindow;
    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Store");
    if(ui->lock_2->isHidden())
        ui->back_button->setEnabled(false);
    else
        ui->back_button->setEnabled(true);
}

buy::~buy()
{
    delete ui;
}

void buy::on_back_button_clicked()
{
    prewindow->showMaximized();
    this->close();
}


void buy::on_buy_2_clicked()
{
    int price=ui->label_26->text().toInt();
    if(User.buy(price)==0)
        QMessageBox::critical(this,"Error","You do not have enough coins to buy this item!");
    else
        ui->lock_2->hide();
}

