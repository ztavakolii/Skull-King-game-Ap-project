#include "player.h"

Player::Player(QString s,QImage im)
{
    username=s;
    profile=im;
    score=0;
    numberOfHandsSaidWon=0;
    numberOfHandsWonInCurrentRound=0;
    durationOfDisconnectFromServer=60;
    whichRound=0;
}

void Player::setUsername(QString s)
{
    username=s;
}

void Player::setProfile(QImage picture)
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

void Player::setCards(std::vector<int> cardsSet)
{
    cards=cardsSet;
}

void Player::setWhichRound(int numberOfRound)
{
    whichRound=numberOfRound;
}

QString Player::getUsername()
{
    return username;
}

QImage Player::getProfile()
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

std::vector<int> Player::getCasrdsSet()
{
    return cards;
}

