#pragma once
#include <iostream>
#include "plant.h"

#define GRASSSTRENGTH 0;
#define GRASSSYMBOL '#'
#define GRASSNAME "grass";

class Grass : public Plant
{
public:
	Grass(int _x, int _y);
	Grass(int _x, int _y, int init, int str);
	Organism* createNew(Cell* cell) override;
	~Grass();
};
