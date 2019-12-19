//
// Created by Lukas Jaklitsch on 12/16/19.
//

#include "BettingBoard.h"

// Constructor
//BettingBoard::BettingBoard(){};

//returns true if the rotnum is in the board
//bool BettingBoard::checkMatch(int rotnum){}

// Alt. Constructor - football
BettingBoard::BettingBoard(const Date & date_, int numGames_, int startRotNum, string sprt):
                date(date_), numGames(numGames_), sport(sprt){

    board = new Match[numGames_];

    for(int i = 0; i < numGames_; ++i) {
        board[i] = Match(startRotNum, startRotNum + 1, sprt, date);
        startRotNum += 2;
    }
}

// Copy Const

// Assignment Operator
BettingBoard& BettingBoard::operator=(const BettingBoard & bb){
    if(this != & bb){
        BettingBoard tmp(bb);

        std::swap(board, tmp.board);
        numGames = bb.numGames;
        const_cast<Date&>(date) = bb.date;
        sport = bb.sport;
    }
    return *this;
};

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

// returns true if match is contained in the "this" board
bool BettingBoard::onBoard(int rotNum){
    for(int i = 0; i < numGames; ++i){
        if((rotNum == board[i].away.rotNum || rotNum == board[i].home.rotNum)){
            return true;
        }
    }
    return false;
}

// Accessors
int BettingBoard::getNumGames(){return numGames;};

Date BettingBoard::getDate(){return date;};

Match BettingBoard::getMatch(int rotNum){
        for(int i = 0; i < numGames; ++i){
            if((rotNum == board[i].away.rotNum || rotNum == board[i].home.rotNum)){
                return board[i];
            }
        }
    std::cout << "Match not available. Press q to quit. Or Enter another date." << std::endl;
};

//Print
void BettingBoard::printBoard() {

    // Print Sport
    //std::cout << sport << std::endl;

    //Print The board
    for (int i = 0; i < numGames; ++i) {
        std::cout << board[i].away.rotNum << "/" << board[i].home.rotNum<< "\t";
        if (i == 4){
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}