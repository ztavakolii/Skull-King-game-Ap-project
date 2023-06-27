#ifndef CLIENTWAITWINDOW_H
#define CLIENTWAITWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClientWaitWindow;
}

class ClientWaitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWaitWindow(QWidget *parent = nullptr);
    ~ClientWaitWindow();

private:
    Ui::ClientWaitWindow *ui;
};

#endif // CLIENTWAITWINDOW_H
