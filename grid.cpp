#include "grid.h"

Grid::Grid()
{
	this->worldgrid = new Cell* [GRIDHEIGHT]; //creating a vertical pointer array
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		worldgrid[i] = new Cell [GRIDWIDTH]; //pointing each pointer to a new horizontal array
	}
}

void Grid::drawGrid()
{
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			cout << this->worldgrid[i][j].symbol << " ";
		}
		cout << endl;
	}
}

Grid::~Grid()
{
	cout << "default destructor" << endl;
}