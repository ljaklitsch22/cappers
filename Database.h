//
// Created by Lukas Jaklitsch on 12/17/19.
//

#ifndef CAPPERS_DATABASE_H
#define CAPPERS_DATABASE_H

#include "Match.h"
#include "BettingBoard.h"

int MAXBOARDS = 20;

class Database{
public:
    // Array of Bettingboards
    BettingBoard * main = nullptr;
    int numBoards = 0;

    void addBoard(const BettingBoard & bb);

    Database() = default;
};

#endif //CAPPERS_DATABASE_H
