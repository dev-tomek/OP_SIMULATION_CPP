#pragma once
#include <iostream>
#include "animal.h"

#define SHEEPSTRENGTH 4;
#define SHEEPINITIATIVE 4;
#define SHEEPSYMBOL '='
#define SHEEPNAME "sheep";

class Sheep : public Animal
{
public:
	Sheep(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	~Sheep();
};

