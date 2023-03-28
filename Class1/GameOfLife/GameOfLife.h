#pragma once
#include <iostream>
#include <vector>
using namespace std;

class GameOfLife
{
public:
	GameOfLife();
	GameOfLife(const unsigned& x, const unsigned& y);
	~GameOfLife();

	void Display();
	void SwapCell(const unsigned& x, const unsigned& y);
	void UpdateField();

private:
	unsigned phase;
	unsigned xMax, yMax;
	unsigned xSize, ySize;
	vector<vector<unsigned>> field;

	unsigned NewValCell(const unsigned& x, const unsigned& y);
};