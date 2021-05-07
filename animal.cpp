#include "animal.h"

Animal::Animal() 
{
	this->age = INITIAL_AGE;
}

char Animal::draw()
{
	return this->symbol;
}

bool Animal::collisionResult(int attackerState, int occupierState, World* world, Organism* occupier)
{
	if (attackerState == BREED)
	{
		Cell* emptyCell = world->grid->findRandomEmpty(this->x, this->y);
		if (emptyCell == nullptr) return false;
		Organism* newOrganism = this->createNew(emptyCell);
		world->spawnOrganism(*newOrganism);
		return false;
	}
	if (occupierState == ESCAPE)
	{
		Cell* escapeTo = world->grid->findRandomEmpty(occupier->x, occupier->y); 
		if (escapeTo == nullptr)
		{
			world->deleteOrganism(occupier);
			return true;
		}
		else world->grid->getCell(escapeTo->x, escapeTo->y)->setOrganism(occupier);
	}
	if (attackerState == KILLED)
	{
		world->deleteOrganism(this);
		return false;
	}
	if (occupierState == KILLED)
	{
		world->deleteOrganism(occupier);
		return true;
	}
	if (attackerState == ALIVE && occupierState == ALIVE) //attacker wins when the strength is equal
	{
		world->deleteOrganism(occupier);
		return true;
	}
	if (occupierState == REFLECT)
	{
		return false;
	}
	return true;
}

int Animal::collision(Organism* _organism)
{
	if (_organism->name == this->name)
	{
		return BREED;
	}
	else
	{
		if (_organism->name == "guarana")
		{
			this->strength = this->strength + 3;
		}
		if (_organism->name == "hogweed")
		{
			return KILLED;
		}
		if (_organism->strength > this->strength) 
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

	if (option == 0 && this->x > 0)
	{
		this->x--;
	}
	else if (option == 1 && this->x < GRIDWIDTH - 1)
	{
		this->x++;
	}
	else if (option == 2 && this->y > 0)
	{
		this->y--;
	}
	else if (option == 3 && this->y < GRIDHEIGHT - 1)
	{
		this->y++;
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

	bool canMove = true;
	if (!grid->getCell(this->x, this->y)->isEmpty()) //checking if grid that the organism went to is occupied
	{
		Organism* occupier = grid->getCell(this->x, this->y)->organism; //get organism on that cell
		int attackerState = collision(occupier);                        //collision handling for attacker
		int occupierState = occupier->collision(this);					//collision handling for occupier
		canMove = collisionResult(attackerState, occupierState, world, occupier);
	}
	if (canMove)
	{
		grid->getCell(oldX, oldY)->clear(); //deleting old 
		grid->getCell(this->x, this->y)->setOrganism(this); //setting up new
	}
	else
	{
		this->x = oldX;
		this->y = oldY;
	}
}

Animal::~Animal()
{
	std::cout << "default destructor" << std::endl;
}