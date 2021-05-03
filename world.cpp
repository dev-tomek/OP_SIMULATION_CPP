#include "world.h"

World::World()
{
	this->grid = new Grid();
}

struct initiativeComparison
{
	inline bool operator() (const Organism* organism1, const Organism* organism2)
	{
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

void World::makeTurn()
{
	//sorting a vector of alive animals by their initiative descendingly
	std::sort(organismsAlive.begin(), organismsAlive.end(), initiativeComparison());
	for (int i = 0; i < organismsAlive.size(); i++)
	{
		std::cout << organismsAlive[i]->name << " with initiative: " << organismsAlive[i]->initiative << " uses his action" << std::endl;
		organismsAlive[i]->action(this->grid, *this);
	}
}

World::~World() {}