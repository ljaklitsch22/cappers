//
// Created by Lukas Jaklitsch on 12/3/19.
//

#include "BetSlip.h"
#include "math.h"

BetSlip::BetSlip(int spread1, int rotNum1, double betSize1, string un, double juice1, string wagerType1)
    : spread(spread1), rotNum(rotNum1), juice(juice1), betSize(betSize1), wagerType(wagerType1), username(un) {

    juice = abs(juice) / 100;

    if (juice > 0) {
        payOut = betSize * juice;
    } else {
        payOut = betSize / juice;
    }
}

