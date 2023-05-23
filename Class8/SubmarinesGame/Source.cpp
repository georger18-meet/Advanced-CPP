#include <iostream>

#include "board.h"

using namespace std;

void Guess(bool t) {

}

void ShowWinner() {

}

int main()
{
    Board b1, b2;
    bool win = false;
    bool turn = false;

    b1.BuildBoard();
    b2.BuildBoard();
    while (!win) {
        Guess(turn);
        turn = !turn;
    }
    ShowWinner();

    return 0;
}