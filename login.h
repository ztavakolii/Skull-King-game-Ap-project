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
    explicit login(QWidget *parent = nullptr);

   // void setHelloTextEdit();

    ~login();

private:
    Ui::login *ui;
    PersonalWindow*personalWindow;

private slots:
    void changePasswordLineEditMode();
    void forgetPassword();
    void showPersonalWindow();
    void enableLoginButton();
    void enablePhoneOkButton();
    void checkMatchingUsernameandPhoneNumber();
    void enableNewPasswordOkButton();
    void changePasswordAndShowPersonalWindow();

};

#endif // LOGIN_H
