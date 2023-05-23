#include "Cell.h"

void Cell::SetPos(int x, int y)
{
	posX = x;
	posY = y;
}

void Cell::ChangeStatus(int value)
{
	status = value;
}
