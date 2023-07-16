#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QMainWindow>

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HistoryWindow(QMainWindow*prewindow,QWidget *parent = nullptr);
    ~HistoryWindow();

private slots:
    void backButtonClicked();

    void on_play1Button_clicked();

    void on_play2Button_clicked();

    void on_play3Button_clicked();

    void on_play4Button_clicked();

    void on_play5Button_clicked();

    void on_play6Button_clicked();

    void on_play7Button_clicked();

    void on_play8Button_clicked();

    void on_play9Button_clicked();

    void on_play10Button_clicked();

    void on_round1Button_clicked();

    void on_round2Button_clicked();

    void on_round3Button_clicked();

    void on_round4Button_clicked();

    void on_round5Button_clicked();

    void on_round6Button_clicked();

    void on_round7Button_clicked();

private:
    Ui::HistoryWindow *ui;
    QMainWindow*preWindow;
};

#endif // HISTORYWINDOW_H
