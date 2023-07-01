#ifndef PERSONALWINDOW_H
#define PERSONALWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QLabel>

#include "historywindow.h"
#include"serverorclientwindow.h"
#include "editprofilewindow.h"
#include "buy.h"

namespace Ui {
class PersonalWindow;
}

class PersonalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonalWindow(QMainWindow* prewindow,QWidget *parent = nullptr);
    ~PersonalWindow();

private:
    Ui::PersonalWindow *ui;
    QMainWindow*preWindow;
 //   QFrame*profileFrame;
  //  QLabel*profileLabel;

    buy*Buy;
    HistoryWindow*historyWindow;
    ServerOrClientWindow*serverOrClientWindow;
    EditProfileWindow*editProfileWindow;
    PlayWindow*playwindow;



private slots:
    void backButtonClicked();
    void storeButtonClicked();// this is doesn't implement
    void historyButtonClicked();
    void playButtonClicked();
    void editProfileButtonClicked();


    void on_pushButton_clicked();
};
#endif // PERSONALWINDOW_H
