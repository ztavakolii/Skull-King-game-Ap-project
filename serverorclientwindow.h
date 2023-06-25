#ifndef SERVERORCLIENTWINDOW_H
#define SERVERORCLIENTWINDOW_H

#include <QMainWindow>

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
};

#endif // SERVERORCLIENTWINDOW_H
