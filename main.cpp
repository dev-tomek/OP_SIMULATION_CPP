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
	std::cout << "3. Instruction" << std::endl;
	std::cout << "4. Quit" << std::endl;
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
	//srand(time(NULL)); different seed every time
	srand(0);

	while (choice != '4')
	{
		printUI();
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			world.restart();
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
				if (world.makeTurn() == 0)
				{
					char goback = '\t';
					std::cout << "GAME OVER!" << std::endl;
					std::cout << "PRESS ANY BUTTON TO GO BACK TO THE MENU" << std::endl;
					goback = _getch();
					if (goback != '\t')
					{
						system("CLS");
						break;
					}
				}
				//if (t > 0) continue;
			}
			break;
		}
		case '2':
		{
			system("CLS");
			std::cout << "LOADING" << std::endl;
		}
		case '3':
		{
			system("CLS");
			std::cout << "-------------------" << std::endl;
			std::cout << "    INSTRUCTION" << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "W - UP" << std::endl;
			std::cout << "S - DOWN" << std::endl;
			std::cout << "A - LEFT" << std::endl;
			std::cout << "D - RIGHT" << std::endl;
			std::cout << "Q - SPECIAL ABILITY" << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "GAME EXPLANATION " << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "You found yourself in wilderness." << std::endl;
			std::cout << "Around you there are plenty of dangerous animals" << std::endl;
			std::cout << "that will easily harm you. You have two choices: " << std::endl;
			std::cout << "Run or fight! " << std::endl;
			std::cout << "{Your special ability is a strength increase} " << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			char goback = _getch();
			if (goback != '\t')
			{
				system("CLS");
				break;
			}
			break;
		}
		case '4':
		{
			break;
		}
		default:
		{
			system("CLS");
			std::cout << "Choice does not exist." << std::endl;
			break;
		}
		}
	}
}