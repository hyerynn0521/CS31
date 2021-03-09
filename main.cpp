//
//  main.cpp
//  BeatThat
//
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"


void clearScreen( );

int main()
{
    using namespace cs31;
    using namespace std;
    
        Die d1; d1.setValue( 1 );
        Die d2; d2.setValue( 2 );
        Die d3; d3.setValue( 3 );
        Die d4; d4.setValue( 4 );
        Die d5; d5.setValue( 5 );
        Die d6; d6.setValue( 6 );

        BeatThat game;

    game.humanPlay( d6, d2 );
            game.computerPlay( d3, d4 );
            game.endTurn( );
            assert(game.isGameOver() == false);
            assert(game.getBoard().getTurnsLeft() == 4);
            assert(game.getBoard().getHumanRoundsWon() == 1);
            game.humanPlay( d5, d1 );
            game.computerPlay( d3, d4 );
            game.endTurn( );
            game.getBoard().setTurnsLeft(2);
        cout << game.getBoard().getTurnsLeft() << endl;
            game.humanPlay( d5, d2 );
            game.computerPlay( d6, d4 );
            game.endTurn( );
    assert(game.turnsLeft() == 2);
            game.humanPlay( d1, d2 );
            game.computerPlay( d3, d4 );
            game.endTurn( );
            
            game.humanPlay( d5, d4 );
            game.computerPlay( d4, d5 );
            game.endTurn( );
    assert(game.getBoard().didComputerWin() == false);
    assert(game.getBoard().didHumanWin() == false);
    assert(game.isGameOver() == true);
    assert(game.determineGameOutcome( ) == BeatThat::TIEDGAME );
    
    /*using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    BeatThat game;
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;
        
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                game.humanPlay();
                game.computerPlay();
                game.endTurn();
                cout << game.display( message ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.endingMessage() << endl;

    return( 0 );*/
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


