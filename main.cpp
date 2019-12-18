#include <iostream>
#include "BetSlip.h"
#include "Date.h"
#include "Match.h"
#include "BettingBoard.h"
#include "Database.h"

typedef std::string string;
int main() {

/*
    Date date(01, 01, 0001);
    date.print();

    //year test
    Date date1(02, 01, 0001);

    if(date1 >= date){std::cout<<"Error\n";};

    Date tmp(0,0,0);
    tmp.setToday();

    if(tmp <= date){std::cout<<"Error\n";};
    tmp.print();

     Match bills_pats(453,454, "NFL", Date(21,12,2019, 4));
     Match bills_pats2(453,454, "NFL", Date(21,12,2019, 4));
     Match tex_bucs(451,452, "NFL", Date(21,12,2019, 1));
     BettingBoard bb(Date(21,12,2019), 16, 451, "NFL");

     //bb.printBoard();

     Match tex_bucs2(451,452, "NFL", Date(21,12,2019));
*/

    //** BB operator= Test **
    BettingBoard bb_NFL(Date(21,12,2019), 16, 451, "NFL");
    BettingBoard bb_NBA(Date(21,12,2019), 6, 501, "NBA");

    // Load in the games

    Database db = Database();
    db.addBoard(bb_NBA);
    db.addBoard(bb_NFL);



    // Get the starting card nums each week, enter the sport,
     // enter the date,
     // create a bettingboard ->

     //singleton to for each nfl betting board?


     // ** Run program **

     char quit = 'r';
     bool run = true;

     while(run) {

         //db.main[0].printBoard();
         //db.main[1].printBoard();

         // test database with return and no return
         //search database a print board for the input sport
         //
         int rotNum;
         double betSize;
         double spread;

         char quit = 'r';
         bool run = true;
         string sport;
         while (run) {

             // ** Navigation to bet **
             std::cout << "Pick a sport" << std::endl;
             std::cin >> sport;

             int dy;
             int mn;
             std::cout << "Pick a day" << std::endl; // (dd/mm)
             std::cin >> dy;
             std::cout << "Pick a month" << std::endl; // (dd/mm)
             std::cin >> mn;

             Date date = Date(dy, mn, 2019);

             BettingBoard board = db.getBoard(sport, date);
             std::cout << "Enter rotation #, bet size and spread" << std::endl;
             std::cin >> rotNum;
             std::cin >> betSize;
             std::cin >> spread;

             // ** Place bet **
             board.getMatch(rotNum, date).placeBet(betSize, rotNum, spread);


             // user selects game and places bet
             //need to update everything in that match


             //Exit Program??
             std::cout << "Make another bet? or q to quit" << std::endl;

             //Exit condition
             std::cin >> quit;
             if (quit == 'q') {
                 run = false;
             }
         }
     }
}

