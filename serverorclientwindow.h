#ifndef SERVERORCLIENTWINDOW_H
#define SERVERORCLIENTWINDOW_H

#include <QMainWindow>

#include "serverwindow.h"
#include "clientwindow.h"

namespace Ui {
class ServerOrClientWindow;
}

class ServerOrClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerOrClientWindow(QMainWindow*prewindow, QWidget *parent = nullptr);
    ~ServerOrClientWindow();

private:
    Ui::ServerOrClientWindow *ui;
    QMainWindow*preWindow;
    ServerWindow*serverWindow;
    ClientWindow*clientWindow;

private slots:
    void backButtonClicked();
    void serverButtonClicked();
    void clientButtonClicked();
};

#endif // SERVERORCLIENTWINDOW_H
