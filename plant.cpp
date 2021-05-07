#include "plant.h"

Plant::Plant()
{
	this->initiative = PLANTINITIATIVE;
	this->age = INITIAL_AGE;
};

void Plant::action(Grid* grid, World* world)
{
	bool propability = (rand() % 100) < 5;
	if (propability)
	{
		Cell* emptyCell = grid->findRandomEmpty(this->x, this->y);
		if (emptyCell == nullptr) return;
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