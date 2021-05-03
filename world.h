#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "organism.h"
#include "grid.h"

class Grid;
class Organism;
class Cell;

class World
{
public:
	std::vector<Organism*> organismsAlive;
	Grid* grid;
public:
	World();
	~World();
	void makeTurn();
	void spawnOrganism(Organism& organism);
};

