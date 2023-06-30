#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();
    void startcountdown();

private slots:
    void on_stop_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
};

#endif // PLAYWINDOW_H
