#include "fox.h"

Fox::Fox(int _x, int _y)
{
	this->name = FOXNAME;
	this->symbol = FOXSYMBOL;
	this->strength = FOXSTRENGTH;
	this->initiative = FOXINITIATIVE;
	this->x = _x;
	this->y = _y;
}

void Fox::action(Grid* grid, World* world)
{
	int oldX = this->x;
	int oldY = this->y;
	move();

	if (!grid->getCell(this->x, this->y)->isEmpty()) //checking if grid that the organism went to is occupied
	{
		Organism* occupier = grid->getCell(this->x, this->y)->organism; //get organism on that cell
		if (occupier->strength > this->strength) //fox's special action ability
		{
			this->x = oldX;
			this->y = oldY;
			return;
		}
		int attackerState = collision(occupier);                        //collision handling for attacker
		int occupierState = occupier->collision(this);					//collision handling for occupier
		if (attackerState == BREED)
		{
			Cell* emptyCell = grid->findRandomEmpty(this->x, this->y);
			if (emptyCell == nullptr) return;
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
		}
	}
	grid->getCell(oldX, oldY)->clear(); //deleting old 
	grid->getCell(this->x, this->y)->setOrganism(this); //setting up new
}


Organism* Fox::createNew(Cell* cell)
{
	Organism* newFox = new Fox(cell->getX(), cell->getY());
	return newFox;
}

Fox::~Fox()
{
	std::cout << "default destructor" << std::endl;
}

