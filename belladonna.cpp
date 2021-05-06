#include "belladonna.h"

Belladonna::Belladonna(int _x, int _y)
{
	this->name = BELLADONNANAME;
	this->symbol = BELLADONNASYMBOL;
	this->strength = BELLADONNASTRENGTH;
	this->x = _x;
	this->y = _y;
}

Organism* Belladonna::createNew(Cell* cell)
{
	Organism* newBelladonna = new Belladonna(cell->getX(), cell->getY());
	return newBelladonna;
}

Belladonna::~Belladonna()
{
	std::cout << "default destructor" << std::endl;
}
