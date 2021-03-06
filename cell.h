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
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
	virtual bool isEmpty();
	void clear();
	void setOrganism(Organism* organism);
	~Cell();
};

class OutOfBounds : public Cell
{
public:
	bool isEmpty() override;
};