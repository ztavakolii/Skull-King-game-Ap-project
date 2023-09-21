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

    void on_backButton_clicked();

    void on_article_1_clicked();

    void on_article_2_clicked();

    void on_article_3_clicked();

    void on_article_4_clicked();

    void on_article_5_clicked();

    void on_article_6_clicked();

    void on_article_7_clicked();

    void on_article_8_clicked();

    void on_article_9_clicked();

    void on_article_10_clicked();

    void on_article_11_clicked();

    void on_article_12_clicked();

    void on_choose_1_clicked();

    void on_choose_2_clicked();

    void on_choose_3_clicked();

    void on_choose_4_clicked();

    void on_choose_5_clicked();

    void on_choose_6_clicked();

    void on_choose_7_clicked();

    void on_choose_8_clicked();

    void on_choose_9_clicked();

    void on_choose_10_clicked();

    void on_choose_11_clicked();

    void on_choose_12_clicked();

    void on_article_13_clicked();

    void on_article_14_clicked();

    void on_article_15_clicked();

    void on_article_16_clicked();

    void on_article_17_clicked();

    void on_article_18_clicked();

    void on_choose_13_clicked();

    void on_choose_14_clicked();

    void on_choose_15_clicked();

    void on_choose_16_clicked();

    void on_choose_17_clicked();

    void on_choose_18_clicked();

    void on_default_1_clicked();

    void on_default_2_clicked();

private:
    Ui::buy *ui;
    QMainWindow *prewindow;

protected:
    void showEvent(QShowEvent*event);
};

#endif // BUY_H
