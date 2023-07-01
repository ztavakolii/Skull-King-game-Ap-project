#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ui_playwindow.h"

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

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
    int remainingtime;
};

#endif // PLAYWINDOW_H
