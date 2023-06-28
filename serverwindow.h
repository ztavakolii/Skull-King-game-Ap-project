#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include "serverwaitwindow.h"

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QMainWindow*prewindow,QMainWindow*personalwindow,QWidget *parent = nullptr);
    ~ServerWindow();

private:
    Ui::ServerWindow *ui;
    QMainWindow*preWindow;
    QMainWindow*personalWindow;
    ServerWaitWindow*serverWaitWindow;

private slots:
    void backButtonClicked();
    void confirmButtonClicked();
};

#endif // SERVERWINDOW_H
