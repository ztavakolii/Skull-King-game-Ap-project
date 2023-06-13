#include "personalwindow.h"
#include "ui_personalwindow.h"

PersonalWindow::PersonalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonalWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Profile");
}

PersonalWindow::~PersonalWindow()
{
    delete ui;
}
