//
// Created by Lukas Jaklitsch on 12/3/19.
//

#ifndef CAPPERS_BETSLIP_H
#define CAPPERS_BETSLIP_H

#import "string"

typedef std::string string;

class BetSlip {

public:
    double spread;
    int rotNum;
    double juice;
    double betSize;
    string wagerType;
    string username;

    double payOut;

    //default constructor
    BetSlip() = default;

    //constructor
    BetSlip(int spread1, int rotNum1, double betSize1, string un, double juice1 = -110, string wagerType1 = "string");

    // Default Constructor

    // Alt. Constructor

    // Copy Constructor

    // Assignment Operator

    // Destructor

    double getPayout(){return payOut;}
};


#endif //CAPPERS_BETSLIP_H
