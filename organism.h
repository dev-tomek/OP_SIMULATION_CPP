#pragma once
#include <iostream>
#include "cell.h"
#include "world.h"
#include "grid.h"

#define BREED 1
#define KILLED 2

class Grid;
class Cell;
class World;

class Organism
{
public:
	std::string name;
	char symbol;
	int strength;
	int initiative;
	int x;
	int y;
	
public:
	virtual void action(Grid* grid, World* world) = 0;
	virtual int collision(Organism* _organism) = 0;
	virtual char draw() = 0;
	virtual Organism* createNew(Cell* cell) = 0;
};