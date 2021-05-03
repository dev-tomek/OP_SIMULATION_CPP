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
public:
	Cell** worldgrid;
public:
	Grid();
	void saveGridState();
	void drawGrid();
	Cell* findNearestEmpty(int _x, int _y);
	~Grid();
};