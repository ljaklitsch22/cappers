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

     Match bills_pats(453,454, Date(21,12,2019, 4));

     Match bills_pats2(453,454, Date(21,12,2019, 4));

     Match tex_bucs(451,452, Date(21,12,2019, 1));

     BettingBoard bb(Date(21,12,2019), 16, 451);

     bb.printBoard();


     Match tex_bucs2(451,452, Date(21,12,2019, 1));


}

