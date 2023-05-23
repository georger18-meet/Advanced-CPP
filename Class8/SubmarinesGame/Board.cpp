#include "Board.h"

void Board::BuildBoard()
{
	int x, y, d;
	for (int i = 0; i < 5; i++)
	{
		GetLocation(subSizes[i], &x, &y, &d);
		subs[i].BuildSub(subSizes[i], x, y, d);
	}
}

void Board::GetLocation(int i, int* x, int* y, int* z)
{

}
