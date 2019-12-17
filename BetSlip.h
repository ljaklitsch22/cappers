//
// Created by Lukas Jaklitsch on 12/3/19.
//

#ifndef CAPPERS_BETSLIP_H
#define CAPPERS_BETSLIP_H

#import "string"

typedef std::string string;

class BetSlip {

private:
    double spread;
    //Team team;
    double juice;
    double betSize;
    double payOut;
    string wagerType;
    int rotNum;

    //default constructor
    BetSlip();

    //constructor
    BetSlip(int spread1, int rotNum1, double juice1, double betSize1, double payOut1, string wagerType1): spread(spread1),
            juice(juice1), betSize(betSize1), wagerType(wagerType1), rotNum(rotNum1){

        juice = juice/100;

        if(juice > 0){
            payOut = betSize * juice;
        }else{
            payOut = betSize / juice;
        }
    }

    // Default Constructor

    // Alt. Constructor

    // Copy Constructor

    // Assignment Operator

    // Destructor

    double getPayout(){return payOut;}

    //

        // add wager size to appropriate team


};


#endif //CAPPERS_BETSLIP_H
