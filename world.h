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
	int turn;
public:
	std::vector<Organism*> organismsAlive;
	Grid* grid;
	World();
	~World();
	void drawWorld();
	void restart();
	void spawnOrganism(Organism& organism);
	void deleteOrganism(Organism* organism);
	int makeTurn();
};

