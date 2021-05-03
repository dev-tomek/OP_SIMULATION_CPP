#include "animal.h"

Animal::Animal() {}

void Animal::draw(Cell** worldgrid, int mode)
{
	if (mode == NULL) //used for clearning the cell
	{
		worldgrid[this->x][this->y].organism = nullptr;
		worldgrid[this->x][this->y].symbol = '.';
	}
	else //used for drawing an organism in cell
	{
		this->cell = &worldgrid[this->x][this->y];
		worldgrid[this->x][this->y].organism = this;
		worldgrid[this->x][this->y].symbol = this->symbol;
	}
}

int Animal::collision(Grid* grid, World world)
{
	Cell* emptyCell = grid->findNearestEmpty(this->x, this->y);
	Organism* newOrganism = this->createNew(&world, emptyCell->x, emptyCell->y);
	return BREED;
}

void Animal::action(Grid* grid, World world)
{
	draw(grid->worldgrid, NULL); //clearing current cell (organism properties are still assigned to this cell, its just not being displayed)

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


	draw(grid->worldgrid, 1); //drawing organism in the right place
}



Animal::~Animal()
{
	std::cout << "default destructor" << std::endl;
}