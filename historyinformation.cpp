#include "historyinformation.h"

void HistoryInformation::setIsWinThePlay(bool b)
{
    isWinThePlay=b;
}

void HistoryInformation::setRound1(std::vector<Hand> round1)
{
    this->round1=round1;
}

void HistoryInformation::setRound2(std::vector<Hand> round2)
{
    this->round2=round2;
}

void HistoryInformation::setRound3(std::vector<Hand> round3)
{
    this->round3=round3;
}

void HistoryInformation::setRound4(std::vector<Hand> round4)
{
    this->round4=round4;
}

void HistoryInformation::setRound5(std::vector<Hand> round5)
{
    this->round5=round5;
}

void HistoryInformation::setRound6(std::vector<Hand> round6)
{
    this->round6=round6;
}

void HistoryInformation::setRound7(std::vector<Hand> round7)
{
    this->round7=round7;
}

bool HistoryInformation::getIsWinThePlay()
{
    return isWinThePlay;
}

std::vector<Hand> HistoryInformation::getRound1()
{
    return round1;
}

std::vector<Hand> HistoryInformation::getRound2()
{
    return round2;
}

std::vector<Hand> HistoryInformation::getRound3()
{
    return round3;
}

std::vector<Hand> HistoryInformation::getRound4()
{
    return round4;
}

std::vector<Hand> HistoryInformation::getRound5()
{
    return round5;
}

std::vector<Hand> HistoryInformation::getRound6()
{
    return round6;
}

std::vector<Hand> HistoryInformation::getRound7()
{
    return round7;
}

QDataStream&operator>>(QDataStream&in,HistoryInformation historyInformationObject){
    in>>historyInformationObject.isWinThePlay>>historyInformationObject.round1[0].isWinTheHand>>historyInformationObject.round1[0].winnerCard
        >>historyInformationObject.round1[0].yourCard>>historyInformationObject.round1[1].isWinTheHand>>historyInformationObject.round1[1].winnerCard
        >>historyInformationObject.round1[1].yourCard>>historyInformationObject.round2[0].isWinTheHand>>historyInformationObject.round2[0].winnerCard
        >>historyInformationObject.round2[0].yourCard>>historyInformationObject.round2[1].isWinTheHand>>historyInformationObject.round2[1].winnerCard
        >>historyInformationObject.round2[1].yourCard>>historyInformationObject.round2[2].isWinTheHand>>historyInformationObject.round2[2].winnerCard
        >>historyInformationObject.round2[2].yourCard>>historyInformationObject.round2[3].isWinTheHand>>historyInformationObject.round2[3].winnerCard
        >>historyInformationObject.round2[3].yourCard>>historyInformationObject.round3[0].isWinTheHand>>historyInformationObject.round3[0].winnerCard
        >>historyInformationObject.round3[0].yourCard>>historyInformationObject.round3[1].isWinTheHand>>historyInformationObject.round3[1].winnerCard
        >>historyInformationObject.round3[1].yourCard>>historyInformationObject.round3[2].isWinTheHand>>historyInformationObject.round3[2].winnerCard
        >>historyInformationObject.round3[2].yourCard>>historyInformationObject.round3[3].isWinTheHand>>historyInformationObject.round3[3].winnerCard
        >>historyInformationObject.round3[3].yourCard>>historyInformationObject.round3[4].isWinTheHand>>historyInformationObject.round3[4].winnerCard
        >>historyInformationObject.round3[4].yourCard>>historyInformationObject.round3[5].isWinTheHand>>historyInformationObject.round3[5].winnerCard
        >>historyInformationObject.round3[5].yourCard>>historyInformationObject.round4[0].isWinTheHand>>historyInformationObject.round4[0].winnerCard
        >>historyInformationObject.round4[0].yourCard>>historyInformationObject.round4[1].isWinTheHand>>historyInformationObject.round4[1].winnerCard
        >>historyInformationObject.round4[1].yourCard>>historyInformationObject.round4[2].isWinTheHand>>historyInformationObject.round4[2].winnerCard
        >>historyInformationObject.round4[2].yourCard>>historyInformationObject.round4[3].isWinTheHand>>historyInformationObject.round4[3].winnerCard
        >>historyInformationObject.round4[3].yourCard>>historyInformationObject.round4[4].isWinTheHand>>historyInformationObject.round4[4].winnerCard
        >>historyInformationObject.round4[4].yourCard>>historyInformationObject.round4[5].isWinTheHand>>historyInformationObject.round4[5].winnerCard
        >>historyInformationObject.round4[5].yourCard>>historyInformationObject.round4[6].isWinTheHand>>historyInformationObject.round4[6].winnerCard
        >>historyInformationObject.round4[6].yourCard>>historyInformationObject.round4[7].isWinTheHand>>historyInformationObject.round4[7].winnerCard
        >>historyInformationObject.round4[7].yourCard>>historyInformationObject.round5[0].isWinTheHand>>historyInformationObject.round5[0].winnerCard
        >>historyInformationObject.round5[0].yourCard>>historyInformationObject.round5[1].isWinTheHand>>historyInformationObject.round5[1].winnerCard
        >>historyInformationObject.round5[1].yourCard>>historyInformationObject.round5[2].isWinTheHand>>historyInformationObject.round5[2].winnerCard
        >>historyInformationObject.round5[2].yourCard>>historyInformationObject.round5[3].isWinTheHand>>historyInformationObject.round5[3].winnerCard
        >>historyInformationObject.round5[3].yourCard>>historyInformationObject.round5[4].isWinTheHand>>historyInformationObject.round5[4].winnerCard
        >>historyInformationObject.round5[4].yourCard>>historyInformationObject.round5[5].isWinTheHand>>historyInformationObject.round5[5].winnerCard
        >>historyInformationObject.round5[5].yourCard>>historyInformationObject.round5[6].isWinTheHand>>historyInformationObject.round5[6].winnerCard
        >>historyInformationObject.round5[6].yourCard>>historyInformationObject.round5[7].isWinTheHand>>historyInformationObject.round5[7].winnerCard
        >>historyInformationObject.round5[7].yourCard>>historyInformationObject.round5[8].isWinTheHand>>historyInformationObject.round5[8].winnerCard
        >>historyInformationObject.round5[8].yourCard>>historyInformationObject.round5[9].isWinTheHand>>historyInformationObject.round5[9].winnerCard
        >>historyInformationObject.round5[9].yourCard>>historyInformationObject.round6[0].isWinTheHand>>historyInformationObject.round6[0].winnerCard
        >>historyInformationObject.round6[0].yourCard>>historyInformationObject.round6[1].isWinTheHand>>historyInformationObject.round6[1].winnerCard
        >>historyInformationObject.round6[1].yourCard>>historyInformationObject.round6[2].isWinTheHand>>historyInformationObject.round6[2].winnerCard
        >>historyInformationObject.round6[2].yourCard>>historyInformationObject.round6[3].isWinTheHand>>historyInformationObject.round6[3].winnerCard
        >>historyInformationObject.round6[3].yourCard>>historyInformationObject.round6[4].isWinTheHand>>historyInformationObject.round6[4].winnerCard
        >>historyInformationObject.round6[4].yourCard>>historyInformationObject.round6[5].isWinTheHand>>historyInformationObject.round6[5].winnerCard
        >>historyInformationObject.round6[5].yourCard>>historyInformationObject.round6[6].isWinTheHand>>historyInformationObject.round6[6].winnerCard
        >>historyInformationObject.round6[6].yourCard>>historyInformationObject.round6[7].isWinTheHand>>historyInformationObject.round6[7].winnerCard
        >>historyInformationObject.round6[7].yourCard>>historyInformationObject.round6[8].isWinTheHand>>historyInformationObject.round6[8].winnerCard
        >>historyInformationObject.round6[8].yourCard>>historyInformationObject.round6[9].isWinTheHand>>historyInformationObject.round6[9].winnerCard
        >>historyInformationObject.round6[9].yourCard>>historyInformationObject.round6[10].isWinTheHand>>historyInformationObject.round6[10].winnerCard
        >>historyInformationObject.round6[10].yourCard>>historyInformationObject.round6[11].isWinTheHand>>historyInformationObject.round6[11].winnerCard
        >>historyInformationObject.round6[11].yourCard>>historyInformationObject.round7[0].isWinTheHand>>historyInformationObject.round7[0].winnerCard
        >>historyInformationObject.round7[0].yourCard>>historyInformationObject.round7[1].isWinTheHand>>historyInformationObject.round7[1].winnerCard
        >>historyInformationObject.round7[1].yourCard>>historyInformationObject.round7[2].isWinTheHand>>historyInformationObject.round7[2].winnerCard
        >>historyInformationObject.round7[2].yourCard>>historyInformationObject.round7[3].isWinTheHand>>historyInformationObject.round7[3].winnerCard
        >>historyInformationObject.round7[3].yourCard>>historyInformationObject.round7[4].isWinTheHand>>historyInformationObject.round7[4].winnerCard
        >>historyInformationObject.round7[4].yourCard>>historyInformationObject.round7[5].isWinTheHand>>historyInformationObject.round7[5].winnerCard
        >>historyInformationObject.round7[5].yourCard>>historyInformationObject.round7[6].isWinTheHand>>historyInformationObject.round7[6].winnerCard
        >>historyInformationObject.round7[6].yourCard>>historyInformationObject.round7[7].isWinTheHand>>historyInformationObject.round7[7].winnerCard
        >>historyInformationObject.round7[7].yourCard>>historyInformationObject.round7[8].isWinTheHand>>historyInformationObject.round7[8].winnerCard
        >>historyInformationObject.round7[8].yourCard>>historyInformationObject.round7[9].isWinTheHand>>historyInformationObject.round7[9].winnerCard
        >>historyInformationObject.round7[9].yourCard>>historyInformationObject.round7[10].isWinTheHand>>historyInformationObject.round7[10].winnerCard
        >>historyInformationObject.round7[10].yourCard>>historyInformationObject.round7[11].isWinTheHand>>historyInformationObject.round7[11].winnerCard
        >>historyInformationObject.round7[11].yourCard>>historyInformationObject.round7[12].isWinTheHand>>historyInformationObject.round7[12].winnerCard
        >>historyInformationObject.round7[12].yourCard>>historyInformationObject.round7[13].isWinTheHand>>historyInformationObject.round7[13].winnerCard
        >>historyInformationObject.round7[13].yourCard;

        return in;
}

QDataStream&operator<<(QDataStream&out,HistoryInformation historyInformationObject){

        out<<historyInformationObject.isWinThePlay<<historyInformationObject.round1[0].isWinTheHand<<historyInformationObject.round1[0].winnerCard
            <<historyInformationObject.round1[0].yourCard<<historyInformationObject.round1[1].isWinTheHand<<historyInformationObject.round1[1].winnerCard
            <<historyInformationObject.round1[1].yourCard<<historyInformationObject.round2[0].isWinTheHand<<historyInformationObject.round2[0].winnerCard
            <<historyInformationObject.round2[0].yourCard<<historyInformationObject.round2[1].isWinTheHand<<historyInformationObject.round2[1].winnerCard
            <<historyInformationObject.round2[1].yourCard<<historyInformationObject.round2[2].isWinTheHand<<historyInformationObject.round2[2].winnerCard
            <<historyInformationObject.round2[2].yourCard<<historyInformationObject.round2[3].isWinTheHand<<historyInformationObject.round2[3].winnerCard
            <<historyInformationObject.round2[3].yourCard<<historyInformationObject.round3[0].isWinTheHand<<historyInformationObject.round3[0].winnerCard
            <<historyInformationObject.round3[0].yourCard<<historyInformationObject.round3[1].isWinTheHand<<historyInformationObject.round3[1].winnerCard
            <<historyInformationObject.round3[1].yourCard<<historyInformationObject.round3[2].isWinTheHand<<historyInformationObject.round3[2].winnerCard
            <<historyInformationObject.round3[2].yourCard<<historyInformationObject.round3[3].isWinTheHand<<historyInformationObject.round3[3].winnerCard
            <<historyInformationObject.round3[3].yourCard<<historyInformationObject.round3[4].isWinTheHand<<historyInformationObject.round3[4].winnerCard
            <<historyInformationObject.round3[4].yourCard<<historyInformationObject.round3[5].isWinTheHand<<historyInformationObject.round3[5].winnerCard
            <<historyInformationObject.round3[5].yourCard<<historyInformationObject.round4[0].isWinTheHand<<historyInformationObject.round4[0].winnerCard
            <<historyInformationObject.round4[0].yourCard<<historyInformationObject.round4[1].isWinTheHand<<historyInformationObject.round4[1].winnerCard
            <<historyInformationObject.round4[1].yourCard<<historyInformationObject.round4[2].isWinTheHand<<historyInformationObject.round4[2].winnerCard
            <<historyInformationObject.round4[2].yourCard<<historyInformationObject.round4[3].isWinTheHand<<historyInformationObject.round4[3].winnerCard
            <<historyInformationObject.round4[3].yourCard<<historyInformationObject.round4[4].isWinTheHand<<historyInformationObject.round4[4].winnerCard
            <<historyInformationObject.round4[4].yourCard<<historyInformationObject.round4[5].isWinTheHand<<historyInformationObject.round4[5].winnerCard
            <<historyInformationObject.round4[5].yourCard<<historyInformationObject.round4[6].isWinTheHand<<historyInformationObject.round4[6].winnerCard
            <<historyInformationObject.round4[6].yourCard<<historyInformationObject.round4[7].isWinTheHand<<historyInformationObject.round4[7].winnerCard
            <<historyInformationObject.round4[7].yourCard<<historyInformationObject.round5[0].isWinTheHand<<historyInformationObject.round5[0].winnerCard
            <<historyInformationObject.round5[0].yourCard<<historyInformationObject.round5[1].isWinTheHand<<historyInformationObject.round5[1].winnerCard
            <<historyInformationObject.round5[1].yourCard<<historyInformationObject.round5[2].isWinTheHand<<historyInformationObject.round5[2].winnerCard
            <<historyInformationObject.round5[2].yourCard<<historyInformationObject.round5[3].isWinTheHand<<historyInformationObject.round5[3].winnerCard
            <<historyInformationObject.round5[3].yourCard<<historyInformationObject.round5[4].isWinTheHand<<historyInformationObject.round5[4].winnerCard
            <<historyInformationObject.round5[4].yourCard<<historyInformationObject.round5[5].isWinTheHand<<historyInformationObject.round5[5].winnerCard
            <<historyInformationObject.round5[5].yourCard<<historyInformationObject.round5[6].isWinTheHand<<historyInformationObject.round5[6].winnerCard
            <<historyInformationObject.round5[6].yourCard<<historyInformationObject.round5[7].isWinTheHand<<historyInformationObject.round5[7].winnerCard
            <<historyInformationObject.round5[7].yourCard<<historyInformationObject.round5[8].isWinTheHand<<historyInformationObject.round5[8].winnerCard
            <<historyInformationObject.round5[8].yourCard<<historyInformationObject.round5[9].isWinTheHand<<historyInformationObject.round5[9].winnerCard
            <<historyInformationObject.round5[9].yourCard<<historyInformationObject.round6[0].isWinTheHand<<historyInformationObject.round6[0].winnerCard
            <<historyInformationObject.round6[0].yourCard<<historyInformationObject.round6[1].isWinTheHand<<historyInformationObject.round6[1].winnerCard
            <<historyInformationObject.round6[1].yourCard<<historyInformationObject.round6[2].isWinTheHand<<historyInformationObject.round6[2].winnerCard
            <<historyInformationObject.round6[2].yourCard<<historyInformationObject.round6[3].isWinTheHand<<historyInformationObject.round6[3].winnerCard
            <<historyInformationObject.round6[3].yourCard<<historyInformationObject.round6[4].isWinTheHand<<historyInformationObject.round6[4].winnerCard
            <<historyInformationObject.round6[4].yourCard<<historyInformationObject.round6[5].isWinTheHand<<historyInformationObject.round6[5].winnerCard
            <<historyInformationObject.round6[5].yourCard<<historyInformationObject.round6[6].isWinTheHand<<historyInformationObject.round6[6].winnerCard
            <<historyInformationObject.round6[6].yourCard<<historyInformationObject.round6[7].isWinTheHand<<historyInformationObject.round6[7].winnerCard
            <<historyInformationObject.round6[7].yourCard<<historyInformationObject.round6[8].isWinTheHand<<historyInformationObject.round6[8].winnerCard
            <<historyInformationObject.round6[8].yourCard<<historyInformationObject.round6[9].isWinTheHand<<historyInformationObject.round6[9].winnerCard
            <<historyInformationObject.round6[9].yourCard<<historyInformationObject.round6[10].isWinTheHand<<historyInformationObject.round6[10].winnerCard
            <<historyInformationObject.round6[10].yourCard<<historyInformationObject.round6[11].isWinTheHand<<historyInformationObject.round6[11].winnerCard
            <<historyInformationObject.round6[11].yourCard<<historyInformationObject.round7[0].isWinTheHand<<historyInformationObject.round7[0].winnerCard
            <<historyInformationObject.round7[0].yourCard<<historyInformationObject.round7[1].isWinTheHand<<historyInformationObject.round7[1].winnerCard
            <<historyInformationObject.round7[1].yourCard<<historyInformationObject.round7[2].isWinTheHand<<historyInformationObject.round7[2].winnerCard
            <<historyInformationObject.round7[2].yourCard<<historyInformationObject.round7[3].isWinTheHand<<historyInformationObject.round7[3].winnerCard
            <<historyInformationObject.round7[3].yourCard<<historyInformationObject.round7[4].isWinTheHand<<historyInformationObject.round7[4].winnerCard
            <<historyInformationObject.round7[4].yourCard<<historyInformationObject.round7[5].isWinTheHand<<historyInformationObject.round7[5].winnerCard
            <<historyInformationObject.round7[5].yourCard<<historyInformationObject.round7[6].isWinTheHand<<historyInformationObject.round7[6].winnerCard
            <<historyInformationObject.round7[6].yourCard<<historyInformationObject.round7[7].isWinTheHand<<historyInformationObject.round7[7].winnerCard
            <<historyInformationObject.round7[7].yourCard<<historyInformationObject.round7[8].isWinTheHand<<historyInformationObject.round7[8].winnerCard
            <<historyInformationObject.round7[8].yourCard<<historyInformationObject.round7[9].isWinTheHand<<historyInformationObject.round7[9].winnerCard
            <<historyInformationObject.round7[9].yourCard<<historyInformationObject.round7[10].isWinTheHand<<historyInformationObject.round7[10].winnerCard
            <<historyInformationObject.round7[10].yourCard<<historyInformationObject.round7[11].isWinTheHand<<historyInformationObject.round7[11].winnerCard
            <<historyInformationObject.round7[11].yourCard<<historyInformationObject.round7[12].isWinTheHand<<historyInformationObject.round7[12].winnerCard
            <<historyInformationObject.round7[12].yourCard<<historyInformationObject.round7[13].isWinTheHand<<historyInformationObject.round7[13].winnerCard
            <<historyInformationObject.round7[13].yourCard;

        return out;
}
