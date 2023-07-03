#include "player.h"

Player::Player()
{
    score=0;
    numberOfHandsSaidWon=0;
    numberOfHandsWonInCurrentRound=0;
    durationOfDisconnectFromServer=60;
    whichRound=0;
    cupsNumber=0;
}

Player::Player(QString s,QPixmap im,int cupsnumber) //this class must change
{
    Name=s;
    profile=im;
    score=0;
    numberOfHandsSaidWon=0;
    numberOfHandsWonInCurrentRound=0;
    durationOfDisconnectFromServer=60;
    whichRound=0;
    cupsNumber=cupsnumber;
}

void Player::setName(QString s)
{
    Name=s;
}

void Player::setProfile(QPixmap picture)
{
    profile=picture;
}

void Player::setScoreIncreament(int increament)
{
    score+=increament;
}

void Player::setNumberOfHandsSaidWon(int number)
{
    numberOfHandsSaidWon=number;
}

void Player::setNumberOfHandsWonInCurrentRoundTOZero()
{
    numberOfHandsWonInCurrentRound=0;
}

void Player::setNumberOfHandsWonInCurrentRoundIncreament()
{
    numberOfHandsWonInCurrentRound+=1;
}

void Player::setcupsNumber(int number)
{
    cupsNumber=number;
}

void Player::setScore(int score)
{
    this->score=score;
}

void Player::increaseScoreAtEndEachRound()
{
    if(numberOfHandsSaidWon!=0){
        if(numberOfHandsWonInCurrentRound>=numberOfHandsSaidWon)
            score+=10*numberOfHandsSaidWon;
        else score-=(numberOfHandsSaidWon-numberOfHandsWonInCurrentRound)*10;
    }
    else/* if(numberOfHandsSaidWon==0)*/{
        if(numberOfHandsWonInCurrentRound==0)
            score+=10*whichRound;
        // else score not changed
    }
}

void Player::setCards(std::vector<QString> cardsSet)
{
    cards=cardsSet;
}

void Player::setWhichRound(int numberOfRound)
{
    whichRound=numberOfRound;
}

void Player::setSocket(QTcpSocket *clientSocket)
{
    socket=clientSocket;
}

QString Player::getName()
{
    return Name;
}

QPixmap Player::getProfile()
{
    return profile;
}

int Player::getScore()
{
    return score;
}

int Player::getNumberOfHandsSaidWon()
{
    return numberOfHandsSaidWon;
}

int Player::getCupsNumber()
{
    return cupsNumber;
}

std::vector<QString> Player::getCasrdsSet()
{
    return cards;
}

QTcpSocket *Player::getSocket()
{
    return socket;
}

void Player::clearCardsVector()
{
    cards.clear();
}

int Player::getNumberOfHandsWonInCurrentRound()
{
    return numberOfHandsWonInCurrentRound;
}

