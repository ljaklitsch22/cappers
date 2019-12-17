// Created by Lukas Jaklitsch on 12/16/19.
//
// holds all the betting cards, done before running the program

#include "Database.h"


// private constructor to force use of
// getInstance() to create Singleton object


void Database::addBoard(const BettingBoard &bb) {
    if(main == nullptr){
        main = new BettingBoard[MAXBOARDS];
    }
        main[numBoards] = bb;
        ++numBoards;
}


