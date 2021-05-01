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
	Grid grid;
	Wolf wolf;

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
			grid.drawGrid();
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