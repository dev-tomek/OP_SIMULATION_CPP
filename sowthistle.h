#pragma once
#include <iostream>
#include "plant.h"

#define SOWTHISTLESTRENGTH 0;
#define SOWTHISTLESYMBOL '*'
#define SOWTHISTLENAME "sowthistle";
#define ATTEMPTS 3;

class Sowthistle : public Plant
{
public:
	Sowthistle(int _x, int _y);
	void action(Grid* grid, World* world) override;
	Organism* createNew(Cell* cell) override;
	~Sowthistle();
};
