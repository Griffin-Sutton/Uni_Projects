/*
	Title:  	driver.cpp
	Author:		Griffin Sutton
	Date:		04/27/26	
	Purpose:	Main driver for Superhero Condo program. Handles the main menu, 
                dynamic memory allocation, and freeing memory.
*/

#include "prog5.h"

int main()
{
	int maxHeroes = 0;
	int numHeroes = 0;
	int choice = 0;

	// Ask for max capacity
	cout << "How many superheroes can your condo complex hold? ";
	cin >> maxHeroes;

	// Validate input
	while (!cin || maxHeroes < 1)
	{
		cout << "Please enter a valid number greater than 0: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> maxHeroes;
	}

	// Dynamically allocate the array of Heroes
	Heroes* heroList = new Heroes[maxHeroes];

	// Main Menu Loop
	do
	{
		cout << "\nWhat would you like to do?\n";
		cout << "1. Enter some superheroes\n";
		cout << "2. Delete a superhero\n";
		cout << "3. Print all superheroes\n";
		cout << "4. Print rent details.\n";
		cout << "5. End Program\n";
		cout << "Enter 1, 2, 3, 4, or 5.\n";
		cout << "CHOICE: ";
		cin >> choice;

		// Validate menu choice
		while (!cin || choice < 1 || choice > 5)
		{
			cout << "Invalid input. Enter 1, 2, 3, 4, or 5.\nCHOICE: ";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choice;
		}

		switch (choice)
		{
			case 1:
				numHeroes = enterHeroes(maxHeroes, numHeroes, heroList);
				break;
			case 2:
				numHeroes = deleteHero(numHeroes, heroList);
				break;
			case 3:
				printHeroes(numHeroes, heroList);
				break;
			case 4:
				printRentDetails(numHeroes, heroList);
				break;
			case 5:
			{
				char saveChoice;
				cout << "Would you like to save your superheroes list to a file? (y or n)\n";
				cin >> saveChoice;
				
				// Validate save choice
				while (!cin || (tolower(saveChoice) != 'y' && tolower(saveChoice) != 'n'))
				{
					cout << "Please enter 'y' or 'n': ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> saveChoice;
				}
				
				if (tolower(saveChoice) == 'y')
				{
					saveToFile(numHeroes, heroList);
				}
				
				cout << "GOODBYE!\n";
				break;
			}
		}
	} while (choice != 5);

	// Free dynamically allocated memory to prevent memory leaks
	delete[] heroList;

	return 0;
}