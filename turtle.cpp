#include "turtle.h"

Turtle::Turtle(int _x, int _y)
{
	this->name = TURTLENAME;
	this->symbol = TURTLESYMBOL;
	this->strength = TURTLESTRENGTH;
	this->initiative = TURTLEINITIATIVE;
	this->x = _x;
	this->y = _y;
}

void Turtle::action(Grid* grid, World* world)
{
	int oldX = this->x;
	int oldY = this->y;
	bool propability = (rand() % 100) < 75;
	if (!propability)
	{
		move();
	}

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

int Turtle::collision(Organism* _organism)
{
	return 0;
}

Organism* Turtle::createNew(Cell* cell)
{
	Organism* newTurtle = new Turtle(cell->getX(), cell->getY());
	return newTurtle;
}

Turtle::~Turtle()
{
	std::cout << "default destructor" << std::endl;
}

