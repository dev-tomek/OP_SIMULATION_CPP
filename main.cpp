#include <iostream>
#include <conio.h>
#include "stdlib.h"
#include "grid.h"
#include "cell.h"
#include "organism.h"
#include "wolf.h"
#include "world.h"
#include "grass.h"
#include "sowthistle.h"
#include "sheep.h"
#include "fox.h"
#include "turtle.h"
#include "antelope.h"
#include "guarana.h"
#include "belladonna.h"
#include "sosnowskyhogweed.h"
#include "human.h"

void printUI()
{
	std::cout << "-------------------------" << std::endl;
	std::cout << "Author: Tomasz Kuczynski" << std::endl;
	std::cout << "Student ID: s184593" << std::endl;
	std::cout << "--------MAIN MENU--------" << std::endl;
	std::cout << "1. Start" << std::endl;
	std::cout << "2. Continue" << std::endl;
	std::cout << "3. Quit" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Your choice: ";
}

int main()
{
	unsigned char choice = -1;
	World world;
	Wolf wolf(13, 5);
	Wolf wolf2(13, 15);
	Grass grass(6, 5);
	Sowthistle sowthistle(9, 9);
	Fox fox(15, 2);
	Turtle turtle(13, 10);
	Sheep sheep(2, 19);
	Antelope antelope(6, 13);
	Antelope antelope2(7, 12);
	Guarana guarana(19, 19);
	Belladonna belladonna(2, 8);
	Hogweed hogweed(10, 10);
	Human human(7, 15);
	srand(time(NULL));

	while (choice != '3')
	{
		printUI();
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			system("CLS");
			world.spawnOrganism(wolf);
			world.spawnOrganism(wolf2);
			world.spawnOrganism(grass);
			world.spawnOrganism(sowthistle);
			world.spawnOrganism(fox);
			world.spawnOrganism(turtle);
			world.spawnOrganism(sheep);
			world.spawnOrganism(antelope);
			world.spawnOrganism(antelope2);
			world.spawnOrganism(guarana);
			world.spawnOrganism(belladonna);
			world.spawnOrganism(hogweed);
			world.spawnOrganism(human);
			int t = 400;
			while (choice != '2')
			{
				t--;
			
				system("CLS");
				world.drawWorld();
				world.makeTurn();
				//choice = getchar(); //sometimes doesn't work as required

				//if (t > 0) continue;
			}
			//system("CLS");
			break;
		}
		case '2':
		{
			system("CLS");

			std::cout << "LOADING" << std::endl;
		}
		case '3':
		{
			break;
		}
		default:
		{
			std::cout << "Choice does not exist." << std::endl;
			break;
		}
		}
	}
}

//todo
//implement turtle's collision
//turn starts from turn 2 