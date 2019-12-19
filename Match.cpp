//
// Created by Lukas Jaklitsch on 12/16/19.
//

#include "Match.h"
#include "BetSlip.h"


//unordered_map<string, int> umap;
//
//    // inserting values by using [] operator
//    umap["GeeksforGeeks"] = 10;

BetSlip Match::placeBet(double betSize, int rotNum, double spread, string username) {
    // confirm game is on the board
    // check rotnum

    // check current date

    // match spread and money amount on opposite side
    // check if sprea exists, retrieve moneyAvail
    // compare it to betSize

    // home.spreads[spread] or home
    // home.spreads[spread*-1] or home

    //Which team is user betting on
    if (rotNum % 2 == 0) { //user is betting on home team
        if (away.spreads.find((spread * -1)) == away.spreads.end()
            || away.spreads[spread*-1] == 0) { // check spread

            //No bets placed on other side of bet yet or 0
            home.spreads[spread] += betSize; //increase funds available on home

            std::cout << "Bet pending..." << std::endl;

        } else { //spread found, check available funds

            // check how much funds
            if (away.spreads.find((spread * -1))->second >= betSize) { //place bet in full
                //place bet in full
                ++home.counter;
                home.moneyTotal += betSize;
                away.spreads[spread*-1] -= betSize;

                std::cout << "Bet Placed successfully" << std::endl;

                // not enough funds for entire bet
            } else {                 // place partial bet
                // assigns the home money avail to whats left on the bet
                // not all of it is placed
                home.spreads[spread] += betSize - away.spreads.find(spread * -1)->second; //
                home.moneyTotal += away.spreads.find(spread * -1)->second;

                // add to queue for when another bet is placed
                std::cout << "Not enough funds to back entire bet" << std::endl;
                std::cout << away.spreads.find(spread * -1)->second << "$ Placed" << std::endl;
                std::cout << "Pending Wager for: $" << betSize - away.spreads.find(spread * -1)->second << std::endl;
                away.spreads[spread*-1]= 0;
                ++home.counter;
            }
        }
    } else { // user is betting on away team
        if (home.spreads.find((spread * -1)) == home.spreads.end()
            || home.spreads.find((spread * -1))->second == 0) { // check spread

            //No bets placed on other side of bet yet or 0
            away.spreads[spread] += betSize; //increase funds available on home

            std::cout << "Bet pending..." << std::endl;

        } else { //spread found, check available funds

            // check how much funds
            if (home.spreads.find((spread * -1))->second >= betSize) { //place bet in full
                //place bet in full
                ++away.counter;
                away.moneyTotal += betSize;
                away.spreads[spread*-1] -= betSize;

                std::cout << "Bet Placed successfully" << std::endl;

                // not enough funds for entire bet
            } else {                 // place partial bet
                // assigns the home money avail to whats left on the bet
                // not all of it is placed
                away.spreads[spread] += betSize - home.spreads.find(spread * -1)->second; //
                away.moneyTotal += home.spreads.find(spread * -1)->second;

                // add to queue for when another bet is placed
                std::cout << "Not enough funds to back entire bet" << std::endl;
                std::cout << home.spreads[spread*-1] << "$ Placed" << std::endl;
                std::cout << "Pending Wager for: $" << betSize - home.spreads.find(spread * -1)->second << std::endl;
                home.spreads[spread*-1] = 0;
                ++away.counter;
            }
        }
    }
    return BetSlip(spread, rotNum, betSize, username);
}


// Default constructor

//Alt. Constructor - takes in rotNums and date,
//maybe add sport too
//
Match::Match(int rotNum1, int rotNum2, string sprt, Date date_tmp)
        : sport(sprt), date(date_tmp){
    away.rotNum = rotNum1;
    home.rotNum = rotNum2;
};

/*
//Match(int rotNum1, int rotNum2, string date_tmp, double spread): rotationNum1(rotNum1), rotationNum2(rotNum2), date(date_tmp) liveSpread(spread){};
// Copy Constructor
Match::Match(const Match& match): rotationNum1(match.rotationNum1), rotationNum2(match.rotationNum2),
            date(match.date), liveSpread(match.liveSpread){};

 */
// Assignment Operator
Match& Match::operator=(const Match & match){
    if(this != & match){

        home = match.home;
        away = match.away;

        liveSpread = match.liveSpread;
        openSpread = match.openSpread;
        const_cast<Date&>(date) = match.date;
    }
    return *this;
};



// Destructor

bool Match::operator==(const Match & match){
    return home.rotNum == match.home.rotNum &&
            away.rotNum == match.away.rotNum && (const_cast<Date&>(date) == match.date);
};

// ** Mutators **
void Match::updateSpread(double spread){liveSpread = spread;};

void Match::setOpenSpread(double spread){openSpread = spread;};
void Match::setHomeTeam(const string &name){home.name = name;};
void Match::setAwayTeam(const string &name){away.name = name;};
//void Match::setGameTime(int time){date.hour = time;};

// ** Mutators **
//int Match::getCardNum(){return rotationNum1 + rotationNum2;};
string Match::getHomeTeam(){return home.name;};
string Match::getAwayTeam(){return away.name;};
double Match::getSpread(){return liveSpread;};
const Date Match::getDate(){return date;};

// ** Accessors **
//double Match::getAwayMoney(){return away.moneyAvail;};
int Match::getAwayCounter(){return away.counter;};
double Match::getAwayPct(){return away.pctOn;};

//double Match::getHomeMoney(){return home.moneyAvail;};
int Match::getHomeCounter(){return home.counter;};
double Match::getHomePct(){return home.pctOn;};


