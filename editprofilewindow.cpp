#include "editprofilewindow.h"
#include "ui_editprofilewindow.h"

EditProfileWindow::EditProfileWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfileWindow)
{
    ui->setupUi(this);
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Edit profile");

}

EditProfileWindow::~EditProfileWindow()
{
    delete ui;
}
