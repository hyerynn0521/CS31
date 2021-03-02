//
//  FrequentFlyerAccount.cpp
//  Project 5
//
//  Created by Hyerin Lee on 2/20/21.
//

#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
using namespace std;
#include <string>

FrequentFlyerAccount::FrequentFlyerAccount(string name){
    mName = name;
    mBalance = 0;
}
double FrequentFlyerAccount::getBalance(){
    return mBalance;
}
string FrequentFlyerAccount::getName(){
    return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight){
    bool result = false;
    if(flight.getName() == mName){
        if(flight.getCost()>0){
            mBalance += flight.getMileage();
        }
        result = true;
    }
    return result;
}
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage){
    bool result = false;
    if(mileage <= mBalance){
        result = true;
    }
    return result;
}
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight & flight){
    bool result = false;
    if(mileage <= mBalance){
        result = true;
        mBalance -= mileage;
        flight.setCost(0);
        if(from != to){
            flight.setFromCity2(from);
            flight.setToCity2(to);
        }
    }
    return result;
}
