// Created by Lukas Jaklitsch on 12/16/19.
//
// holds all the betting cards, done before running the program

#include "Database.h"


// private constructor to force use of
// getInstance() to create Singleton object


void Database::addBoard(const BettingBoard &bb) {
    if(main == nullptr){
        main = new BettingBoard[20];
    }
        main[numBoards] = bb;
        ++numBoards;
}

BettingBoard & Database::getBoard(string sport, Date date){

        for (int i = 0; i < numBoards; ++i) {
            if (main[i].sport == sport && main[i].date == date) {
                main[i].printBoard();
                return main[i]; // or just print
            }
        }
        std::cout << "Board not available. Press q to quit. Or Enter another date." << std::endl;

        // What to return if user quits. needs to be a board
}



