#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QTextStream>
#include <thread>
#include <QTimer>
#include "ui_playwindow.h"
#include "QEventLoop"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QMainWindow*personalwindow,QWidget *parent = nullptr);
    ~PlayWindow();
    void startcountdown(int);
    void savedatetime();

private slots:
    void on_stop_button_clicked();
    void on_exit_button_clicked();
    void f();
    void set_round_hand(int ,int);
    void on_exchange_button_clicked();
    void on_ok_button_clicked();

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
    QEventLoop eventLoop;
    int remainingtime;
    std::thread*t;//thread of reading information sent by server if the player become client
    QMainWindow*personalWindow;

    void handle_loop(int);

    void readInformationSentByServer();//for clients
    void exitCodeReceived(QString clientName);
};

#endif // PLAYWINDOW_H
