#pragma once
#include <iostream>
#include "organism.h"
#include "grid.h"
#include <algorithm>
#include <vector>

struct initiativeComparison
{
	inline bool operator() (const Organism* organism1, const Organism* organism2)
	{
		return (organism1->initiative > organism2->initiative);
	}
};

class World
{
public:
	std::vector<Organism*> organismsAlive;
	
public:
	World();
	~World();
	void makeTurn();
	//void drawWorld();
	void spawnOrganism(Organism& organism, Cell** worldgrid);
};

