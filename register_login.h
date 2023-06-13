#ifndef REGISTER_LOGIN_H
#define REGISTER_LOGIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>

#include "login.h"
#include "registeraccount.h"

QT_BEGIN_NAMESPACE
namespace Ui { class register_login; }
QT_END_NAMESPACE

class register_login : public QMainWindow
{
    Q_OBJECT

public:
    register_login(QApplication*a,QWidget *parent = nullptr);
    ~register_login();

private:
    Ui::register_login *ui;
    QPushButton*exitButton;
    QPushButton*registerAccountButton;
    QPushButton*loginButton;
    login*loginWindow;
    RegisterAccount*registerAccountWindow;

private slots:
    void showLoginWindow();
    void showRegisterAccountWindow();

};
#endif // REGISTER_LOGIN_H
