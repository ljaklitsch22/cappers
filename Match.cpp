//
// Created by Lukas Jaklitsch on 12/16/19.
//

#include "Match.h"


void Match::placeBet(double betSize, int rotNum, double spread){

    // check balance
    //  make sure there is enough money on Away team to balance
    if(rotNum % 2 == 0){ //user is betting on home team
        if(away.moneyAvail >= betSize){ //there is sufficient funds
            ++away.counter;
            away.moneyTotal += betSize;
            away.moneyAvail -= betSize;

            std::cout<< "Bet Placed successfully"<<std::endl;
        }else{
            away.moneyTotal += away.moneyAvail;
            // add to queue for when another bet is placed
            std::cout<< "Not enough funds to back bet"<<std::endl;
            std::cout<< away.moneyAvail<< "$ Placed"<<std::endl;
            std::cout<<"Pending Wager for: "<< betSize-away.moneyAvail<<std::endl;
            away.moneyAvail = 0;
            ++away.counter;
        }

    }else{ //user betting on away team
        if(home.moneyAvail >= betSize){ //there is sufficient funds
            ++home.counter;
            home.moneyTotal += betSize;
            home.moneyAvail -= betSize;

            std::cout<< "Bet Placed successfully"<<std::endl;

        }else{
            home.moneyTotal += home.moneyAvail;
            // add to queue for when another bet is placed
            std::cout<< "Not enough funds"<<std::endl;
            std::cout<< home.moneyAvail<< "$ Placed"<<std::endl;
            std::cout<<"Pending Wager for: "<< betSize-home.moneyAvail<<std::endl;
            home.moneyAvail = 0;
            ++home.counter;
        }
    }
}

// Default constructor

//Alt. Constructor - takes in rotnums and date,
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
double Match::getAwayMoney(){return away.moneyAvail;};
int Match::getAwayCounter(){return away.counter;};
double Match::getAwayPct(){return away.pctOn;};

double Match::getHomeMoney(){return home.moneyAvail;};
int Match::getHomeCounter(){return home.counter;};
double Match::getHomePct(){return home.pctOn;};


