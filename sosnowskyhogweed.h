#pragma once
#include <iostream>
#include "plant.h"

#define HOGWEEDSTRENGTH 10;
#define HOGWEEDSYMBOL '&'
#define HOGWEEDNAME "hogweed";

class Hogweed : public Plant
{
public:
	Hogweed(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	//collision implemented in animal collision as it kills the animal that eats hogweed
	void action(Grid* grid, World* world);
	~Hogweed();
};
