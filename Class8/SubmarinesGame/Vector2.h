#pragma once
struct Vector2
{

public:

	Vector2() { x = 0, y = 0; }

	int GetX() { return x; }
	int GetY() { return y; }

	void SetX(int xVal) { x = xVal; }
	void SetY(int yVal) { y = yVal; }
	void SetXY(int xVal, int yVal) { x = xVal, y = yVal; }

private:

	int x;
	int y;
};

