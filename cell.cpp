#include "cell.h"

Cell::Cell()
{
	this->organism = nullptr;
	this->x = 0;
	this->y = 0;
}

char Cell::getSymbol()
{
	if (!this->isEmpty()) return this->organism->symbol;
	return '.';
}

int Cell::getX()
{
	return this->x;
}

int Cell::getY()
{
	return this->y;
}

void Cell::setX(int value)
{
	this->x = value;
}

void Cell::setY(int value)
{
	this->y = value;
}

bool Cell::isEmpty()
{
	return organism == nullptr;
}

bool OutOfBounds::isEmpty()
{
	return false;
}

void Cell::clear()
{
	this->organism = nullptr;
}

void Cell::setOrganism(Organism* organism)
{
	this->organism = organism;
}

Cell::~Cell()
{
	std::cout << "default destructor" << std::endl;
}