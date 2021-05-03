#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "world.h"
#include "organism.h"
#include "grid.h"

#define BREED 1

class Organism;
class Grid;
class World;

class Animal : public Organism
{
public:
	Animal();
	~Animal();
	virtual void action(Grid* grid, World world);
	virtual int collision(Grid* grid, World world);
	virtual char draw();
};

