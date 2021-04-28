#pragma once
#include <iostream>
#include "cell.h"
#define GRIDHEIGHT 20
#define GRIDWIDTH 20
using namespace std;

class Grid
{
public:
	Cell** worldgrid;
public:
	Grid();
	void drawGrid();
	~Grid();
};

