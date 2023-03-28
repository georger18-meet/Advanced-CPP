#include "GameOfLife.h"

// Default Constructor - Generates an Empty Field of Set Size
GameOfLife::GameOfLife()
{
	phase = 0;
	xMax = 10;
	yMax = 10;
	xSize = xMax + 2;
	ySize = yMax + 2;

	for (unsigned i = 0; i != xSize; i++)
	{
		vector<unsigned> inter;
		for (unsigned j = 0; j != ySize; j++)
		{
			inter.push_back(0);
		}
		field.push_back(inter);
	}
}

// Manual Constructor - Generates an Empty Field of Set Size
GameOfLife::GameOfLife(const unsigned& x, const unsigned& y)
{
	phase = 0;
	xMax = x;
	yMax = y;
	xSize = xMax + 2;
	ySize = yMax + 2;

	for (unsigned i = 0; i != xSize; i++)
	{
		vector<unsigned> inter;
		for (unsigned j = 0; j != ySize; j++)
		{
			inter.push_back(0);
		}
		field.push_back(inter);
	}
}

// Destructor
GameOfLife::~GameOfLife()
{
	return;
}

// Prints the Field in the Console with the proper State Value for each Cell
void GameOfLife::Display()
{
	cout << "Phase: " << phase << "\n";
	for (int i = 1; i != xMax + 1; i++)
	{
		for (int j = 1; j != yMax + 1; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

// Switches the State Value of a Given Cell
void GameOfLife::SwapCell(const unsigned& x, const unsigned& y)
{
	field[x][y] = !field[x][y];
	return;
}

// Updates all Cells within the Field by running the NeighborChecker Method('NewValCell')
void GameOfLife::UpdateField()
{
    vector< vector<unsigned> > stockField = field;
    for (unsigned i = 1; i != xMax + 1; i++)
    {
        for (unsigned j = 1; j != yMax + 1; j++)
        {
            stockField[i][j] = NewValCell(i, j);
        }
    }
    field = stockField;
	phase++;
    return;
}

// Checks the Neighboring Cells of a Given Cell, then Sets its New State
unsigned GameOfLife::NewValCell(const unsigned& x, const unsigned& y)
{
	unsigned stok;
	stok = field[x - 1][y - 1]
		+ field[x - 1][y]
		+ field[x - 1][y + 1]
		+ field[x][y - 1]
		+ field[x][y + 1]
		+ field[x + 1][y - 1]
		+ field[x + 1][y]
		+ field[x + 1][y + 1];

	switch (stok)
	{
	case 3: return 1;
	case 2: return field[x][y];
	default: return 0;
	}
}
