#pragma once
#include "organism.h"

class Cell
{
public:
	Organism* organism;
	char symbol;
	bool occupied;
public:
	Cell();
	~Cell();
	void updateSymbol(Organism* organism);
};