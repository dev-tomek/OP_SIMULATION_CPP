#include <iostream>
#include "stdlib.h"
#include "grid.h"
#include "cell.h"
#include "organism.h"
#include "wolf.h"
#include "world.h"
using namespace std;

void printUI()
{
	cout << "-------------------------" << endl;
	cout << "Author: Tomasz Kuczynski" << endl;
	cout << "Student ID: s184593" << endl;
	cout << "--------MAIN MENU--------" << endl;
	cout << "1. Start a new game" << endl;
	cout << "2. Load a game" << endl;
	cout << "3. Quit" << endl;
	cout << "-------------------------" << endl;
	cout << "Your choice: ";
}

int main()
{
	char choice = -1;
	World world;
	Grid grid;
	Wolf wolf(5, 5);
	Wolf wolf2(10, 10, 3);
	Wolf wolf3(8, 8, 4);
	srand(time(NULL));

	while (choice != '3')
	{
		printUI();
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			system("CLS");
			cout << "--------GAMEPLAY---------" << endl;
			world.spawnOrganism(wolf, grid.worldgrid);
			world.spawnOrganism(wolf2, grid.worldgrid);
			world.spawnOrganism(wolf3, grid.worldgrid);
			grid.drawGrid();
			while (choice != '5')
			{
				wolf.action(grid.worldgrid);
				wolf2.action(grid.worldgrid);
				cin >> choice;
				system("CLS");
				grid.drawGrid();

				//position
				cout << wolf.x << " " << wolf.y << endl;
				cout << wolf2.x << " " << wolf2.y << endl;

				//initiative
				world.makeTurn();
			}

			cout << "-------------------------" << endl;
			cin >> choice;
			system("CLS");
			break;
		}
		case '2':
		{
			system("CLS");

			cout << "LOADING" << endl;
		}
		case '3':
		{
			break;
		}
		default:
		{
			cout << "Choice does not exist." << endl;
			break;
		}
		}

	}
}