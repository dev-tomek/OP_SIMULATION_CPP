#include "sosnowskyhogweed.h"

Hogweed::Hogweed(int _x, int _y)
{
	this->name = HOGWEEDNAME;
	this->symbol = HOGWEEDSYMBOL;
	this->strength = HOGWEEDSTRENGTH;
	this->x = _x;
	this->y = _y;
}

Organism* Hogweed::createNew(Cell* cell)
{
	Organism* newHogweed = new Hogweed(cell->getX(), cell->getY());
	toEverLive.push_back(newHogweed);
	return newHogweed;
}

void Hogweed::action(Grid* grid, World* world)
{
	int option = 0;
	int candX, candY;
	while (option != 4)
	{
		candX = this->x;
		candY = this->y;
		if (option == 0)
		{
			candX--;
			if (candX >= 0 && candX <= GRIDWIDTH - 1)
			{
				if (world->grid->getCell(candX, candY)->organism != NULL)
					world->deleteOrganism(world->grid->getCell(candX, candY)->organism);
				//world->grid->getCell(candX, candY)->getSymbol()
			}
		}
		else if (option == 1)
		{
			candX++;
			if (candX >= 0 && candX <= GRIDWIDTH - 1)
			{
				if (world->grid->getCell(candX, candY)->organism != NULL)
					world->deleteOrganism(world->grid->getCell(candX, candY)->organism);
			}
		}
		else if (option == 2)
		{
			candY--;
			if (candY >= 0 && candY <= GRIDHEIGHT - 1)
			{
				if (world->grid->getCell(candX, candY)->organism != NULL)
					world->deleteOrganism(world->grid->getCell(candX, candY)->organism);
			}
		}
		else if (option == 3)
		{
			candY++;
			if (candY >= 0 && candY <= GRIDHEIGHT - 1)
			{
				if (world->grid->getCell(candX, candY)->organism != NULL)
					world->deleteOrganism(world->grid->getCell(candX, candY)->organism);
			}
		}
		option++;
	}
}

Hogweed::~Hogweed()
{
	std::cout << "default destructor" << std::endl;
}
