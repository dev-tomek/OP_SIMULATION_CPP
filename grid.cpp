#include "grid.h"
#include <vector>

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
	this->outOfBounds = new OutOfBounds;
}

Cell* Grid::getCell(int _x, int _y)
{
	if (_x < 0  || _x > GRIDWIDTH - 1 || _y < 0 || _y > GRIDHEIGHT - 1)
	{
		return this->outOfBounds;
	}
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

Cell* Grid::findRandomEmpty(int _x, int _y)
{
	int optionStart = rand() % 4;
	int option = optionStart + 1;
	int candX, candY;
	bool found = false;
	
	while (!found)
	{
		option = option % 4;
		if (option == optionStart) return nullptr;
		candX = _x;
		candY = _y;
		if (option == 0) candX--;
		else if (option == 1) candX++;
		else if (option == 2) candY--;
		else if (option == 3) candY++;
		if (candX < 0 || candX >= GRIDWIDTH || candY < 0 || candY >= GRIDHEIGHT) option++;
		else if (!this->getCell(candX, candY)->isEmpty()) option++;
		else found = true;
	}
	return this->getCell(candX, candY);
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