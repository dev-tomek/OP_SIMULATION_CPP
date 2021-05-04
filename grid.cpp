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

Cell* Grid::findNearestEmpty(int _x, int _y)
{
	if (this->worldgrid[_x - 1][_y].isEmpty() && _x > 0)
	{
		return &worldgrid[_x - 1][_y];
	}
	else if (this->worldgrid[_x + 1][_y].isEmpty() && _x < GRIDWIDTH - 1)
	{
		return &worldgrid[_x + 1][_y];
	}
	else if (this->worldgrid[_x][_y - 1].isEmpty() && _y > 0)
	{
		return &worldgrid[_x][_y - 1];
	}
	else if (this->worldgrid[_x][_y + 1].isEmpty() && _y < GRIDHEIGHT - 1)
	{
		return &worldgrid[_x][_y + 1];
	}
	return nullptr;
}

Cell* Grid::findRandomEmpty(int _x, int _y)
{
	int option;
	option = rand() % 4;
	Cell* result = nullptr;

	if (option == 0 && _x > 0)                                       //TAKE CARE OF THE CASE WHEN ORGANISM IS NEXT TO THE WALL AND OPTION IS THE WALL
	{
		if (this->worldgrid[_x - 1][_y].isEmpty()) return &this->worldgrid[_x - 1][_y];
	}
	else if (option == 1 && _x < GRIDWIDTH - 1)
	{
		if (this->worldgrid[_x + 1][_y].isEmpty()) return &this->worldgrid[_x - 1][_y];
		else result = findRandomEmpty(_x, _y);
	}
	else if (option == 2 && _y > 0)
	{
		if (this->worldgrid[_x][_y - 1].isEmpty()) return &this->worldgrid[_x][_y - 1];
		else result = findRandomEmpty(_x, _y);
	}
	else if (option == 3 && _y < GRIDHEIGHT - 1)
	{
		if (this->worldgrid[_x][_y + 1].isEmpty()) return &this->worldgrid[_x][_y + 1];
		else result = findRandomEmpty(_x, _y);
	}
	else
	{
		result = findRandomEmpty(_x, _y);
	}
	return result;
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