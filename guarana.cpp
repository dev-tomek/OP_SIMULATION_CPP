#include "guarana.h"

Guarana::Guarana(int _x, int _y)
{
	this->name = GUARANANAME;
	this->symbol = GUARANASYMBOL;
	this->strength = GUARANASTRENGTH;
	this->x = _x;
	this->y = _y;
}

Organism* Guarana::createNew(Cell* cell)
{
	Organism* newGuarana = new Guarana(cell->getX(), cell->getY());
	return newGuarana;
}

Guarana::~Guarana()
{
	std::cout << "default destructor" << std::endl;
}
