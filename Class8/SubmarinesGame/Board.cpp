#include "Board.h"

void Board::BuildBoard()
{
	int rows = sizeof board / sizeof board[0];

	int cols = sizeof board[0] / sizeof(int);

	int subCount = sizeof subs / sizeof subs[0];

	int x, y, d;
	for (int i = 0; i < subCount; i++)
	{
		bool checksOut = false;
		while (!checksOut)
		{
			GetRandSubLocation(&x, &y, &d);
			if (d == 0) // Check Y Out of Bounds
			{
				if (y + subSizes[i] - 1 > rows - 1 || CheckSubInterference(subSizes[i], x, y, d))
				{
					checksOut = false;
				}
				else
				{
					checksOut = true;
				}
			}
			else // Check X Out of Bounds
			{
				if (x + subSizes[i] - 1 > cols - 1 || CheckSubInterference(subSizes[i], x, y, d))
				{
					checksOut = false;
				}
				else
				{
					checksOut = true;
				}
			}
		}
		cout << x << "," << y << "," << d << endl;
		subs[i].BuildSub(subSizes[i], x, y, d);
	}
}

void Board::DisplayBoard()
{
	int rows = sizeof board / sizeof board[0];

	int cols = sizeof board[0] / sizeof(int);

	cout << "Board: " << name << endl;
	for (int y = -1; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (y == -1)
			{
				cout << x << "|";
			}
			else
			{
				Cell* tempCell = nullptr;
				tempCell = CheckIfSubIsAt(x, y);
				// Determine Node State
				if (tempCell != nullptr)
				{
					if (tempCell->GetStatus() == 1)
					{
						cout << "S";
					}
					else if (tempCell->GetStatus() == 2)
					{
						cout << "X";
					}
				}
				else
				{
					cout << ".";
				}

				int spaces = to_string(x).length();
				for (int i = 0; i < spaces; i++)
				{
					cout << " ";
				}
			}
		}
		if (y != -1) cout << "|" << y;
		cout << endl;
	}
	cout << endl;
}

bool Board::AttackPoint(int x, int y)
{
	Cell* tempCell = nullptr;
	tempCell = CheckIfSubIsAt(x, y);

	if (tempCell != nullptr)
	{
		if (tempCell->GetStatus() == 1)
		{
			tempCell->ChangeStatus(2);
			return true;
		}
	}
	return false;
}

void Board::GetRandSubLocation(int* x, int* y, int* z)
{
	int rows = sizeof board / sizeof board[0];

	int cols = sizeof board[0] / sizeof(int);

	*y = rand() % rows;

	*x = rand() % cols;

	*z = rand() % 2;
}

Cell* Board::CheckIfSubIsAt(int xCoordinate, int yCoordinate)
{
	Cell* foundCell = nullptr;

	int subCount = sizeof subs / sizeof subs[0];

	for (int s = 0; s < subCount; s++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (subs[s].GetCells()[c].GetStatus() != 0 && subs[s].GetCells()[c].GetX() == xCoordinate && subs[s].GetCells()[c].GetY() == yCoordinate)
			{
				foundCell = &subs[s].GetCells()[c];
				return foundCell;
			}
		}
	}

	return foundCell;
}

bool Board::CheckSubInterference(int size, int x, int y, int d)
{
	for (int sc = 0; sc < size; sc++)
	{
		if (d == 0) // Check Y Interference
		{
			if (CheckIfSubIsAt(x, y + sc) != nullptr)
			{
				return true;
			}
		}
		else // Check X Interference
		{
			if (CheckIfSubIsAt(x + sc, y) != nullptr)
			{
				return true;
			}
		}
	}

	return false;
}
