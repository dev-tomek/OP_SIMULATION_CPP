#include "animal.h"

Animal::Animal() {}

char Animal::draw()
{
	return this->symbol;
}

int Animal::collision(Organism* _organism)
{
	if (_organism->name == this->name)
	{
		
		return BREED;
	}
	else
	{
		Organism* opponent = _organism;
		if (opponent->strength > this->strength)
		{
			return KILLED;
		}
	}
	return -1;
}

void Animal::action(Grid* grid, World* world)
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

	if (!grid->getCell(this->x, this->y)->isEmpty())
	{
		Organism* b = grid->getCell(this->x, this->y)->organism;
		
		int myresult = collision(b);
		int hisresult = b->collision(this);
		if (myresult == BREED)
		{
			Cell* emptyCell = grid->findNearestEmpty(this->x, this->y);
			Organism* newOrganism = this->createNew(emptyCell);
			world->spawnOrganism(*newOrganism);
			this->x = oldX;
			this->y = oldY;
		}
		if (myresult == KILLED)
		{
			world->deleteAnimal(this);
			grid->getCell(oldX, oldY)->clear(); //deleting old 
			return;
		}
		if (hisresult == KILLED)
		{
			world->deleteAnimal(b);
			return;
		}
	}
	grid->getCell(oldX, oldY)->clear(); //deleting old 
	grid->getCell(this->x, this->y)->setOrganism(this); //setting up new
}



Animal::~Animal()
{
	std::cout << "default destructor" << std::endl;
}