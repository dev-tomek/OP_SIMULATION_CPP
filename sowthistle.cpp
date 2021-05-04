#include "sowthistle.h"

Sowthistle::Sowthistle(int _x, int _y)
{
	this->name = SOWTHISTLENAME;
	this->symbol = SOWTHISTLESYMBOL;
	this->strength = SOWTHISTLESTRENGTH;
	this->x = _x;
	this->y = _y;
}

void Sowthistle::action(Grid* grid, World* world)
{
	for (int i = 0; i < 3; i++)
	{
		bool propability = (rand() % 100) < 5;
		if (propability)
		{
			Cell* emptyCell = grid->findRandomEmpty(this->x, this->y);
			if (emptyCell == nullptr) return;
			Organism* newOrganism = this->createNew(emptyCell);
			world->spawnOrganism(*newOrganism);
			return;
		}
	}
}

Organism* Sowthistle::createNew(Cell* cell)
{
	Organism* newSowthistle = new Sowthistle(cell->getX(), cell->getY());
	return newSowthistle;
}

Sowthistle::~Sowthistle()
{
	std::cout << "default destructor" << std::endl;
}
