#include "animal.h"

Animal::Animal()
{
	cout << "default animal constructor" << endl;
}

void Animal::action()
{
	cout << "action" << endl;
}

void Animal::collision()
{
	cout << "collision" << endl;
}

void Animal::draw()
{
	cout << "draw" << endl;
}

Animal::~Animal()
{
	cout << "default destructor" << endl;
}