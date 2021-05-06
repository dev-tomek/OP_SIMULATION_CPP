#pragma once
#include <iostream>
#include "animal.h"

#define FOXSTRENGTH 3;
#define FOXINITIATIVE 7;
#define FOXSYMBOL '$'
#define FOXNAME "fox";

class Fox : public Animal
{
public:
	Fox(int _x, int _y);
	void action(Grid* grid, World* world) override;
	Organism* createNew(Cell* cell) override;
	~Fox();
};
