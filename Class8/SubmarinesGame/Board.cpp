#include "Board.h"

Board::Board(string name)
	: name(name)
{
}

void Board::BuildBoard()
{
	int x, y, d;
	for (int i = 0; i < 5; i++)
	{
		GetLocation(subSizes[i], &x, &y, &d);
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
				cout << "~";

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

void Board::GetLocation(int i, int* x, int* y, int* z)
{

}
