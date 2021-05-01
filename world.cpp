#include "world.h"

World::World()
{
	std::cout << "default world constructor" << std::endl;
}

//takes an organism and spawns it in the cell
void World::spawnOrganism(Organism& organism, Cell** worldgrid)
{
	organism.cell = &worldgrid[organism.x][organism.y];
	worldgrid[organism.x][organism.y].occupier = organism.name;
	worldgrid[organism.x][organism.y].symbol = organism.symbol;
	organismsAlive.push_back(&organism);
}

void World::makeTurn()
{
	//sorting a vector of alive animals by their initiative descendingly
	std::sort(organismsAlive.begin(), organismsAlive.end(), initiativeComparison());
}

World::~World()
{
	std::cout << "default world destructor" << std::endl;
}