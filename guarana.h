#pragma once
#include <iostream>
#include "plant.h"

#define GUARANASTRENGTH 0;
#define GUARANASYMBOL 'g'
#define GUARANANAME "guarana";

class Guarana : public Plant
{
public:
	Guarana(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	//collision which increases strength was implemented in animal collision
	~Guarana();
};
