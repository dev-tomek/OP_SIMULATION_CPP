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
	char choice = -1;
	World world;
	Wolf wolf2(6, 17, 3, 4);
	Wolf wolf3(9, 12, 4, 6);
	Grass grass(6, 5);
	Sowthistle sowthistle(9, 9);
	Fox fox(15, 2);
	Turtle turtle(13, 4);
	Sheep sheep(2, 19);
	srand(0);

	while (choice != '3')
	{
		printUI();
		std::cin >> choice;
		switch (choice)
		{
		case '1':
		{
			system("CLS");
			world.spawnOrganism(wolf2);
			world.spawnOrganism(wolf3);
			world.spawnOrganism(grass);
			world.spawnOrganism(sowthistle);
			world.spawnOrganism(fox);
			world.spawnOrganism(turtle);
			world.spawnOrganism(sheep);
			int t = 188;
			while (choice != '2')
			{
				t--;
			
				system("CLS");
				world.makeTurn();
				world.drawWorld();
				//choice = getchar(); //sometimes doesn't work as required
				//while (_kbhit()) {};

				

				if (t > 0) continue;
				choice = getchar();
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
//debug the program
//debug sowthistle
//implement turtle's collision
//equal strength problem
//turn starts from turn 2 