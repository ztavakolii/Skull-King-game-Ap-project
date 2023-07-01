#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QTimer>
#include "ui_playwindow.h"

=======
#include "QEventLoop"
>>>>>>> 3256dce0dc2e784880dde36bbf497b361aeead72
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

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
    QEventLoop eventLoop;
    int remainingtime;
    void handle_loop(int);
};

#endif // PLAYWINDOW_H
