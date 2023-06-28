#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "clientwaitwindow.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QMainWindow*personalwindow,QMainWindow*prewindow,QWidget *parent = nullptr);
    ~ClientWindow();

private:
    Ui::ClientWindow *ui;
    QMainWindow*preWindow;
    QMainWindow*personalWindow;
    ClientWaitWindow*clientWaitWindow;


private slots:
    void backButtonClicked();
    void connectButtonClicked();
};

#endif // CLIENTWINDOW_H
