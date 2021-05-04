#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "world.h"
#include "organism.h"
#include "grid.h"

class Organism;
class Grid;
class World;

class Animal : public Organism
{
public:
	Animal();
	~Animal();
	virtual void action(Grid* grid, World* world);
	virtual int collision(Organism* _organism);
	virtual char draw();
	virtual void move();
	virtual bool collisionResult(int attackerState, int occupierState, World* world, Organism* occupier);
};

