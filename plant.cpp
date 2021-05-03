#include "plant.h"

Plant::Plant()
{
	this->initiative = PLANTINITIATIVE;
};

void Plant::action(Grid* grid, World* world)
{
	
}

char Plant::draw()
{
	return this->symbol;
}

int Plant::collision(Grid* grid, World* world)
{
	return -1;
}


















Plant::~Plant() {};