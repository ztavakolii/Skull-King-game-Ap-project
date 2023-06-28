#ifndef CLIENTWAITWINDOW_H
#define CLIENTWAITWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QByteArray>
#include <QTextStream>
#include <thread>
#include <vector>

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

    void sendPlayerInformationToServer();
    void readInformationSentByServer();
    void addNewClientToList(QString clientName,int clientCupNumber/*,QPixmap clientProfilePicture*/);
    void showClientListInGUI();

private slots:
    void backButtonClicked();
    void disconnectButtonClicked();
};

#endif // CLIENTWAITWINDOW_H
