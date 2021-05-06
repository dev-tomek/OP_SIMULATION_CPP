#pragma once
#include <iostream>
#include "plant.h"

#define BELLADONNASTRENGTH 99;
#define BELLADONNASYMBOL 'B'
#define BELLADONNANAME "belladonna";

class Belladonna : public Plant
{
public:
	Belladonna(int _x, int _y);
	Organism* createNew(Cell* cell) override;
	//since it has the highest strength in the game
	//it doesn't require special collision system in order
	//to fulfill its special collision ability
	~Belladonna();
};
