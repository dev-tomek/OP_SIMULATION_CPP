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
		bool canMove = true;
		if (!grid->getCell(this->x, this->y)->isEmpty()) //checking if grid that the organism went to is occupied
		{
			Organism* occupier = grid->getCell(this->x, this->y)->organism; //get organism on that cell
			int attackerState = Animal::collision(occupier);                //collision handling for attacker
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
}

int Turtle::collision(Organism* _organism)
{
	int t = Animal::collision(_organism);
	if (t == KILLED)
	{
		if (_organism->strength < 5)
		{
			return REFLECT;
		}
	}
	return t;
}

Organism* Turtle::createNew(Cell* cell)
{
	Organism* newTurtle = new Turtle(cell->getX(), cell->getY());
	toEverLive.push_back(newTurtle);
	return newTurtle;
}

Turtle::~Turtle()
{
	std::cout << "default destructor" << std::endl;
}

