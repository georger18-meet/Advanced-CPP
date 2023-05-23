#pragma once

class Cell
{
public:
	void SetPos(int x, int y);
	void ChangeStatus(int value);

	int GetX() { return posX; }
	int GetY() { return posY; }
	int GetStatus() { return status; }

private:
	int posX;
	int posY;
	int status;
};

