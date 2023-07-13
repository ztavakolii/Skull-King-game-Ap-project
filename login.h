#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "personalwindow.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QMainWindow*previousWindow,QWidget *parent = nullptr);


    ~login();

private:
    Ui::login *ui;
    PersonalWindow*personalWindow;
    QMainWindow*preWindow;

private slots:
    void changePasswordLineEditMode();
    void changeNewPasswordLineEditMode();
    void forgetPassword();
    void showPersonalWindow();
    void enableLoginButton();
    void enablePhoneOkButton();
    void checkMatchingUsernameandPhoneNumber();
    void enableNewPasswordOkButton();
    void changePasswordAndShowPersonalWindow();
    void backButtonClicked();
};

#endif // LOGIN_H
