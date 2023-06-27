#ifndef PERSONALWINDOW_H
#define PERSONALWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QLabel>

#include "historywindow.h"
#include"serverorclientwindow.h"
#include "editprofilewindow.h"

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

    // we need a pointer to store window
    HistoryWindow*historyWindow;
    ServerOrClientWindow*serverOrClientWindow;
    EditProfileWindow*editProfileWindow;



private slots:
    void backButtonClicked();
    void storeButtonClicked();// this is doesn't implement
    void historyButtonClicked();
    void playButtonClicked();
    void editProfileButtonClicked();


};
#endif // PERSONALWINDOW_H
