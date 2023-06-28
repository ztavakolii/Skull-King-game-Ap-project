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
    explicit ServerWaitWindow(QWidget *parent = nullptr);
    ~ServerWaitWindow();

private:
    Ui::ServerWaitWindow *ui;
};

#endif // SERVERWAITWINDOW_H
