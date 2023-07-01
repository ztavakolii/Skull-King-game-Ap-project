#ifndef EDITPROFILEWINDOW_H
#define EDITPROFILEWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditProfileWindow;
}

class EditProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditProfileWindow(QMainWindow*register_loginwindow,QMainWindow*prewindow ,QWidget *parent = nullptr);
    ~EditProfileWindow();

private:
    Ui::EditProfileWindow *ui;
    QMainWindow*preWindow;
    QMainWindow*register_loginWindow;

private slots:
    void backButtonClicked();
    void changePasswordLineEditMode();
    void deleteAccountButtonClicked();
    void editButtonClicked();
    void cancelButtonClicked();
};

#endif // EDITPROFILEWINDOW_H
