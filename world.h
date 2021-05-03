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
private:
	Grid* grid;
public:
	std::vector<Organism*> organismsAlive;
public:
	World();
	~World();
	void drawWorld();
	void makeTurn();
	void spawnOrganism(Organism& organism);
};

