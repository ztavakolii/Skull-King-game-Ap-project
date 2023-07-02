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
    void on_back_button_clicked();

private:
    Ui::HistoryWindow *ui;
    QMainWindow*preWindow;
};

#endif // HISTORYWINDOW_H
