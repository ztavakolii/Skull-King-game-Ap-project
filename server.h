#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QMainWindow*prewindow,QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Server *ui;
    QMainWindow*preWindow;
};

#endif // SERVER_H
