//
//  main.cpp
//  Project 4
//
//  Created by Hyerin Lee on 2/8/21.
//  UID: 305 567 859

#include <iostream>
#include <string>
using namespace std;

int locateMaximum( const  string  array[ ],  int  n );//done
bool isItFloatingPointValue(string n);//done
int countFloatingPointValues( const string array[ ], int  n );//done
bool hasNoCapitals( const string array[ ], int n );//done
bool identicalValuesTogether( const string array[ ], int n);//done
bool hasTwoOrMoreDuplicates( const string array[ ], int  n );//done
int shiftLeft( string array[ ], int n, int amount, string placeholder );//done
int replaceFirstAndLastOccurrences( string array[ ], int n, char charToFind, char charToReplace );//done
int firstOccurence(string s, char charToFind);//done
int lastOccurence(string s, char charToFind);//done


int main() {
    string data[5] = { "mamaBbcca", "mamaBbcca", "foo", "98.76", "tyrion" };
    string array[4] ={"AAA", "ABA", "ACAAA", "zzzzzA"};
    string test[5] = { "A", "B", "C", "B", "C"};
    string test2[5] = {"a", "a", "foo", "c", "b"};
    string rand[4] = {"A", "Basdfads", "Casddasdf", "Casddasdf"};
    string test1[5] = {"b", "b", "b", "a", "a" };
    string s = "xyz";
    string b = "xyzz";
    //bool a = s<b;
    //cout << a << endl;
    //int result = countFloatingPointValues(data, 5);
    //bool result = isItFloatingPointValue("12.40");
    //int result = replaceFirstAndLastOccurrences( array, 4, 'A', 'z');
    //bool result = hasTwoOrMoreDuplicates( test, 5 );
    bool result = identicalValuesTogether( test1, 5 );
    //int result = shiftLeft( data, 5, 2, "foo" );
    //int result = locateMaximum( rand, 4 );
    cout << result << endl;
    
    /*for (int i = 0; i<5; i++){
        cout << data[i] << endl;
    }
     */
    
    
}

bool identicalValuesTogether( const string array[ ], int n){
    if(n<=0){
        return false;
    }
    int count = 0;
    string current, compare;
    //this boolean indicates whether another identical value was found that was not next to the first identical value
    bool diffValue = false;
    for(int i = 0; i<n; i++){
        current = array[i];
        count = 0;
        diffValue = false;
        for(int j = 0; j<n; j++){
            compare = array[j];
            
            if(current == compare){
                count ++;
                //if identical value has been found again and there's been a different value found before
                if(count >1 && diffValue == true){
                    return false;
                }
                
            }
            //if the identical value was found at least once and the next value is different
            else if(current != compare && count > 0){
                //change the boolean to indicate there's another value between identical values
                diffValue = true;
            }
            
        }
    }
    return true;
}

int shiftLeft( string array[ ], int n, int amount, string placeholder ){
    if(n<= 0 || amount<0){
        return -1;
    }
    string first = "";
    string last = "";
    int count = 0;
    for(int i = 0; i<amount; i++){
        
        for(int j = 0; j<n; j++){
            first = array[0];
            if(j == 0){
                //if the first element (which is going to be the last element after the shift) is not the same as placeholder, increment the times placeholder was used
                if(first != placeholder){
                    count ++;
                }
            }
            if(j<n-1){
                //the next element becomes current element
                array[j] = array[j+1];
            }
            else if(j == n-1){
                //first element becomes the last element of array
                array[j] = first;
                last = array[j];
            }
        }
        //replace last element with placeholder
        array[n-1] = placeholder;
    }
    return count;
}


int locateMaximum( const  string  array[ ],  int  n ){
    if (n <= 0){
        return -1;
    }
    //initially set first value and index as max
    string max = array[0];
    int maxIndex = 0;
    //compare starting from the second value of array(since first was set to max)
    for(int i = 1; i<n; i++){
        // if current element is bigger than the max
        if(array[i] > max ){
            //set current element to max value, and current index to max index
            max = array[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}


bool hasTwoOrMoreDuplicates( const string array[ ], int  n ){
    if(n <=0){
        return false;
    }
    string current, compare;
    int count = 0;
    string diff = "";
    bool diffFound = false;
    for(int i = 0; i<n; i++){
        current = array[i];
        count = 0;
        //compare current value in index i to all values of the array
        for(int j = 0; j<n; j++){
            
            compare = array[j];
            
            if(current == compare){
                count++;
            }
            //at the last cycle of the loop
            if(j == n-1){
                //if there's a pair of elements and there no other pair of different value was found
                if(count == 2 && diffFound == false){
                    //indicate that a pair has been found
                    diff = array[i];
                    diffFound = true;
                }
                //if there is another pair of different value from the first one
                else if(count == 2 && array[i] != diff && diffFound == true){
                    return true;
                }
            }
            
            
        }
        //or if theres 3 or more identical values
        if(count>2){
            return true;
        }
        
    }
    return false;
}

bool isItFloatingPointValue(string s){
    int dotCount = 0;
    for(int i = 0; i<s.size(); i++){
        char currChar = s.at(i);
        //if a current character is something other than . or a number, return false
        if(!isdigit(currChar) && currChar != '.'){
            return false;
        }
        //count the dots to make sure there is only one
        else if(currChar == '.'){
            dotCount ++;
        }
        
    }
    if(dotCount>1){
        return false;
    }
    return true;
}

int countFloatingPointValues( const string array[ ], int  n ){
    if (n <= 0){
        return -1;
    }
    bool result;
    int floatCount = 0;
    for(int i = 0; i<n; i++){
        string current = array[i];
        result = isItFloatingPointValue(current);
        //if a current value is a float, increment float count
        if(result == true){
            floatCount ++;
        }
    }
    return floatCount;
}

bool hasNoCapitals( const string array[ ], int n ){
    if(n <= 0){
        return true;
    }
    for(int i = 0; i<n; i++){
        string current = array[i];
        //for each value, go over each character of the value
        for(int j = 0; j<current.length(); j++){
            char currChar = current.at(j);
            //if any character is a capital letter, return false
            if(currChar>='A' && currChar <= 'Z'){
                return false;
            }
        }
    }
    return true;
}

int replaceFirstAndLastOccurrences( string array[ ], int n, char charToFind, char charToReplace ){
    if(n<=0){
        return -1;
    }
    int total = 0;
    int first = 0;
    int last = 0;
    for(int i = 0; i<n; i++){
        string current = array[i];
        //for each value in array, find the first and last index where charToFind occurs
        first = firstOccurence(array[i], charToFind);
        last = lastOccurence(array[i], charToFind);
        //if index value found is valid
        if(first != -1 && last != -1){
            //set the character at the found indices to charToReplace
            array[i].at(first) = charToReplace;
            array[i].at(last) = charToReplace;
            //if there is only one charToFind in current value, add one to the total (only one occurrence of charToFind in a value)
            if(first == last){
                
                total += 1;
            }
            //if first and last were found and last is bigger, add 2 to total (two occurrence of charToFind in a value)
            else if(first < last){
                total += 2;
            }
        }
    }
    
    return total;
}

int firstOccurence(string s, char charToFind){
    
    for (int i = 0; i<s.size(); i++){
        char currChar = s.at(i);
        //return the first character found that matches charToFind
        if(currChar == charToFind){
            return i;
        }
    }
    return -1;
}

int lastOccurence(string s, char charToFind){
    int last = -1;
    for(int i = 0; i<s.size(); i++){
        char currChar = s.at(i);
        //every time a character matches charToFind, update last to i, the current index
        if(currChar == charToFind){
            last = i;
        }
    }
    return last;
}
 

