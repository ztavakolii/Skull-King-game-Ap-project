#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QPixmap>
#include <vector>
#include <QTcpSocket>

class Player
{
public:
    Player();
    Player(QString s,QPixmap im,int cupsnumber); // s is username and im is profile image
    void setName(QString s);
    void setProfile(QPixmap picture);
    void setScoreIncreament(int increament);
    void setNumberOfHandsSaidWon(int number);
    void setNumberOfHandsWonInCurrentRoundTOZero();
    void setNumberOfHandsWonInCurrentRoundIncreament();
    void setcupsNumber(int number);
    void setScore(int score);
    void increaseScoreAtEndEachRound();
    void setCards(std::vector<QString>cardsSet);
    void setWhichRound(int numberOfRound);
    void setSocket(QTcpSocket* clientSocket);
    QString getName();
    QPixmap getProfile();
    int getScore();
    int getNumberOfHandsSaidWon();
    int getCupsNumber();
    std::vector<QString> getCasrdsSet();
    QTcpSocket*getSocket();
    void clearCardsVector();
    int getNumberOfHandsWonInCurrentRound();

private:

    QString Name;
    QPixmap profile; //player profile image
    int score; //the score of player in current game
    int cupsNumber;
    int numberOfHandsSaidWon; //the number of hands that player promise to won in each round
    int numberOfHandsWonInCurrentRound;
    std:: vector<QString>cards; // the list of player's carts in each round
    int durationOfDisconnectFromServer; //the time elapsed from the disconnect moment from server
    int whichRound;
    QTcpSocket*socket;

};

#endif // PLAYER_H
