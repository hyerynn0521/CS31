//
//  FrequentFlyerAccount.h
//  Project 5
//
//  Created by Hyerin Lee on 2/20/21.
//



#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

#include <string>
#include "PlaneFlight.h"

class FrequentFlyerAccount{
    std::string mName;
    double mBalance;
    
public:
    FrequentFlyerAccount(std::string name);
    
    double getBalance();
    std::string getName();
    
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(std::string from, std::string to, double mileage, PlaneFlight & flight);
    
};

#endif /* FrequentFlyerAccount_h */
