#include <iostream>
#include "BetSlip.h"
#include "Date.h"
#include "Match.h"
#include "BettingBoard.h"
#include "Database.h"
#include "PendingQueue.h"
#include <tuple>

string SPORTS [6] = {"NFL", "NBA", "MLB", "NHL", "CFB", "CBB"};

static void printArray(string tmp[]){
    int i;
    size_t z = sizeof(tmp)/ sizeof(tmp[0]);

    for(i = 0; i < 5; ++i){
        std::cout<< tmp[i] << ", ";
    }
    std::cout<< tmp[i] << std::endl;
}

typedef std::string string;

int main() {

    // Database, back end
    PendingQueue pendingBets = PendingQueue();

    BettingBoard bb_NFL(Date(21,12,2019), 16, 451, "NFL");
    BettingBoard bb_NBA(Date(21,12,2019), 6, 501, "NBA");

    // Load in the games
    Database db = Database();
    db.addBoard(bb_NBA);
    db.addBoard(bb_NFL);


    // What the user experiences

    //** Sign IN**
    string username;
    std::cout<< "Enter a Username"<< std::endl;
    std::cin>>username;

    // Get the starting card nums each week, enter the sport,
     // enter the date,
     // create a bettingboard ->

     //singleton to for each nfl betting board?


     // ** Run program **

         // test database with return and no return
         //search database a print board for the input sport


         int rotNum;
         double betSize;
         double spread;

         string quit = "r";
         string sport;

         while (quit != "q"){

             // ** Navigation to bet **
             std::cout << "Pick a sport" << std::endl;
             printArray(SPORTS);

            std::cin >> sport; //
             transform(sport.begin(), sport.end(), sport.begin(), ::toupper);
             // check if entered sport is available
             string *spt = std::find(std::begin(SPORTS), std::end(SPORTS), sport);
            // When the element is not found, std::find returns the end of the range

             while (spt == std::end(SPORTS)) {
                 std::cout << "Enter a valid sport " << std::endl;
                 std::cin >> sport;
                 transform(sport.begin(), sport.end(), sport.begin(), ::toupper);
                 spt = std::find(std::begin(SPORTS), std::end(SPORTS), sport);
             }


             int dy;
             int mn;
             std::cout << "Pick a day" << std::endl; // (dd/mm)
             std::cin >> dy;
             std::cout << "Pick a month" << std::endl; // (dd/mm)
             std::cin >> mn;

             Date date = Date(dy, mn, 2019);

             BettingBoard board = db.getBoard(sport, date);
             std::cout << "Enter rotation #" << std::endl;
             std::cin >> rotNum;
             // fix this so its one bool call
             while(!(board.onBoard(board.getMatch(rotNum, date)))){
                 std::cout<<"Please select an available game"<<std::endl;
                 board.printBoard();
                 std::cin>>rotNum;
             }

             // Make sure user has enough funds
             std::cout << "Enter bet size" << std::endl;
             std::cin >> betSize;


             std::cout << "Enter spread" << std::endl;
             std::cin >> spread;

             // ** Place bet **
             BetSlip slip = board.getMatch(rotNum, date).placeBet(betSize, rotNum, spread, username);
             pendingBets.enqueue(slip);

             // user selects game and places bet
             //need to update everything in that match

             //Exit Program??
             std::cout << "Make another bet? or q to quit" << std::endl;
             //Exit condition
             std::cin >> quit;
         }
}


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

