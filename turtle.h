#pragma once
#include <iostream>
#include "animal.h"

#define TURTLESTRENGTH 2;
#define TURTLEINITIATIVE 1;
#define TURTLESYMBOL '^'
#define TURTLENAME "turtle";

class Turtle : public Animal
{
public:
	Turtle(int _x, int _y);
	void action(Grid* grid, World* world) override;
	int collision(Organism* _organism) override;
	Organism* createNew(Cell* cell) override;
	~Turtle();
};
