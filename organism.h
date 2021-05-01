#pragma once
#include <iostream>
#include "cell.h"

class Organism
{
public:
	std::string name;
	Cell* cell;
	char symbol;
	int strength;
	int initiative;
	int x;
	int y;
	
public:
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
};