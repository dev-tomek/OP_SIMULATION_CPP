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
	Wolf(int _x, int _y, int init, int str);
	Organism* createNew(World* world, int _x, int _y) override;
	~Wolf();
};

