#pragma once
#include "Cell.h"

class Sub
{
public:
	void BuildSub(int size, int x, int y, int d);

	Cell* GetCells();

private:
	Cell cells[5];
};

