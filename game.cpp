#include "game.h"

#include <cstdlib>

Game::Game(int numberOfclients, std::vector<Player> playervec)
{
    numberOfPlayers=numberOfclients;
    players=playervec;
    whichHand=0;
    whichRound=0;
    gameStatus=true;

}

void Game::sedRound(int round)
{
    whichRound=round;
}

void Game::setHand(int hand)
{
    whichHand=hand;
}

void Game::setGameStatus(bool status)
{
    gameStatus=status;
}

void Game::setFieldCardCode(int code)
{
    fieldCardCode=code;
}

void Game::setUsernameOfCurrentHandStarter(QString username)
{
    usernameOfCurrentHandStarter=username;
}

void Game::setUsernameOfPreviousHandWinner(QString s)
{
    usernameOfPreviousHandWinner=s;
}

void Game::setFaceupCardsCodeInCurrentHand(int code)
{
    faceupCardsCodeInCurrentHand.push_back(code);
}

QString Game::getUsernameOfPreviousHandWinner()
{
    return usernameOfPreviousHandWinner;
}

QString Game::getUsernameOfCurrentHandStarter()
{
    return usernameOfCurrentHandStarter;
}

int Game::getFieldCardCode()
{
    return fieldCardCode;
}

bool Game::getGameStatus()
{
    return gameStatus;
}

int Game::getRound()
{
    return whichRound;
}

int Game::getHand()
{
    return whichHand;
}

int Game::getNumberOfPlayers()
{
    return numberOfPlayers;
}

void Game::manageGame()
{
    for(int round=1;round<=7;round++){
        whichRound=round;
        for(int hand=1;hand<=2*whichRound;hand++){
            whichHand=hand;
            if(whichHand==1){
            }
            else{
                usernameOfCurrentHandStarter=usernameOfPreviousHandWinner;
            }

        }
    }
}

