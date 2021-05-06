#pragma once
#include <iostream>
#include "animal.h"

#define WOLFSTRENGTH 9;
#define WOLFINITIATIVE 5;
#define WOLFSYMBOL '>'
#define WOLFNAME "wolf";

class Wolf : public Animal
{
public:
	Wolf(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	~Wolf();
};

