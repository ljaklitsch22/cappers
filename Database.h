//
// Created by Lukas Jaklitsch on 12/17/19.
//

#ifndef CAPPERS_DATABASE_H
#define CAPPERS_DATABASE_H

#include "Match.h"
#include "BettingBoard.h"

class Database{
public:
    // Array of Bettingboards
    BettingBoard * main = nullptr;
    int numBoards = 0;

    void addBoard(const BettingBoard & bb);
    BettingBoard & getBoard(string sport, Date date);
    bool hasBoard(string sport, Date date);


/*
static Database & getInstance()
    {
        static Database instance;
        return instance;
    }
*/
    Database() = default;
};

#endif //CAPPERS_DATABASE_H
