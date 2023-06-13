#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include <vector>

class Player
{
public:
    Player(QString s,QImage im); // s is username and im is profile image
    void setUsername(QString s);
    void setProfile(QImage picture);
    void setScoreIncreament(int increament);
    void setNumberOfHandsSaidWon(int number);
    void setNumberOfHandsWonInCurrentRoundTOZero();
    void setNumberOfHandsWonInCurrentRoundIncreament();
    void increaseScoreAtEndEachRound();
    void setCards(std::vector<int>cardsSet);
    void setWhichRound(int numberOfRound);
    QString getUsername();
    QImage getProfile();
    int getScore();
    int getNumberOfHandsSaidWon();
    std::vector<int> getCasrdsSet();

private:

    QString username;
    QImage profile; //player profile image
    int score; //the score of player in current game
    int numberOfHandsSaidWon; //the number of hands that player promise to won in each round
    int numberOfHandsWonInCurrentRound;
    std:: vector<int>cards; // the list of player's carts in each round
    int durationOfDisconnectFromServer; //the time elapsed from the disconnect moment from server
    int whichRound;

};

#endif // PLAYER_H
