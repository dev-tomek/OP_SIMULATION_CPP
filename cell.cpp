#include "cell.h"

Cell::Cell()
{
	this->organism = nullptr;
	this->symbol = '#';
	this->occupied = false;
}

void Cell::updateSymbol(Organism* organism)
{
	this->symbol = organism->symbol;
}

Cell::~Cell()
{
	cout << "default destructor" << endl;
}