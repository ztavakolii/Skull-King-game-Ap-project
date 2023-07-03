#ifndef SERVERWAITWINDOW_H
#define SERVERWAITWINDOW_H

#include <QMainWindow>
#include <thread>
#include "playwindow.h"
//#include "personalwindow.h"

namespace Ui {
class ServerWaitWindow;
}

class ServerWaitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWaitWindow(QMainWindow*prewindow,QWidget *parent = nullptr);
    ~ServerWaitWindow();
    void setGuideTextEdit();

private:
    Ui::ServerWaitWindow *ui;
    QMainWindow*preWindow;
  //  QMainWindow*personalWindow;
   // PlayWindow*playWindow;
   // std::thread t;

public slots:
    void backButtonClicked();
    void deleteServerButtonClicked();
    void playButtonClicked();
    void deleteServer();
    void showConnectedClients();

};

#endif // SERVERWAITWINDOW_H
