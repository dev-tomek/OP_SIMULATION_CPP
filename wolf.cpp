#include "wolf.h"


Wolf::Wolf(int _x, int _y)
{
	this->name = WOLFNAME;
	this->symbol = WOLFSYMBOL;
	this->strength = WOLFSTRENGTH;
	this->initiative = WOLFINITIATIVE;
	this->x = _x;
	this->y = _y;
}

//temporary overload
Wolf::Wolf(int _x, int _y, int init, int str)
{
	this->name = WOLFNAME;
	this->symbol = WOLFSYMBOL;
	this->strength = str;
	this->initiative = init;
	this->x = _x;
	this->y = _y;
}

Organism* Wolf::createNew(World* world, int _x, int _y)
{
	Organism* newWolf = new Wolf(_x, _y);
	world->spawnOrganism(*newWolf);
	return newWolf;
}

Wolf::~Wolf()
{
	std::cout << "default destructor" << std::endl;
}