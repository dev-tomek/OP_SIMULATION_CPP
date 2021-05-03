#pragma once
#include <iostream>
#include "organism.h" 
class Organism;

class Cell
{
public:
	Organism* organism;
	int x;
	int y;
public:
	Cell();
	char getSymbol();
	~Cell();
};