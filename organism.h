#pragma once
#include <iostream>
#include "cell.h"
#include "world.h"
#include "grid.h"

#define BREED 1
#define KILLED 2
#define ALIVE -1
#define REFLECT 3
#define ESCAPE 4
#define INITIAL_AGE 0

class Grid;
class Cell;
class World;

class Organism
{
public:
	std::string name;
	std::vector<Organism*> toEverLive;
	char symbol;
	int strength;
	int initiative;
	int x;
	int y;
	int age;
	
public:
	virtual void action(Grid* grid, World* world) = 0;
	virtual int collision(Organism* _organism) = 0;
	virtual char draw() = 0;
	virtual Organism* createNew(Cell* cell) = 0;
};