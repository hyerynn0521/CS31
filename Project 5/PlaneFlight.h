//
//  PlaneFlight.h
//  Project 5
//
//  Created by Hyerin Lee on 2/20/21.
//
#include <string>
#ifndef PlaneFlight_h
#define PlaneFlight_h


//std::
class PlaneFlight {
    double mCost;
    std::string mFromCity;
    std::string mToCity;
    std::string mName;
    double mMileage;
    
public:
    PlaneFlight(std::string passengerName, std::string fromCity, std::string toCity, double cost, double mileage);
    
    double getCost();
    void setCost(double cost);
    
    double getMileage();
    void setMileage(double mileage);
    
    std::string getName();
    void setName(std::string name);
    
    std::string getFromCity();
    void setFromCity(std::string from);
    
    std::string getToCity();
    void setToCity(std::string to);
    
    void setToCity2(std::string to);
    void setFromCity2(std::string from);
};

#endif /* PlaneFlight_h */
