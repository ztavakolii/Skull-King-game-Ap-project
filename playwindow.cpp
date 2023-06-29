#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Play");

    ui->stop_button->setStyleSheet("border:none");
    ui->exit_button->setStyleSheet("border:none");

}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::on_stop_button_clicked()
{
    QPixmap pixmap1(":/new/image/icons8-play-button-96.png");
    QPixmap labelpixmap=ui->stop_label->pixmap();
    QImage image1=pixmap1.toImage();
    QImage image=labelpixmap.toImage();
    if(image1!=image){
        QPixmap p(":/new/image/icons8-play-button-96.png");
        ui->stop_label->setPixmap(p);
    }
    else{
        QPixmap p(":/new/image/icons8-pause-button-96.png");
        ui->stop_label->setPixmap(p);
    }
}


void PlayWindow::on_exit_button_clicked()
{

}

