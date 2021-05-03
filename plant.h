#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "world.h"
#include "organism.h"
#include "grid.h"

#define PLANTINITIATIVE 0

class Organism;
class Grid;
class World;

class Plant : public Organism
{
public:
	Plant();
	~Plant();
	virtual void action(Grid* grid, World* world);
	virtual int collision(Grid* grid, World* world);
	virtual char draw();
};
