#include "Sub.h"

void Sub::BuildSub(int size, int x, int y, int d)
{
	int cellCount = sizeof cells / sizeof cells[0];

	for (int i = 0; i < cellCount; i++)
	{
		if (i < size)
		{
			if (d) // Horizontal
			{
				cells[i].SetPos(x++, y);
			}
			else // Vertical
			{
				cells[i].SetPos(x, y++);
			}
			cells[i].ChangeStatus(1);
		}
		else
		{
			cells[i].ChangeStatus(0);
		}
	}
}

Cell* Sub::GetCells()
{
	return cells;
}
