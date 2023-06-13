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
    explicit RegisterAccount(QWidget *parent = nullptr);
    ~RegisterAccount();

private:
    Ui::RegisterAccount *ui;
};

#endif // REGISTERACCOUNT_H
