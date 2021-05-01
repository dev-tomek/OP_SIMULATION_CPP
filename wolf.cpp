#include "wolf.h"

Wolf::Wolf()
{
	cout << "wolf created" << endl;
	this->name = WOLFNAME;
	this->symbol = WOLFSYMBOL;
	this->strength = WOLFSTRENGTH;
	this->initiative = WOLFINITIATIVE;
}

Wolf::~Wolf()
{
	cout << "default destructor" << endl;
}