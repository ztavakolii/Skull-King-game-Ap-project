#ifndef SERVERWAITWINDOW_H
#define SERVERWAITWINDOW_H

#include <QMainWindow>

namespace Ui {
class ServerWaitWindow;
}

class ServerWaitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWaitWindow(QMainWindow*prewindow,QWidget *parent = nullptr);
    ~ServerWaitWindow();

private:
    Ui::ServerWaitWindow *ui;
    QMainWindow*preWindow;
};

#endif // SERVERWAITWINDOW_H
