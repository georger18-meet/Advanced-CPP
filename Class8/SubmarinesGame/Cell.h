#pragma once
#include "Vector2.h"

class Cell
{
public:

	Cell() { status = 0; }

	void SetPos(int x, int y);
	void ChangeStatus(int value);

	int GetX() { return coords.GetX(); }
	int GetY() { return coords.GetY(); }
	int GetStatus() { return status; }

private:
	Vector2 coords;
	int status;
};

