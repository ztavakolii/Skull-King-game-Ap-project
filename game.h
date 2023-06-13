#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <vector>

class Game
{
public:
    Game(int numberOfclients,std::vector<Player>playervec);
    //    void setNumberOfPlayers(int number);
    void sedRound(int round);
    void setHand(int hand);
    void setGameStatus(bool status);
    void setFieldCardCode(int code);
    void setUsernameOfCurrentHandStarter(QString username);
    void setUsernameOfPreviousHandWinner(QString s);
    void setFaceupCardsCodeInCurrentHand(int code);

    QString getUsernameOfPreviousHandWinner();
    QString getUsernameOfCurrentHandStarter();
    int getFieldCardCode();
    bool getGameStatus();
    int getRound();
    int getHand();
    int getNumberOfPlayers();

    void manageGame();

private:
    std::vector<Player>players;
    int numberOfPlayers;
    int whichRound;
    int whichHand;
    bool gameStatus;//this determines that game is stop or not,
        //true means in progress and false meeans that is stoped
    int elapsedSecondsFromStop; //the maximum amount of this variable must be 20s
    int fieldCardCode;//the code of card that first player entered the game
    QString usernameOfCurrentHandStarter;
    QString usernameOfPreviousHandWinner;
    std::vector<int> faceupCardsCodeInCurrentHand;
};

#endif // GAME_H
