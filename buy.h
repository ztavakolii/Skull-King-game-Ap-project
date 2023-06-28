#ifndef BUY_H
#define BUY_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class buy;
}

class buy : public QDialog
{
    Q_OBJECT

public:
    explicit buy(QMainWindow*previousWindow,QWidget *parent = nullptr);
    ~buy();

private slots:
    void on_back_button_clicked();

    void on_buy_2_clicked();

private:
    Ui::buy *ui;
    QMainWindow *prewindow;
};

#endif // BUY_H
