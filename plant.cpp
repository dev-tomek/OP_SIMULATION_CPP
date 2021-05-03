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