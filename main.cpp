#include <iostream>
#include <conio.h>
#include "stdlib.h"
#include "grid.h"
#include "cell.h"
#include "organism.h"
#include "wolf.h"
#include "world.h"

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
	Wolf wolf2(6, 6, 3, 4);
	Wolf wolf3(6, 7, 4, 6);
	srand(time(NULL));

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
			while (choice != '2')
			{
				world.drawWorld();
				world.makeTurn();
				std::cout << wolf2.x << " " << wolf2.y << std::endl;
				std::cout << wolf3.x << " " << wolf3.y << std::endl;
				//std::cin >> choice;
				choice = _getch(); //sometimes doesn't work as required
				system("CLS");

				//position
			}
			system("CLS");
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
//write a polymorphic function that will spawn any organism you pass by its name
//breed
//kill
//some idea for loading the game state