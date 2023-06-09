#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>
#include "board.h"
#include "GameFunctions.h"

using namespace std;

int main()
{
	srand(time(0));

	GameFunctions gf;
	Board b1("Board 1"), b2("Board 2");
	vector<Vector2> pointsHit1, pointsHit2;
	bool win = false;
	bool turn = true;

	b1.BuildBoard();
	b2.BuildBoard();


	while (!win) {
		system("cls");
		turn = !turn;
		string tempResult = gf.Guess(turn, &b1, &b2, pointsHit1, pointsHit2);

		b1.DisplayBoard();
		b2.DisplayBoard();

		if (!turn) cout << b1.GetName() << "'s Turn" << endl;
		else cout << b2.GetName() << "'s Turn" << endl;
		cout << tempResult << endl;

		//cout << "Press Enter to Continue";
		//cin.ignore();
		this_thread::sleep_for(chrono::milliseconds(10));

		win = gf.CheckWin(&b1, &b2);
	}
	gf.ShowWinner(win, turn, &b1, &b2);

	return 0;
}