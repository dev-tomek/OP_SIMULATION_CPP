#pragma once
#include <iostream>
#include "animal.h"

#define HUMANSTRENGTH 5;
#define HUMANINITIATIVE 4;
#define HUMANSYMBOL 'H'
#define HUMANNAME "human";

class Human : public Animal
{
public:
	Human(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	int collision(Organism* _organism) override;
	void action(Grid* grid, World* world) override;
	void move();
	~Human();
};
