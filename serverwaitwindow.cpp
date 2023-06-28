#include "serverwaitwindow.h"
#include "ui_serverwaitwindow.h"

ServerWaitWindow::ServerWaitWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWaitWindow)
{
    ui->setupUi(this);
}

ServerWaitWindow::~ServerWaitWindow()
{
    delete ui;
}
