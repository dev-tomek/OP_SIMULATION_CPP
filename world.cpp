#include "world.h"

World::World()
{
	this->grid = new Grid();
	this->turn = 0;
}

struct Comparator
{
	inline bool operator() (const Organism* organism1, const Organism* organism2)
	{
		if (organism1->initiative == organism2->initiative)
		{
			return organism1->age > organism2->age;
		}
		return (organism1->initiative > organism2->initiative);
	}
};

void World::drawWorld()
{
	this->grid->drawGrid();
	this->grid->saveGridState();
}

//takes an organism and spawns it in the cell
void World::spawnOrganism(Organism& organism)
{
	grid->getCell(organism.x, organism.y)->setOrganism(&organism);
	organismsAlive.push_back(&organism);
}

void World::deleteOrganism(Organism* organism)
{
	for (int i = 0; i < organismsAlive.size(); i++)
	{
		if (organismsAlive[i] == organism)
		{
			organismsAlive.erase(organismsAlive.begin() + i);
		}
	}
	grid->getCell(organism->x, organism->y)->clear();
}

int World::makeTurn()
{
	for (int i = 0; i < organismsAlive.size(); i++)
	{
		organismsAlive[i]->age++;
	}
	this->turn++;
	bool humanAlive = false;
	std::cout << "TURN NUMBER: " << turn << std::endl;
	for (int i = 0; i < organismsAlive.size(); i++)
	{
		if (organismsAlive[i]->name == "human") humanAlive = true;
	}
	if (!humanAlive) return 0;
	else
	{
		//sorting a vector of alive animals by their initiative and age descendingly
		std::sort(organismsAlive.begin(), organismsAlive.end(), Comparator());
		for (int i = 0; i < organismsAlive.size(); i++)
		{
			//std::cout << organismsAlive[i]->name << " with initiative: " << organismsAlive[i]->initiative << " uses his action" << std::endl;
			organismsAlive[i]->action(this->grid, this);
		}
	}
	return 1;
}

void World::restart()
{
	for (int i = 0; i < organismsAlive.size(); i++)
	{
		this->turn = 0;
		organismsAlive[i]->age = 0;
		deleteOrganism(organismsAlive[i]);
	}
	organismsAlive.empty();
}

World::~World() {}