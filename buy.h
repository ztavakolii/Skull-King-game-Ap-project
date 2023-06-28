#ifndef BUY_H
#define BUY_H

#include <QDialog>

namespace Ui {
class buy;
}

class buy : public QDialog
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = nullptr);
    ~buy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::buy *ui;
};

#endif // BUY_H
