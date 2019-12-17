//
// Created by Lukas Jaklitsch on 12/16/19.
//

#include "Match.h"


bool Match::placeBet(double betSize, int rotationNum){

    //match rotation cardNum

    // check balance
    /*
    if(betSize > rotationNum1.moneyBet){
        // place what is left that's on moneyBet's side

        // add wager size to appropriate team
        if(rotationNum == rotationNum1.rotationNum){
            rotationNum1.moneyBet += rotationNum2.moneyBet;
        }else{
            rotationNum2.moneyBet += rotationNum2.moneyBet;
        }

    }else{ // there are sufficient funds for the liability of the bet so it can be placed
        if(rotationNum == rotationNum1.rotationNum){
            rotationNum1.moneyBet += betSize;
        }else{
            rotationNum2.rotationNum += betSize;
        }
    }
     */

    // Update what needs to be

    // Print "pending" if there is not matching money on the other side

    // Print "Success" if there is enoguh money to take on the bet

    return false;

}

// Default constructor


//Alt. Constructor - takes in rotnums and date,
//maybe add sport too
//
Match::Match(int rotNum1, int rotNum2, string sprt, Date date_tmp)
        : rotationNum1(rotNum1), rotationNum2(rotNum2), sport(sprt), date(date_tmp){};

/*
//Match(int rotNum1, int rotNum2, string date_tmp, double spread): rotationNum1(rotNum1), rotationNum2(rotNum2), date(date_tmp) liveSpread(spread){};
// Copy Constructor
Match::Match(const Match& match): rotationNum1(match.rotationNum1), rotationNum2(match.rotationNum2),
            date(match.date), liveSpread(match.liveSpread){};

 */
// Assignment Operator
Match& Match::operator=(const Match & match){
    if(this != & match){
        rotationNum1 = match.rotationNum1;
        rotationNum2 = match.rotationNum2;
        liveSpread = match.liveSpread;
        homeMoney = match.homeMoney;
        awayMoney = match.awayMoney;
        homeCounter = match.homeCounter;
        awayCounter = match.awayCounter;
        pctHome = match.pctHome;
        pctAway = match.pctAway;
        homeName = match.homeName;
        awayName = match.awayName;
        openSpread = match.openSpread;
        const_cast<Date&>(date) = match.date;
    }
    return *this;
};



// Destructor

bool Match::operator==(const Match & match){
    return rotationNum1 == match.rotationNum1 &&
            rotationNum2 == match.rotationNum2 && (const_cast<Date&>(date) == match.date);
};

// ** Mutators **
void Match::updateSpread(double spread){liveSpread = spread;};

void Match::setOpenSpread(double spread){openSpread = spread;};
void Match::setHomeTeam(const string &name){homeName = name;};
void Match::setAwayTeam(const string &name){awayName = name;};
//void Match::setGameTime(int time){date.hour = time;};

// ** Mutators **
int Match::getCardNum(){return rotationNum1 + rotationNum2;};
string Match::getHomeTeam(){return homeName;};
string Match::getAwayTeam(){return awayName;};
double Match::getSpread(){return liveSpread;};
const Date Match::getDate(){return date;};

// ** Accessors **
double Match::getAwayMoney(){return awayMoney;};
double Match::getHomeMoney(){return homeMoney;};
int Match::getAwayCounter(){return awayCounter;};
int Match::getHomeCounter(){return homeCounter;};
double Match::getHomePct(){return pctHome;};
double Match::getAwayPct(){return pctAway;};

const Match Match::getMatch(){return *this;};
