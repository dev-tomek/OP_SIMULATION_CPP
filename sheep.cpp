#include "sheep.h"

Sheep::Sheep(int _x, int _y)
{
	this->name = SHEEPNAME;
	this->symbol = SHEEPSYMBOL;
	this->strength = SHEEPSTRENGTH;
	this->initiative = SHEEPINITIATIVE;
	this->x = _x;
	this->y = _y;
}

Organism* Sheep::createNew(Cell* cell)
{
	Organism* newSheep = new Sheep(cell->getX(), cell->getY());
	return newSheep;
}

Sheep::~Sheep()
{
	std::cout << "default destructor" << std::endl;
}

