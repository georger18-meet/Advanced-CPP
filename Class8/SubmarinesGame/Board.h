#pragma once
#include "Sub.h"
#include <string> 
#include <iostream>
using namespace std;

class Board
{
public:
	Board(string name);

	void BuildBoard();
	void DisplayBoard();

private:
	string name;
	Sub subs[5];
	int board[12][12];
	int subSizes[5] = { 5,4,3,3,2 };

	void GetLocation(int i, int* x, int* y, int* z);
};

