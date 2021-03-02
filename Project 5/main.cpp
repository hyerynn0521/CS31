//
//  main.cpp
//  Project 5
//
//  Created by Hyerin Lee on 2/20/21.
//

#include <iostream>
#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
using namespace std;

int main() {
    // insert code here...
    PlaneFlight f( "Howard", "LAX", "LAS", 65.00, 285 );
    FrequentFlyerAccount account( "Howard" );
    account.addFlightToAccount( f );
    assert( account.getName() == "Howard" );
    assert( std::to_string( account.getBalance() ) == "285.000000" );
    
    assert( account.canEarnFreeFlight( 285 ) == true );
    string test = std::to_string(account.getBalance());
    cout << test << endl;
    account.freeFlight( "LAS", "LAX", 285, f );
    
    assert( f.getName() == "Howard" );
    assert( f.getFromCity() == "LAS" );
    assert( f.getToCity() == "LAX" );
    assert( f.getCost() == 0 );
    assert( f.getMileage() == 285 );
    string result2 = std::to_string( account.getBalance() );
    cout << result2 << endl;
    
    return 0;
}
