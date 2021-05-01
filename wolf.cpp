#include "wolf.h"

Wolf::Wolf(int _x, int _y)
{
	cout << "wolf created" << endl;
	this->name = WOLFNAME;
	this->symbol = WOLFSYMBOL;
	this->strength = WOLFSTRENGTH;
	this->initiative = WOLFINITIATIVE;
	this->x = _x;
	this->y = _y;
}

Wolf::~Wolf()
{
	cout << "default destructor" << endl;
}