#pragma once
#include <iostream>
#include "cell.h"
#define GRIDHEIGHT 20
#define GRIDWIDTH 20

class Grid
{
public:
	Cell** worldgrid;
public:
	Grid();
	void drawGrid();
	~Grid();
};