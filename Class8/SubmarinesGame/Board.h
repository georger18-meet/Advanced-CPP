#pragma once
#include "Sub.h"

class Board
{
public:
	void BuildBoard();

private:
	Sub subs[5];
	int board[12][12];
	int subSizes[5] = { 5,4,3,3,2 };

	void GetLocation(int i, int* x, int* y, int* z);
};

