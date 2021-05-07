#include "human.h"
#include <conio.h>

Human::Human(int _x, int _y)
{
	this->strength = HUMANSTRENGTH;
	this->initiative = HUMANINITIATIVE;
	this->name = HUMANNAME;
	this->symbol = HUMANSYMBOL;
	this->x = _x;
	this->y = _y;
}

void Human::move()
{
	char direction;
	direction = _getch();
	switch (direction)
	{
		case 'w':
			if (this->y > 0) this->y--;
			break;
		case 's':
			if ((this->y < (GRIDHEIGHT - 1))) this->y++;
			break;
		case 'a':
			if (this->x > 0) this->x--;
			break;
		case 'd':
			if ((this->x < (GRIDHEIGHT - 1)) > 0) this->x++;
			break;
		default:
			move();
			break;
	}
}

int Human::collision(Organism* _organism)
{
	static int roundsLeft = 0;
	if (roundsLeft == 0)
	{
		std::cout << "SPECIAL ABILITY - PRESS Q" << std::endl;
		char abilityActivated = _getch();
		if ((abilityActivated == 'q' || abilityActivated == 'Q') && roundsLeft == 0)
		{
			std::cout << "SPECIAL ABILITY ACTIVATED" << std::endl;
			this->strength = 10;
			roundsLeft = 5;
		}
	}
	if (roundsLeft > 0)
	{
		roundsLeft--;
		this->strength--;
	}
	int result = Animal::collision(_organism);
	return result;
}

void Human::action(Grid* grid, World* world)
{
	int oldX = this->x;
	int oldY = this->y;
	move();
	if (this->x == oldX && this->y == oldY) return;

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

Organism* Human::createNew(Cell* cell)
{
	Organism* newHuman = new Human(cell->getX(), cell->getY());
	toEverLive.push_back(newHuman);
	return newHuman;
}

Human::~Human()
{
}