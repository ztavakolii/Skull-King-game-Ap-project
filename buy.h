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
//    void on_back_button_clicked();

//    void on_buy_2_clicked();

//    void on_buy_1_clicked();

//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

//    void on_pushButton_5_clicked();

//    void on_pushButton_6_clicked();

//    void on_pushButton_7_clicked();

//    void on_pushButton_8_clicked();

//    void on_pushButton_9_clicked();

//    void on_pushButton_10_clicked();

//    void on_pushButton_11_clicked();

//    void on_pushButton_12_clicked();

//    void on_pushButton_13_clicked();

//    void on_pushButton_14_clicked();

//    void on_pushButton_15_clicked();

//    void on_pushButton_16_clicked();

//    void on_pushButton_17_clicked();

//    void on_pushButton_18_clicked();

//    void on_pushButton_19_clicked();

//    void on_pushButton_20_clicked();

//    void on_pushButton_21_clicked();

//    void on_pushButton_22_clicked();

//    void on_pushButton_23_clicked();

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
