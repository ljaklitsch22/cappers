//
// Created by Lukas Jaklitsch on 12/2/19.
//

#ifndef CAPPERS_BET_PLACEMENT_H
#define CAPPERS_BET_PLACEMENT_H

#import "string"
#include "BetSlip.h"
#include "Capper.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include "stdlib.h"
#include "Date.h"

typedef std::string string;

struct Team{
    int rotNum = 000; //Away
    string name = "";
    double moneyAvail = 0;
    double moneyTotal = 0;
    int counter = 0;  // num times team is picked - make hashing map to match values with spreads
    double pctOn = 0;
};

class Match {

public:
    // User Gives - Must
    const Date date = Date(0,0,0,0); //dd/mm/yyyy
    const string sport = ""; // NFL, NBA, MLB, NHL, CFB, CBB, OTHER
    double liveSpread = 0;
    double openSpread = 0;
    int totalBets = home.counter + away.counter;
    Team home;
    Team away;

    // VARS FOR Alt. Constr. - user updates

    // Default constructor
    Match() = default;

    //Alt. Constructor
    Match(int rotNum1, int rotNum2, string sprt, Date date_tmp);

    //Match(int rotNum1, int rotNum2, string date_tmp, double spread): rotationNum1(rotNum1), rotationNum2(rotNum2), date(date_tmp) liveSpread(spread){};
    // Copy Constructor
    Match(const Match& match) = default;

    // Assignment Operator
    Match & operator=(const Match & match);

    bool operator==(const Match & match);

    // Destructor

    //maybe make return BetSlip
    BetSlip placeBet(double betSize, int rotationNum, double spread, string username);

    // ** Mutators **
    void updateSpread(double spread);

    void setOpenSpread(double spread);
    void setHomeTeam(const string &name);
    void setAwayTeam(const string &name);
    //void setGameTime(int time);

    // ** Accessors **
    //int getCardNum();
    string getHomeTeam();
    string getAwayTeam();
    double getSpread();
    const Date getDate();

    // Needed? Yes or No?
    double getAwayMoney();
    double getHomeMoney();
    int getAwayCounter();
    int getHomeCounter();
    double getHomePct();
    double getAwayPct();
};


#endif //CAPPERS_BET_PLACEMENT_H
