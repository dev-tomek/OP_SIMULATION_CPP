#include "grass.h"

Grass::Grass(int _x, int _y)
{
	this->name = GRASSNAME;
	this->symbol = GRASSSYMBOL;
	this->strength = GRASSSTRENGTH;
	this->x = _x;
	this->y = _y;
}

Organism* Grass::createNew(Cell* cell)
{
	Organism* newGrass = new Grass(cell->getX(), cell->getY());
	toEverLive.push_back(newGrass);
	return newGrass;
}

Grass::~Grass()
{
	std::cout << "default destructor" << std::endl;
}
