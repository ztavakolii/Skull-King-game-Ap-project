#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QTextStream>
#include <thread>
#include <QTimer>
#include "ui_playwindow.h"
#include "QEventLoop"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QMainWindow*personalwindow,QWidget *parent = nullptr);
    ~PlayWindow();

public slots:
    void startcountdown(int);
    void savedatetime(int);
    void setNumberOfPlayers(int number);
    void set_round(int);
    void set_hand(int hand);
    void showCard(int index,QString cardCode);
    void setPlayersScore();
    void showWinnerOfCurrentHand(QString clientName);
    void showWinnerOfWholeGame(QString clientName);
    void stopCodeReceived(bool b,QString);
    void resumeCodeReceived();
    void youCodeReceived();
    void showExchangeRequest(QString clientName);
    void exchangeReplyReceived(QString clientName);
    void exchangeTwoCard(QString preCard,QString newCard);
    void setPlayersForserverplayer(QByteArray);
    void setScoresForServerPlayer(QByteArray);
   // void rotate_bottle(int);
    void showTurn(int index);
    void setPlayingFieldCardCode(QString cardCode);
    void setIsFirstOne();
    void newRoundStarted();
    void serverplayerWins();
    void on_stop_button_clicked();
    void on_exit_button_clicked();
    void f();
    void on_exchange_button_clicked();
    void on_ok_button_clicked();
    void exitSlot();
    void hideSkullKingWords();
    void setCardsIcon();
    void exitCodeReceived(QString clientName);
    void enterAnAllowedCardToTheGame();
    void check_card(QString);
    void sentNumberOfHandsSaidWon();

private:
    Ui::PlayWindow *ui;
    QTimer* countdowntimer;
    QEventLoop eventLoop;
    int remainingtime;
    int initialvalueofremainingtime;
    std::thread*t;//thread of reading information sent by server if the player become client
    QMainWindow*personalWindow;

    void handle_loop(int);

    void readInformationSentByServer();//for clients
    void start_hand();
  //  void placeLabelsAroundCircle(int,int);
    void listOfplayersReceived();
  //  void show_line_edit();
    void end_of_play();

protected:
    void closeEvent(QCloseEvent*event);

signals:
    void second20Signal();
    void second25Signal();
    void second15Signal();
    void second45Signal();
    void second30Signal();
    void aCardWasselected(QString cardCode);
    void second60Signal();
    void showCardSignal(int index, QString cardCode);
    void stopCodeReceivedSignal(bool b,QString name);
    void youCodeReceivedSignal();
    void setCardsIconSignal();
    void exitCodeReceivedSignal(QString);
    void showExchangeRequestSignal(QString);
    void showWinnerOfCurrentHandSignal(QString);
    void showWinnerOfWholeGameSignal(QString);
    void exchangeReplyReceivedSignal(QString);
    void newRoundStartedSignal();


private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_yesRadioButton_clicked();
    void on_noRadioButton_2_clicked();
    //void on_pushButton_clicked();

protected:
    void showEvent(QShowEvent*event);

};

#endif // PLAYWINDOW_H
