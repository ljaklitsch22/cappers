//
// Created by Lukas Jaklitsch on 12/16/19.
//

#ifndef CAPPERS_BETTINGBOARD_H
#define CAPPERS_BETTINGBOARD_H

#include "Match.h"
#include "Date.h"

class BettingBoard{
public:

    int numGames; // # of games on the board for the given week
    Match* board; // Array that stores matches
    Date date; // card date
    string sport = ""; // NFL, NBA, MLB, NHL, CFB, CBB, OTHER

    // Constructor
    BettingBoard() = default;

    // Alt. Constructor
    BettingBoard(const Date & date_, int numGames_, int startRotNum, string sprt);

    // Assignment Operator
    BettingBoard & operator=(const BettingBoard & bb);

    // Mutators
    //void setDate(Date date);
    //void setMatch(const Match & match);

    void addMatch(const Match & match);


    // Accessors
    int getNumGames();
    Date getDate();
    Match getMatch(int rotNum);
    bool onBoard(const Match & match);
    bool onBoard(int rotNum);


    //Print
    void printBoard();
};

#endif //CAPPERS_BETTINGBOARD_H
