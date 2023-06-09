#include <iostream>
#include <time.h>

#include "board.h"

using namespace std;

string Guess(bool t, Board* b1, Board* b2) 
{
	string tempResult;

	bool wasHit = false;

	int randY = 0;

	int randX = 0;

	if (!t)
	{
		int rows = sizeof b1->GetBoard() / sizeof b1->GetBoard()[0];

		int cols = sizeof b1->GetBoard()[0] / sizeof(int);

		int randY = rand() % rows;

		int randX = rand() % cols;

		wasHit = b1->AttackPoint(randX, randY);

		tempResult = b1->GetName() + " Was Attacked At (" + to_string(randX) + "," + to_string(randY) + ")\n";
	}
	else
	{
		int rows = sizeof b2->GetBoard() / sizeof b2->GetBoard()[0];

		int cols = sizeof b2->GetBoard()[0] / sizeof(int);

		int randY = rand() % rows;

		int randX = rand() % cols;

		wasHit = b2->AttackPoint(randX, randY);

		tempResult = b2->GetName() + " Was Attacked At (" + to_string(randX) + "," + to_string(randY) + ")\n";
	}

	if (wasHit)tempResult += "Was Sub Hit?: True\n";
	else tempResult += "Was Sub Hit?: False\n";

	return tempResult;
}

void ShowWinner() 
{

}

int main()
{
	srand(time(0));


	Board b1("Board 1"), b2("Board 2");
	bool win = false;
	bool turn = false;

	b1.BuildBoard();
	b2.BuildBoard();


	while (!win) {
		system("cls");
		string tempResult = Guess(turn, &b1, &b2);
		turn = !turn;

		b1.DisplayBoard();
		b2.DisplayBoard();

		cout << tempResult << endl;
		cout << "Press Enter to Continue";
		cin.ignore();
	}
	ShowWinner();

	return 0;
}