#pragma once
#include <iostream>
#include "organism.h" 
class Organism;

class Cell
{
public:
	Organism* organism;
	char symbol;
	int x;
	int y;
public:
	Cell();
	~Cell();
};