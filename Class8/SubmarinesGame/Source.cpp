#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>
#include "board.h"

using namespace std;

bool CheckPointAlreadyHit(int x, int y, vector<Vector2> ph)
{
	for (int i = 0; i < ph.size(); i++)
	{
		if (ph[i].GetX() == x && ph[i].GetY() == y)
		{
			return true;
		}
	}
	return false;
}

string Guess(bool t, Board* b1, Board* b2, vector<Vector2> ph1, vector<Vector2> ph2)
{
	string tempResult;

	bool wasHit = false;

	int randY = 0;

	int randX = 0;

	if (t)
	{
		int rows = sizeof b1->GetBoard() / sizeof b1->GetBoard()[0];

		int cols = sizeof b1->GetBoard()[0] / sizeof(int);

		randY = rand() % rows;

		randX = rand() % cols;

		while (CheckPointAlreadyHit(randX, randY, ph1))
		{
			randY = rand() % rows;

			randX = rand() % cols;
		}
		ph1.push_back(Vector2(randX, randY));

		wasHit = b1->AttackPoint(randX, randY);

		tempResult = b1->GetName() + " Was Attacked At (" + to_string(randX) + "," + to_string(randY) + ")\n";
	}
	else
	{
		int rows = sizeof b2->GetBoard() / sizeof b2->GetBoard()[0];

		int cols = sizeof b2->GetBoard()[0] / sizeof(int);

		randY = rand() % rows;

		randX = rand() % cols;

		while (CheckPointAlreadyHit(randX, randY, ph2))
		{
			randY = rand() % rows;

			randX = rand() % cols;
		}
		ph2.push_back(Vector2(randX, randY));

		wasHit = b2->AttackPoint(randX, randY);

		tempResult = b2->GetName() + " Was Attacked At (" + to_string(randX) + "," + to_string(randY) + ")\n";
	}

	if (wasHit)tempResult += "Was Sub Hit?: True\n";
	else tempResult += "Was Sub Hit?: False\n";

	return tempResult;
}

bool CheckWin(Board* b1, Board* b2)
{
	if (b1->CheckAllSubsGone() || b2->CheckAllSubsGone())
	{
		return true;
	}
	return false;
}

void ShowWinner(bool w, bool t, Board* b1, Board* b2)
{
	if (w)
	{
		if (!t)
		{
			cout << b1->GetName() << " Has Won!" << endl;
		}
		else
		{
			cout << b2->GetName() << " Has Won!" << endl;
		}
	}
}

int main()
{
	srand(time(0));


	Board b1("Board 1"), b2("Board 2");
	vector<Vector2> pointsHit1, pointsHit2;
	bool win = false;
	bool turn = true;

	b1.BuildBoard();
	b2.BuildBoard();


	while (!win) {
		system("cls");
		turn = !turn;
		string tempResult = Guess(turn, &b1, &b2, pointsHit1, pointsHit2);

		b1.DisplayBoard();
		b2.DisplayBoard();

		if (!turn) cout << b1.GetName() << "'s Turn" << endl;
		else cout << b2.GetName() << "'s Turn" << endl;
		cout << tempResult << endl;

		//cout << "Press Enter to Continue";
		//cin.ignore();
		this_thread::sleep_for(chrono::milliseconds(10));

		win = CheckWin(&b1, &b2);
	}
	ShowWinner(win, turn, &b1, &b2);

	return 0;
}