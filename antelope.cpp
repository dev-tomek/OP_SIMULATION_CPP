#include "antelope.h"

Antelope::Antelope(int _x, int _y)
{
	this->name = ANTELOPENAME;
	this->symbol = ANTELOPESYMBOL;
	this->strength = ANTELOPESTRENGTH;
	this->initiative = ANTELOPEINITIATIVE;
	this->x = _x;
	this->y = _y;
}

int Antelope::collision(Organism* _organism)
{
	if (_organism->name == this->name)
	{
		return BREED;
	}
	else
	{
		int t = Animal::collision(_organism);
		bool propability = (rand() % 100) < 50;
		if (propability) return ESCAPE;
		return t;
	}
	
}

void Antelope::move()
{
	int option;
	option = rand() % 4;

	if (option == 0 && this->x > 0)
	{
		this->x = this->x - 2; 
	}
	else if (option == 1 && this->x < GRIDWIDTH - 1)
	{
		this->x = this->x + 2;
	}
	else if (option == 2 && this->y > 0)
	{
		this->y = this->y - 2;
	}
	else if (option == 3 && this->y < GRIDHEIGHT - 1)
	{
		this->y = this->y + 2;
	}
	else
	{
		move();
	}
}

void Antelope::action(Grid* grid, World* world)
{
	//random move
	int oldX = this->x;
	int oldY = this->y;
	move();

	bool canMove = true;
	if (!grid->getCell(this->x, this->y)->isEmpty()) //checking if grid that the organism went to is occupied
	{
		Organism* occupier = grid->getCell(this->x, this->y)->organism; //get organism on that cell
		if (occupier == nullptr)
		{
			this->x = oldX;
			this->y = oldY;
			return;
		}
		int attackerState = collision(occupier);                        //collision handling for attacker
		if (attackerState == ESCAPE)
		{
			Cell* escapeTo = grid->findRandomEmpty(this->x, this->y);
			if (escapeTo == nullptr)
			{
				this->x = oldX;
				this->y = oldY;
				return;
			}
			grid->getCell(oldX, oldY)->clear(); //deleting old 
			grid->getCell(escapeTo->x, escapeTo->y)->setOrganism(this);
			return;
		}
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

Organism* Antelope::createNew(Cell* cell)
{
	Organism* newAntelope = new Antelope(cell->getX(), cell->getY());
	toEverLive.push_back(newAntelope);
	return newAntelope;
}

Antelope::~Antelope()
{
	std::cout << "default destructor" << std::endl;
}