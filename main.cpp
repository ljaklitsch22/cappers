#include <iostream>
#include "BetSlip.h"
#include "Date.h"
#include "Match.h"
#include "BettingBoard.h"

typedef std::string string;
static const double JUICE = 1.1;
static const double WIN_WAGER_SIZE = 100;

static void betting_roi(double winningPct){
    double winnings = WIN_WAGER_SIZE * winningPct;
    double losings = WIN_WAGER_SIZE * JUICE * (1 - winningPct);

    double profit = winnings - losings;
    double totalMoneyWagered = WIN_WAGER_SIZE * JUICE;

    double roi = profit/totalMoneyWagered;
    std::cout<< "Winning Pct: " << winningPct << "\n"
             << "Return on Investment: " << (roi) << "\n";
}


int main() {
    /*
    std::cout << "Enter a Winnning Percentage" << std::endl;
    double winningPct;
    string check;

    do{
        std::cin >> winningPct;
        betting_roi(winningPct);
        std::cout << "Enter a winnning percentage or press enter to exit" << std::endl;
        std::cin >> check;
    }while(check != "\n" );

    return 0;
     */


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

    //** BB operator= Test **
    BettingBoard bb_NFL(Date(21,12,2019), 16, 451, "NFL");
    BettingBoard bb_NBA(Date(21,12,2019), 6, 501, "NBA");
    bb_NFL.printBoard();
    bb_NBA.printBoard();

    bb_NFL = bb_NBA;

    bb_NFL.printBoard();
    //bb_NBA.printBoard();










    // Get the starting card nums each week, enter the sport,
     // enter the date,
     // create a bettingboard ->

     //singleton to for each nfl betting board?


     // ** Run program **
/*
     char quit = 'r';
     bool run = true;

     while(run){

         string sport;
         std::cout<< "Pick a sport"<< std::endl;
         std::cin>>sport;

         //search database a print board for the input sport

         // user selects game and places bet
         //need to update everything in that match

         //Exit Program??
         std::cout<< "Make another bet? or q to quit"<< std::endl;

         //Exit condition
         std::cin>>quit;
         if(quit == 'q'){
             run = false;
         }
     }

     */

}

