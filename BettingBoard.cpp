//
// Created by Lukas Jaklitsch on 12/16/19.
//

#include "BettingBoard.h"

// Constructor
BettingBoard::BettingBoard(){};

// Alt. Constructor
BettingBoard::BettingBoard(const Date & date_, int numGames_, int startRotNum):
                date(date_), numGames(numGames_){

    board = new Match[numGames_];

    for(int i = 0; i < numGames_; ++i) {
        board[i] = Match(startRotNum, startRotNum + 1, date);
        startRotNum += 2;
    }
}

// Copy Const

// Assignment Operator

// Mutators
//void BettingBoard::setDate(Date date_tmp){};
//void BettingBoard::setMatch(const Match & match){board[numGames] = match;};
void BettingBoard::addMatch(const Match & match) {

        //check if its in board
        if(!(onBoard(match)) && date == match.date){
            board[numGames] = match;
            ++numGames;
        }

        // Do nothing if its not on board
        std::cout<< "GAME IS ALREADY ADDED\n" <<std::endl;
    }

// returns true if match is contained in the "this" board
bool BettingBoard::onBoard(const Match & match){
    for(int i = 0; i < numGames; ++i){
        if(board[i] == match){
            return true;
        }
    }
    return false;
}

// Accessors
int BettingBoard::getNumGames(){return numGames;};
Date BettingBoard::getDate(){return date;};
Match BettingBoard::getMatch(int rotNum, Date date){return this->board[5];};

//Print
void BettingBoard::printBoard(){
    for(int i = 0; i < numGames; ++i){
        std::cout<< board[i].rotationNum1 << "/" << board[i].rotationNum2 <<std::endl;
    }
};