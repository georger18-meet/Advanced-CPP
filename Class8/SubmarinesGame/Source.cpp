#include <iostream>
#include <time.h>

#include "board.h"

using namespace std;

void Guess(bool t) {

}

void ShowWinner() {

}

int main()
{
    srand(time(0));


    Board b1("Board 1"), b2("Board 2");
    //bool win = false;
    //bool turn = false;

    b1.BuildBoard();
    b2.BuildBoard();
    
    b1.DisplayBoard();
    b2.DisplayBoard();

    //while (!win) {
    //    Guess(turn);
    //    turn = !turn;
    //}
    //ShowWinner();

    return 0;
}