#include "historywindow.h"
#include "ui_historywindow.h"

HistoryWindow::HistoryWindow(QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("History");

    preWindow=prewindow;

}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}
