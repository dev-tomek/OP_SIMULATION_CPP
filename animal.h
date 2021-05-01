#pragma once
#include <iostream>
#include "organism.h"
#include "grid.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Animal : public Organism
{
public:
	Animal();
	~Animal();
	virtual void action(Cell** worldgrid);
	virtual void collision();
	virtual void draw();
};

