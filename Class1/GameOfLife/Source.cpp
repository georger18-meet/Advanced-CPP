#include "GameOfLife.h";

int main()
{
    GameOfLife a = GameOfLife();
    a.SwapCell(1, 5);
    a.SwapCell(2, 5);
    a.SwapCell(3, 5);
    a.SwapCell(3, 6);
    a.SwapCell(2, 7);
    a.Display();
    cout << "-------------------\n";
    for (int i = 0; i < 30; i++) {
        a.UpdateField();
        a.Display();
        cout << "-------------------\n";
    }
    return 0;
}