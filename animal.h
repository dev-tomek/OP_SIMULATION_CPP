#pragma once
#include <iostream>
#include "organism.h"
using namespace std;

class Animal : public Organism
{
public:
	Animal();
	~Animal();
	virtual void action();
	virtual void collision();
	virtual void draw();
};

