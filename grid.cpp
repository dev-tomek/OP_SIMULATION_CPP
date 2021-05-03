#include "grid.h"

Grid::Grid()
{
	this->worldgrid = new Cell * [GRIDHEIGHT]; //creating a vertical pointer array
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		worldgrid[i] = new Cell[GRIDWIDTH]; //pointing each pointer to a new horizontal array
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			this->worldgrid[i][j].setX(i);
			this->worldgrid[i][j].setY(j);
		}
	}
}

Cell* Grid::getCell(int _x, int _y)
{
	return &this->worldgrid[_x][_y];
}

void Grid::drawGrid()
{
	std::cout << "----------------GAMEPLAY----------------" << std::endl;
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			std::cout << this->worldgrid[j][i].getSymbol() << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
}

//consider all the 8 cases
Cell* Grid::findNearestEmpty(int _x, int _y)
{
	return &worldgrid[_x - 1][_y];
}

//autosave function
void Grid::saveGridState()
{
	fileOut.open("gridstate.txt");
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			fileOut << this->worldgrid[j][i].getSymbol() << " ";
		}
		fileOut << std::endl;
	}
	fileOut.close();
}

Grid::~Grid()
{
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		delete[] worldgrid[i];
	}
	delete[] worldgrid;
}