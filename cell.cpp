#include "cell.h"

Cell::Cell()
{
	this->symbol = '#';
	this->occupier = "empty";
}


Cell::~Cell()
{
	std::cout << "default destructor" << std::endl;
}