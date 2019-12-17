//
// Created by Lukas Jaklitsch on 12/3/19.
//

#ifndef CAPPERS_CAPPER_H
#define CAPPERS_CAPPER_H

#import "string"
#include "BetSlip.h"


typedef std::string string;

class Capper{

private:

    string username;
    string password;

    double currBalance; //current balance

    int bets; // # of bets placed
    BetSlip pendingBets[0];
    int numPendingBets;
    int betsWon;
    int betsLost;

    // bet history


    // display pending bets


public:

    // Default Constructor

    // Alt. Constructor

    // Copy Constructor

    // Assignment Operator

    // Destructor

    /**
     * bet - lets the capper place a bet
     *     - bet is added to pending wagers
     *
     * @param betSize
     * @param rotNum
     * @param juice
     * @param spread
     * @param wagerType
     */

    void bet(double betSize, int rotNum, int juice, int spread, string wagerType){
        //BetSlip betSlip(spread, rotNum, juice, betSize, wagerType, rotNum);

        // Display payout

        // update bet history
        // charge customers to store their data

        //int i = 0;
        //for(i < numPendingBets; ++i;){}
        //pendingBets[i] = betSlip;

        ++bets;
        //++pendingBets;

        // pending bets and searchBet
        // update the singleton for this game

    }

};

#endif //CAPPERS_CAPPER_H
