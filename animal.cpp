#include "animal.h"

Animal::Animal()
{
	cout << "default animal constructor" << endl;
}


void Animal::action(Cell** worldgrid)
{
	//reseting current cell
	worldgrid[this->x][this->y].occupier = "empty";
	worldgrid[this->x][this->y].symbol = '#';

	//random move
	int option;
	option = rand() % 4;
	//goes up
	if (option == 0 && this->x > 0) //making sure x doesn't go out the gird
	{
		this->x--;
	}
	//goes down
	else if (option == 1 && this->x < GRIDHEIGHT)
	{
		this->x++;
	}
	//goes left
	else if (option == 2 && this->y > 0)
	{
		this->y--;
	}
	//goes right
	else if (option == 3 && this->y < GRIDWIDTH)
	{
		this->y++;
	}

	//spawning in the right place
	this->cell = &worldgrid[this->x][this->y];
	worldgrid[this->x][this->y].occupier = this->name;
	worldgrid[this->x][this->y].symbol = this->symbol;
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