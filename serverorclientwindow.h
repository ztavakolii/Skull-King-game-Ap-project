#ifndef SERVERORCLIENTWINDOW_H
#define SERVERORCLIENTWINDOW_H

#include <QMainWindow>

#include "server.h"
#include "client.h"

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
    Server*serverWindow;
    Client*clientWindow;

private slots:
    void backButtonClicked();
    void serverButtonClicked();
    void clientButtonClicked();
};

#endif // SERVERORCLIENTWINDOW_H
