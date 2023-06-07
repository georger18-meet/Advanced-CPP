#include "Cell.h"

void Cell::SetPos(int x, int y)
{
	coords.SetX(x);
	coords.SetY(y);
}

void Cell::ChangeStatus(int value)
{
	status = value; // 0=Invalid 1=Valid 2=Hit
}
