#include "plant.h"

Plant::Plant()
{
	this->initiative = PLANTINITIATIVE;
};

void Plant::action(Grid* grid, World* world)
{
	bool propability = (rand() % 100) < 10;
	if (propability)
	{
		Cell* emptyCell = grid->findRandomEmpty(this->x, this->y);
		Organism* newOrganism = this->createNew(emptyCell);
		world->spawnOrganism(*newOrganism);
	}
	
}

char Plant::draw()
{
	return this->symbol;
}

int Plant::collision(Organism* _organism)
{
	Organism* opponent = _organism;
	if (opponent->strength > this->strength)
	{
		return KILLED;
	}
	return -1;
}


















Plant::~Plant() {};