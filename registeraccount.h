#ifndef REGISTERACCOUNT_H
#define REGISTERACCOUNT_H

#include <QMainWindow>


namespace Ui {
class RegisterAccount;
}

class RegisterAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterAccount(QMainWindow *prewindow,QWidget *parent = nullptr);
    ~RegisterAccount();

private slots:
    void on_eye_p_clicked();

    void on_back_button_clicked();

    void on_login_pushbutton_clicked();

private:
    Ui::RegisterAccount *ui;
    QMainWindow *prewindow;
};

#endif // REGISTERACCOUNT_H
