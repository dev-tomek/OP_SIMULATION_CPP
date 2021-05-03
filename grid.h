#pragma once
#include <iostream>
#include <fstream>
#include "cell.h"
#define GRIDHEIGHT 20
#define GRIDWIDTH 20

class Cell;
class Grid
{
private:
	std::ofstream fileOut;
	Cell** worldgrid;
public:
	Grid();
	void saveGridState();
	void drawGrid();
	Cell* getCell(int _x, int _y);
	Cell* findNearestEmpty(int _x, int _y);
	~Grid();
};