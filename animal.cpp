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
		Organism* opponent = _organism;             //??????????????
		if (opponent->strength > this->strength)    // TAKE CARE OF EQUAL STRENGTH
		{
			return KILLED;
		}
	}
	return -1;
}

void Animal::move()
{
	int option;
	option = rand() % 4;

	if (option == 0 && this->x > 0)                                       //TAKE CARE OF THE CASE WHEN ORGANISM IS NEXT TO THE WALL AND OPTION IS THE WALL
	{
		this->x--; //goes up
	}
	else if (option == 1 && this->x < GRIDWIDTH - 1)
	{
		this->x++; //goes down
	}
	else if (option == 2 && this->y > 0)
	{
		this->y--; //goes left
	}
	else if (option == 3 && this->y < GRIDHEIGHT - 1)
	{
		this->y++; //goes right
	}
	else
	{
		move();
	}
}

void Animal::action(Grid* grid, World* world)
{
	//random move
	int oldX = this->x;
	int oldY = this->y;
	move();

	if (!grid->getCell(this->x, this->y)->isEmpty()) //checking if grid that the organism went to is occupied
	{
		Organism* occupier = grid->getCell(this->x, this->y)->organism; //get organism on that cell
		int attackerState = collision(occupier);                        //collision handling for attacker
		int occupierState = occupier->collision(this);					//collision handling for occupier
		if (attackerState == BREED)
		{
			Cell* emptyCell = grid->findNearestEmpty(this->x, this->y);
			Organism* newOrganism = this->createNew(emptyCell);
			world->spawnOrganism(*newOrganism);
			this->x = oldX;
			this->y = oldY;
		}
		if (attackerState == KILLED)
		{
			world->deleteOrganism(this);
			grid->getCell(oldX, oldY)->clear(); //deleting old 
			return;
		}
		if (occupierState == KILLED)
		{
			world->deleteOrganism(occupier);
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