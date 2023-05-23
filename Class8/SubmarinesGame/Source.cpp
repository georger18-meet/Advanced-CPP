#include <iostream>

#include "board.h"

using namespace std;

void guess(bool t) {

}

void showWinner() {

}

int main()
{
    Board b1, b2;
    bool win = false;
    bool turn = false;

    b1.BuildBoard();
    b2.BuildBoard();
    while (!win) {
        guess(turn);
        turn = !turn;
    }
    showWinner();

    return 0;
}