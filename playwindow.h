#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
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
    explicit PlayWindow(QWidget *parent = nullptr);
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
//    void rotate();

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
    QEventLoop eventLoop;
    int remainingtime;
    void handle_loop(int);
    void start_hand();
    void placeLabelsAroundCircle(int,int);
};

#endif // PLAYWINDOW_H
