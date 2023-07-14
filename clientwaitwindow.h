#ifndef CLIENTWAITWINDOW_H
#define CLIENTWAITWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QByteArray>
#include <QTextStream>
#include <thread>
#include <vector>
#include "playwindow.h"

namespace Ui {
class ClientWaitWindow;
}

class ClientWaitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWaitWindow(QMainWindow*personalWindow,QMainWindow*prewindow,QWidget *parent = nullptr);
    ~ClientWaitWindow();

private:
    Ui::ClientWaitWindow *ui;
    QMainWindow*personalWindow;
    QMainWindow*preWindow;
    //This thread is so that when the client is connected to the server,
    //it can go to other pages, such as its own page, while the server completes.
    std::thread* t;
    struct ClientInformation{
        QString name;
        int cupNumber;
        QPixmap profilePicture;
    };
    std::vector<ClientInformation>connectedClientsToServerList;
  //  PlayWindow*playWindow;
    bool b; //for ui->guideTextEdit


    void sendPlayerInformationToServer();
    void readInformationSentByServer();
    void addNewClientToList(QString clientName,int clientCupNumber,QPixmap clientProfilePicture);
    void showClientListInGUI();

protected:
    void closeEvent(QCloseEvent*event);

private slots:
    void backButtonClicked();
    void disconnectButtonClicked();
    void setSkullKingWords(QString serverName,int serverCapacity);
signals:
    void setguideTextEdit(QString,int);

};

#endif // CLIENTWAITWINDOW_H
