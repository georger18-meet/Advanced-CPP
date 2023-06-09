#pragma once
#include<vector>
#include "Board.h"

class GameFunctions
{
public:

	bool CheckPointAlreadyHit(int x, int y, vector<Vector2> ph);

	string Guess(bool t, Board* b1, Board* b2, vector<Vector2> ph1, vector<Vector2> ph2);

	bool CheckWin(Board* b1, Board* b2);

	void ShowWinner(bool w, bool t, Board* b1, Board* b2);

};

