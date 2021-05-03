#pragma once
#include <iostream>
#include "organism.h" 
class Organism;

class Cell
{
private:
	Organism* organism;
	int x;
	int y;
public:
	Cell();
	char getSymbol();
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
	bool isEmpty();
	void clear();
	void setOrganism(Organism* organism);
	~Cell();
};