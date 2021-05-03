#include "animal.h"

Animal::Animal() {}

char Animal::draw()
{
	return this->symbol;
}

int Animal::collision(Grid* grid, World world)
{
	Cell* emptyCell = grid->findNearestEmpty(this->x, this->y);
	Organism* newOrganism = this->createNew(&world, emptyCell->x, emptyCell->y);
	return BREED;
}

void Animal::action(Grid* grid, World world)
{
	//random move
	int option;
	//option = rand() % 4;
	option = rand() % 2;
	if (option == 1)
	{
		option = 2;
	}
	else
	{
		option = -1;
	}

	int oldX = this->x;
	int oldY = this->y;

	if (option == 0 && this->x > 0)
	{
		this->x--; //goes up
	}
	else if (option == 1 && this->x < GRIDHEIGHT - 1)
	{
		this->x++; //goes down
	}
	else if (option == 2 && this->y > 0)
	{
		this->y--; //goes left
	}
	else if (option == 3 && this->y < GRIDWIDTH - 1)
	{
		this->y++; //goes right
	}

	if (grid->worldgrid[this->x][this->y].organism != nullptr)
	{
		int result = collision(grid, world);
		if (result == BREED)
		{
			this->x = oldX;
			this->y = oldY;
		}
	}
	grid->worldgrid[oldX][oldY].organism = nullptr;
	grid->worldgrid[this->x][this->y].organism = this;
}



Animal::~Animal()
{
	std::cout << "default destructor" << std::endl;
}