#include "cell.h"

Cell::Cell()
{
	this->organism = nullptr;
}

char Cell::getSymbol()
{
	if (this->organism != nullptr) return this->organism->symbol;
	return '.';
}

Cell::~Cell()
{
	std::cout << "default destructor" << std::endl;
}