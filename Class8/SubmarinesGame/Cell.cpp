#include "Cell.h"

void Cell::SetPos(int x, int y)
{
	posX = x;
	posY = y;
}

void Cell::ChangeStatus(int value)
{
	status = value; // 0=Invalid 1=Valid 2=Hit
}
