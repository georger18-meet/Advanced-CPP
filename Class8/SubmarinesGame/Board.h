#pragma once
#include "Sub.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Board
{
public:
	Board(string nameVal) { name = nameVal; };

	void BuildBoard();
	void DisplayBoard();

	bool AttackPoint(int x, int y);
	bool CheckAllSubsGone();

	string GetName() { return name; }
	int(&GetBoard())[12][12]{ return board; }

private:
	string name;
	Sub subs[5];
	int board[12][12];
	int subSizes[5] = { 5,4,3,3,2 };

	void GetRandSubLocation(int* x, int* y, int* z);

	Cell* CheckIfSubIsAt(int xCoordinate, int yCoordinate);

	bool CheckSubInterference(int size, int x, int y, int d);
};

