#include "cell.h"

Cell::Cell()
{
	this->symbol = '.';
	this->organism = nullptr;
}

Cell::~Cell()
{
	std::cout << "default destructor" << std::endl;
}