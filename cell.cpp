#include "cell.h"

Cell::Cell()
{
	this->symbol = '#';
	//this->occupier = false;
}


Cell::~Cell()
{
	std::cout << "default destructor" << std::endl;
}