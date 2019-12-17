//
// Created by Lukas Jaklitsch on 12/16/19.
//

#ifndef CAPPERS_BETTINGBOARD_H
#define CAPPERS_BETTINGBOARD_H

#include "Match.h"
#include "Date.h"

class BettingBoard{
public:
    Date date; // card date
    int numGames; // # of games on the board for the given week
    Match* board;


    // Constructor
    BettingBoard();

    // Alt. Constructor
    BettingBoard(const Date & date_, int numGames_, int startRotNum);

    // Mutators
    //void setDate(Date date);
    //void setMatch(const Match & match);

    void addMatch(const Match & match);
    bool onBoard(const Match & match);


    // Accessors
    int getNumGames();
    Date getDate();
    Match getMatch(int rotNum, Date date);

    //Print
    void printBoard();
};

#endif //CAPPERS_BETTINGBOARD_H
