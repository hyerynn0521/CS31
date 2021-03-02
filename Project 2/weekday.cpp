//
//  main.cpp
//  Project 2
//  Name: Hyerin Lee
//  UID: 305 567 859
//  Created by Hyerin Lee on 1/14/21.
//

#include <iostream>
using namespace std;
#include <string>

int main() {
    // insert code here...
    string month;
    bool monthBool = true;
    bool dayBool = true;
    bool yearBool = true;
    
    int day, year, monthCode, centuryCode, yearCode, dayCode, centuryValue;
    cout << "Provide a month: ";
    getline(cin, month);
    
    cout << "Provide a day: ";
    cin >> day;
    cout << "Provide a year: ";
    cin >> year;
    
    //checks the month, making sure day and year is valid
    if(day>0 &&day<=31 &&year>0 && year <=3000 && (month == "January" || month == "October") ){
        
        monthCode = 1;
        if(year%4==0 && year%400 == 0&&month == "January"){
            monthCode -= 1;
        }
    }
    else if((month == "February" || month == "March" || month == "November")&& day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 4;
            if(year%4==0 && year%400 == 0&&month == "February"){
                monthCode -= 1;
            }
    }
    else if((month == "April" || month == "July")&& day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 0;
    }
    else if(month == "May" && day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 2;
    }
    else if(month == "June"&& day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 5;
    }
    else if(month == "August"&& day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 3;
    }
    else if((month == "September" || month == "December")&& day>0 &&day<=31 &&year>0 && year <=3000){
            monthCode = 6;
    }
    //checks which error statements to output (checks in the order of month, day, year)
    else{
        if(month !="January" && month !="February" && month !="March" && month !="April" && month !="May" && month !="June" && month !="July"&& month !="August" && month !="September" && month !="October" && month !="November" && month !="December"){
            cout << "Invalid month!" << endl;
            monthBool = false;
        }
        else if(day<=0 || day >31){
            cout << "Invalid day!" << endl;
            dayBool = false;
        }
        else if(year<=0 || year >3000){
            cout << "Invalid year!" << endl;
            yearBool = false;
        }
    }
        centuryValue = year/100%4;
    //if day and year is valid and month input is also valid, start calculation
    if(day>0 &&day<=31 &&year>0 && year <=3000 && monthBool == true && dayBool == true && yearBool == true){
        if(centuryValue == 0){
            centuryCode = -2;
        }
        else if(centuryValue == 1){
            centuryCode = 3;
        }
        else if(centuryValue == 2){
            centuryCode = 1;
        }
        else if(centuryValue == 3){
            centuryCode = -1;
        }
        yearCode = (year%100)/4 + year%100;
        dayCode = (centuryCode + day + yearCode + monthCode)%7;
        if(dayCode == 0){
            cout << month << " " << day << ", " << year << " was a Sunday!" << endl;
        }
        else if(dayCode == 1 || dayCode == -6){
            cout << month << " " << day << ", " << year << " was a Monday!" << endl;
        }
        else if(dayCode == 2 || dayCode == -5){
            cout << month << " " << day << ", " << year << " was a Tuesday!" << endl;
        }
        else if(dayCode == 3 || dayCode == -4){
            cout << month << " " << day << ", " << year << " was a Wednesday!" << endl;
        }
        else if(dayCode == 4 || dayCode == -3){
            cout << month << " " << day << ", " << year << " was a Thursday!" << endl;
        }
        else if(dayCode == 5 || dayCode == -2){
            cout << month << " " << day << ", " << year << " was a Friday!" << endl;
        }
        else if(dayCode == 6 || dayCode == -1){
            cout << month << " " << day << ", " << year << " was a Saturday!" << endl;
        }
    }
    
    return 0;
}
//challenges i overcame
//figuring out the order of calculation(at first had all the calculations inside the month condition
//finding logical errors(found out I had a spelling error)
//getting the correct error statement to print out (if i check the day first, it will print out "invalide day" first even when the month is the first invalide input
