//
//  main.cpp
//  Project 3
//
//  Created by Hyerin Lee on 1/25/21.
//  UID: 305 567 859

#include <iostream>
#include <cctype>
#include <string>
#include <cassert>

using namespace std;

bool isValidResultString(string results);
int negativeTests(string results);
int positiveTests(string results);
int totalTests(string results);
int batches(string results);
bool totalEqualsNegPos(string results);
int extractNumber(string commands, size_t index, bool isValid );
string negativePositiveFirst(string results);

int main() {
    // insert code here...
    string test = "      ";
    //bool result =isValidResultString(test);
    //int result = totalTests(test);
    //int result = positiveTests(test);
    int result = negativeTests(test);
    //int result = negPosTotal(test);
    //bool totalTest = totalEqualsNegPos(test);
    //string result = negativePositiveFirst(test);
    //bool result = totalEqualsNegPos(test);
    cout << result << endl;
    //cout << result2 << endl;
    //cout << totalTest << endl;
    
    return 0;
}

bool isValidResultString(string results){
    //if first character is not R, return false
    if(results.at(0)!='R'){
        return false;
    }
    //if string input is less than the minimum required number of characters(=6), return false
    else if(results.length()<6){
        return false;
    }
    //if total cases starts with 0, return false
    else if(results.at(1) == '0'){
        return false;
    }
    
    char previousChar;
    char nextChar;
    int plusCount = 0;
    int minusCount = 0;
    size_t rIndex = 0;
    
    for(size_t i = 1; i<results.length();i++){
        char currChar = results.at(i);
        if(i < results.length()-1){
            nextChar = results.at(i+1);
            previousChar = results.at(i-1);
            //if character after + or - is zero and there are other digits after the zero character, return false
            if (currChar =='0' && (previousChar == '+' ||previousChar == '-') &&isdigit(nextChar)){
                    return false;
            }
            else if(currChar == '+'){
                // if character before + is not a digit, return false
                if(!isdigit(previousChar)){
                    return false;
                }
                //if there was already a + character within the same batch, return false
                else if(plusCount != 0){
                    return false;
                }
                //increment plus count
                plusCount ++;
            }
            else if(currChar == '-'){
                //if character before - is not a digit, return false
                if(!isdigit(previousChar)){
                    return false;
                }
                //if there was already a - character within the same batch, return false
                else if(minusCount != 0){
                    return false;
                }
                //increment minus count
                minusCount ++;
            }
            //if we have reached a new batch
            else if(currChar == 'R'){
                //and if the count of + and - sign differs from one in the previous batch, return false;
                if(plusCount != 1 || minusCount != 1){
                    return false;
                }
                //reset the plus count and minus count for new batch
                plusCount = 0;
                minusCount = 0;
                //check if the total equals sum of positive and negative case in the previous batch which starts from rIndex
                bool checkSum = totalEqualsNegPos(results.substr(rIndex, i));
                if(checkSum == false){
                    return false;
                }
                //set rIndex to the current charcter to check when end of string is reached or we get to a new batch
                rIndex = i;
                //if character before or after R is not a digit or character after R is a 0, return false
                if((!isdigit(previousChar) || !isdigit(nextChar))|| nextChar == '0'){
                    return false;
                }
            }
        }
        //when we have reached the last character of the string
        else if (i==results.length()-1){
                //if last char isn't a number, return false
                if(!isdigit(currChar)){
                    return false;
                }
                //if the minus and plus count differs from one in the last batch of the string, return false
                else if(plusCount != 1 || minusCount != 1){
                    return false;
                }
                //if the string is only one batch long (meaning rIndex would be 0)
                else if(rIndex == 0){
                    //check for total = pos+neg
                    bool checkSum = totalEqualsNegPos(results);
                    if(checkSum == false){
                        return false;
                    }
                }
                // if the string was multiple batches long
                else if(rIndex != 0){
                    //check total = pos + neg for the last batch of the string
                    bool checkSum = totalEqualsNegPos(results.substr(rIndex, i));
                    if(checkSum == false){
                        return false;
                    }
                }
        }
    }
    return true;
}

int positiveTests(string results){
    //checks for validity of string
    if(isValidResultString(results) == false){
        return -1;
    }
    size_t startIndex = 0;
    size_t endIndex = 0;
    int positive = 0;
    string positiveString;
    string whichFirst = negativePositiveFirst(results);
    //for each character starting from second character
    for(size_t i = 1; i<results.length();i++){
        char currChar = results.at(i);
        //if current character is R, meaning a new batch, check which sign comes first for that batch
        if(currChar == 'R'){
            //checks which one (+ or -) comes first from the starting index of the new batch
            whichFirst = negativePositiveFirst(results.substr(i, results.length()-1));
        }
        //if positive comes first
        if(whichFirst=="positive"){
            //if current character is + and if i+1 will not overstep the string
            if(currChar == '+'&& i<results.length()-1){
                //set startIndex to the index after the positive sign
                startIndex = i+1;
            }
            //if i is within the limit and next character is -,
            else if(i>=startIndex && i<results.length()-1&&results.at(i+1)=='-'){
                //set current index to end index
                endIndex = i;
                //extracts the positive test case from the result string
                positiveString = results.substr(startIndex, endIndex);
                //add to the total positive
                positive += extractNumber(positiveString, 0, true);
                
            }
        }
        //if negative sign comes first(if positive sign comes last)
        else if(whichFirst=="negative"){
            //if current character is +
            if(currChar == '+'){
                //set start index to the next index
                startIndex = i+1;
                //set end index to the end of the string
                endIndex = results.length()-1;
                //add to the positive
                positiveString = results.substr(startIndex, endIndex);
                //extractNumber() stops after it reaches new batch, so it doesn't go until the end of the string unless it's a last batch
                positive += extractNumber(positiveString, 0, true);
            }
        }
    }
    return positive;
}
int negativeTests(string results){
    //checks for validity of string
    if(isValidResultString(results) == false){
        return -1;
    }
    size_t startIndex = 0;
    size_t endIndex = 0;
    int negative = 0;
    string negativeString;
    string whichFirst = negativePositiveFirst(results);
    //for each character starting from second character
    for(size_t i = 1; i<results.length();i++){
        char currChar = results.at(i);
        //if current character is R, meaning a new batch, check which sign comes first for that batch
        if(currChar == 'R'){
            //checks which one (+ or -) comes first from the starting index of the new batch
            whichFirst = negativePositiveFirst(results.substr(i, results.length()-1));
        }
        //if negative comes first
        if(whichFirst=="negative"){
            //if current character is + and if i+1 will not overstep the string
            if(currChar == '-'&&i<results.length()-1){
                //set startIndex to the index after the negative sign
                startIndex = i+1;
            }
            //if i is within the limit and next character is +,
            else if(i<results.length()-1&&i>=startIndex && results.at(i+1)=='+'){
                //set current index to end index
                endIndex = i;
                //extracts the negative test case from the result string
                negativeString = results.substr(startIndex, endIndex);
                //add to the total negative
                negative += extractNumber(negativeString, 0, true);
                
            }
        }
        //if positive sign comes first(if negative sign comes last)
        else if(whichFirst=="positive"){
            //if current character is -
            if(currChar == '-'){
                //set start index to the next index
                startIndex = i+1;
                //set end index to the end of the string
                endIndex = results.length()-1;
                //add to the negative
                negativeString = results.substr(startIndex, endIndex);
                //extractNumber() stops after it reaches new batch, so it doesn't go until the end of the string unless it's a last batch
                negative += extractNumber(negativeString, 0, true);
            }
        }
    }
    return negative;
}
int totalTests(string results){
    //checks for validity of string
    if(isValidResultString(results) == false){
        return -1;
    }
    size_t startIndex = 0;
    size_t endIndex = 0;
    int total = 0;
    string totalString;
    int firstNext = 0;
    for(size_t i = 0; i<results.length(); i++){
        char currChar = results.at(i);
        
        if(i<results.length()-1){
            char nextChar = results.at(i+1);
            if(currChar == 'R'){
                //total start index is the index of digit that comes after R
                startIndex = i+1;
                //for every new batch, reset firstNext
                firstNext = 0;
            }
            //if next char is + or - and endIndex has not been determined yet for the current batch
            else if(isdigit(currChar)&&(nextChar=='+' || nextChar == '-')&&firstNext ==0){
                //set firstNext to 1 to indicate total end index has been determined
                firstNext = 1;
                //current index is total end index
                endIndex = i;
                totalString = results.substr(startIndex, endIndex);
                //convert extracted string to int and add on to total
                total += extractNumber(totalString, 0, true);
            }
        }
    }
    return total;
}
int batches(string results){
    //checks for validity
    if(isValidResultString(results) == false){
        return -1;
    }
    //default batch count is 0
    int batchCount = 0;
    for(size_t i = 0; i<results.length();i++){
        
        char currChar = results.at(i);
        if(currChar == 'R'){
            //increment batch count every time a character is R, meaning a new batch
            batchCount++;
        }
    }
    return batchCount;
}
bool totalEqualsNegPos(string results){
    int rCount = 0;
    int total = 0;
    int negPosTotal = 0;
    
    size_t totalStartIndex = 0;
    size_t posStartIndex = 0;
    size_t negStartIndex = 0;
    size_t i = 0;
    
    char nextChar;
    //see if which (+ or -) comes first
    string whichFirst = negativePositiveFirst(results);
    for(i = 0; i<results.length(); i++){
        char currChar = results.at(i);
        
        if(i<results.length()-1){
            nextChar = results.at(i+1);
            
            if(currChar == 'R'){
                //reset rCount for every new batch
                rCount = 0;
                //total starts at index after R
                totalStartIndex = i+1;
            }
            else if(isdigit(currChar)&&(nextChar == '+' || nextChar =='-') &&rCount == 0){
                //set rCount to 1 for total end index
                rCount = 1;
                //extract the number part and convert to int
                total = extractNumber(results.substr(totalStartIndex, i), 0, true);
            }
            //if positive sign comes first
            else if(whichFirst== "positive"){
                
                if(currChar == '+'&&isdigit(nextChar)){
                    //positive start index is the next index if current character is + and next character is a digit
                    posStartIndex = i+1;
                    
                }
                else if(currChar == '-'&&isdigit(nextChar)){
                    //starting index for negative is the index after - character
                    negStartIndex = i+1;
                    //extract the number part and conver to int
                    negPosTotal += extractNumber(results.substr(posStartIndex, i-1), 0, true);
                }
                else if(nextChar == 'R'){
                    //if we have reached the end of the batch, extract and add the negative to the negPosTotal
                    negPosTotal += extractNumber(results.substr(negStartIndex, i), 0, true);
                    if(total != negPosTotal){
                        //if the total doesn't equal the sum return false
                        return false;
                    }
                    else if(total == negPosTotal){
                        //if the total equals the sum return true
                        return true;
                    }
                }
            }
            //if negative comes first
            else if(whichFirst== "negative"){
                    
                if(currChar == '+'&&isdigit(nextChar)){
                    //positive start index is the next index if current character is + and next character is a digit
                    posStartIndex = i+1;
                }
                else if(currChar == '-'&&isdigit(nextChar)){
                    //starting index for negative is the index after - character
                    negStartIndex = i+1;
                }
                else if(nextChar == '+'&&isdigit(currChar)){
                    //if next character is + and is a digit, current index is the negative end index
                    negPosTotal += extractNumber(results.substr(negStartIndex, i), 0, true);
                }
                else if(nextChar == 'R'){
                    //if we have reached the end of the batch, extract and add the positive cases
                    negPosTotal += extractNumber(results.substr(posStartIndex, i), 0, true);
                    if(total != negPosTotal){
                        
                        return false;
                    }
                    else if(total == negPosTotal){
                            
                        return true;
                    }
                }
            }
        }
        //or if we have reached the end of the string
        else if(i==results.length()-1){
            
            if(whichFirst == "positive"){
                //if positive comes first, last index is the negative end index
                negPosTotal += extractNumber(results.substr(negStartIndex, i), 0, true);
                if(total != negPosTotal){
                    
                    return false;
                }
                else if(total == negPosTotal){
                    
                    return true;
                }
            }
            else if(whichFirst == "negative"){
                //if negative comes first, last index is the positive end index
                negPosTotal += extractNumber(results.substr(posStartIndex, i), 0, true);
                if(total != negPosTotal){
                    
                    return false;
                }
                else if(total == negPosTotal){
                    
                    return true;
                }
            }
        }
    }
    if(total == negPosTotal){
        return true;
    }
    return false;
}
int extractNumber( string commands, size_t index, bool isValid )
{
 // track the integer value found
 int quantity( 0 );
 // the number can't start with a zero!
 if (commands.at(index) >= '1' && commands.at(index) <= '9')
 {
 // the number should be made up of digits
 while( index < commands.length() &&
 (commands.at(index) >= '0' && commands.at(index) <= '9') )
 {
 // extract one digit and add it to the cumulative value
 // held in quantity "123" ---> 123
 int digit = commands.at( index ) - '0';
 quantity = quantity * 10 + digit;
 index = index + 1;
 }
 }
 // once we run out of digits to consume, the cumulative quantity
 // must not still be zero
 isValid = (quantity != 0);
 return( quantity );
}
string negativePositiveFirst(string results){
    for(size_t i = 0; i<results.length(); i++){
        char currChar = results.at(i);
        //if positive is spotted first return positive
        if(currChar == '+'){
            return "positive";
        }
        //if negative is spotted first return negative
        else if (currChar == '-'){
            return "negative";
        }
    }
    return "inconclusive";
}




