#pragma once
#include <iostream>
#include "animal.h"

#define ANTELOPESTRENGTH 4;
#define ANTELOPEINITIATIVE 4;
#define ANTELOPESYMBOL '"'
#define ANTELOPENAME "antelope";

class Antelope : public Animal
{
public:
	Antelope(int _x, int _y);
	void action(Grid* grid, World* world) override;
	void move() override;
	int collision(Organism* _organism);
	Organism* createNew(Cell* cell) override;
	~Antelope();
};
