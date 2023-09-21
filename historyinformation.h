#ifndef HISTORYINFORMATION_H
#define HISTORYINFORMATION_H

#include <QString>
#include <QDataStream>
#include <vector>

struct Hand{
    bool isWinTheHand=false;
    QString winnerCard="";
    QString yourCard="";
};

class HistoryInformation
{
    friend QDataStream&operator>>(QDataStream&in,HistoryInformation historyInformationObject);
    friend QDataStream&operator<<(QDataStream&out,HistoryInformation historyInformationObject);

public:
    HistoryInformation();
    void setDate(QString s);
    void setIsWinThePlay(bool b);
    void setRound1(std::vector<Hand> round1);
    void setRound2(std::vector<Hand> round2);
    void setRound3(std::vector<Hand> round3);
    void setRound4(std::vector<Hand> round4);
    void setRound5(std::vector<Hand> round5);
    void setRound6(std::vector<Hand> round6);
    void setRound7(std::vector<Hand> round7);

    QString getDate();
    bool getIsWinThePlay();
    std::vector<Hand>getRound1();
    std::vector<Hand>getRound2();
    std::vector<Hand>getRound3();
    std::vector<Hand>getRound4();
    std::vector<Hand>getRound5();
    std::vector<Hand>getRound6();
    std::vector<Hand>getRound7();

private:
    QString date;
    bool isWinThePlay;
    std::vector<Hand> round1;
    std::vector<Hand> round2;
    std::vector<Hand> round3;
    std::vector<Hand> round4;
    std::vector<Hand> round5;
    std::vector<Hand> round6;
    std::vector<Hand> round7;
};

#endif // HISTORYINFORMATION_H
