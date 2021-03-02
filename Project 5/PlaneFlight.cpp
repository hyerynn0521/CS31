//
//  PlaneFlight.cpp
//  Project 5
//
//  Created by Hyerin Lee on 2/20/21.
//

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;
#include <string>
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage){
    
    if(passengerName != ""){
        mName = passengerName;
    }
    
    if(fromCity != "" && fromCity != toCity){
        mFromCity = fromCity;
    }
    if(toCity != "" && fromCity != toCity){
        mToCity = toCity;
    }
    
    if(cost >= 0){
        mCost = cost;
    }
    if(cost < 0){
        mCost = -1;
    }
    if(mileage > 0){
        mMileage = mileage;
    }
    
    if(mileage <= 0){
        mMileage = -1;
    }
}
double PlaneFlight::getCost(){
    return mCost;
}
void PlaneFlight::setCost(double cost){
    if(cost >= 0){
        mCost = cost;
    }
    else if (cost<0){
        mCost = -1;
    }
}

double PlaneFlight::getMileage(){
    return mMileage;
}
void PlaneFlight::setMileage(double mileage){
    if(mileage > 0){
        mMileage = mileage;
    }
    else{
        mMileage = -1;
    }
}

string PlaneFlight::getName(){
    return mName;
}
void PlaneFlight::setName(string name){
    if(name != ""){
        mName = name;
    }
}

string PlaneFlight::getFromCity(){
    return mFromCity;
}
void PlaneFlight::setFromCity(string from){
    if(from != "" && from != mToCity){
        mFromCity = from;
    }
}

string PlaneFlight::getToCity(){
    return mToCity;
}
void PlaneFlight::setToCity(string to){
    if(to != "" && to != mFromCity){
        mToCity = to;
    }
}
//setToCity2 and setFromCity 2 is only used in the freeFlight() function so desired fromCity and toCity can be changed as long as the parameter from and to is not the same without the restriction in original setToCity and setFromCity functions
void PlaneFlight::setToCity2(string to){
    if(to != "" ){
        mToCity = to;
    }
}
void PlaneFlight::setFromCity2(string from){
    if(from != "" ){
        mFromCity = from;
    }
}
