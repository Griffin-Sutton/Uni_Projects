/*
	Title:  	functions.cpp
	Author:		Griffin Sutton
	Date:		04/27/26	
	Purpose:	Function implementations for the Superhero Condo program.
*/

#include "prog5.h"

/*
	Function Name: enterHeroes
	Purpose: Allows the user to load heroes from a file or enter them manually.
*/
int enterHeroes(int max, int numHeroes, Heroes* heroList)
{
	// Check capacity first
	if (numHeroes >= max)
	{
		cout << "Sorry! Your complex can only hold " << max << " heroes. You cannot add more.\n";
		return numHeroes;
	}

	int choice;
	cout << "What do you want to do?\n";
	cout << "1. Load the heroes from a file.\n";
	cout << "2. Enter a hero manually.\n";
	cout << "Choose 1 or 2.\nCHOICE: ";
	cin >> choice;

	while (!cin || (choice != 1 && choice != 2))
	{
		cout << "Invalid input. Choose 1 or 2.\nCHOICE: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	string filename;
	ifstream inputFile;
	string data;
	int numHeroesFromFile = 0;

	switch (choice)
	{
		case 1: // Load heroes from a file
			cout << "What is the name of the file with your list of superheroes? (ex: filename.txt)\n";
			cin.ignore(10000, '\n');
			cout << "FILENAME:  ";
			getline(cin, filename);
			cout << endl;

			inputFile.open(filename, ios::in);

			if (!inputFile)
			{
				cout << filename << " does not exist or is corrupt. Sorry. Can't load heroes.\n";
				return numHeroes;
			}
			
			// Load heroes from file	
			while (getline(inputFile, data, '#') && numHeroes < max)
			{
				heroList[numHeroes].name = data;
				getline(inputFile, heroList[numHeroes].description, '#');
				getline(inputFile, data, '#');
				heroList[numHeroes].dangerous = stoi(data);
				getline(inputFile, data, '#');
				heroList[numHeroes].rentPrice = stof(data);
				getline(inputFile, data, '#');
				heroList[numHeroes].damageCost = stof(data);
				
				// Read until '#' for the last item 
				getline(inputFile, data, '#');
				heroList[numHeroes].numYears = stof(data);

				numHeroes++;
				numHeroesFromFile++;
			}
			inputFile.close();
			inputFile.clear();

			cout << "\n" << numHeroesFromFile << " heroes from " << filename << " have been added to your condo complex.\n";
			break;

		case 2: // Enter one hero manually
		{
			char addMore = 'y';
			cin.ignore(10000, '\n'); // clear buffer for getline
			
			do
			{
				if (numHeroes >= max)
				{
					cout << "Sorry! Your complex can only hold " << max << " heroes. You cannot add more.\n";
					break;
				}

				cout << "SUPERHERO NAME: ";
				getline(cin, heroList[numHeroes].name);

				cout << "DESCRIPTION: ";
				getline(cin, heroList[numHeroes].description);

				char danger;
				cout << "IS IT A DANGEROUS HERO? (y or n): ";
				cin >> danger;
				while (!cin || (tolower(danger) != 'y' && tolower(danger) != 'n'))
				{
					cout << "Invalid input. Please enter 'y' or 'n': ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> danger;
				}
				
				if (tolower(danger) == 'y')
					heroList[numHeroes].dangerous = true;
				else
					heroList[numHeroes].dangerous = false;

				cout << "How much does " << heroList[numHeroes].name << " pay for rent per month?\n";
				cout << "RENT PRICE: $";
				cin >> heroList[numHeroes].rentPrice;

				cout << "What is the typical cost of damage " << heroList[numHeroes].name << " has each month?\n";
				cout << "DAMAGE COST: $";
				cin >> heroList[numHeroes].damageCost;

				cout << "How many years has " << heroList[numHeroes].name << " lived in your condo?\n";
				cout << "YEARS: ";
				cin >> heroList[numHeroes].numYears;

				cout << "The " << heroList[numHeroes].name << " has been added.\n";
				numHeroes++;

				if (numHeroes < max)
				{
					cout << "Want to add more heroes? (y or n) ";
					cin >> addMore;
					while (!cin || (tolower(addMore) != 'y' && tolower(addMore) != 'n'))
					{
						cout << "Please enter 'y' or 'n': ";
						cin.clear();
						cin.ignore(10000, '\n');
						cin >> addMore;
					}
					cin.ignore(10000, '\n');
				}
				else
				{
					addMore = 'n';
				}
			} while (tolower(addMore) == 'y');
			
			break;
		}
	} // end of switch

	return numHeroes;
}

/*
	Function Name: moveArrayElements
	Purpose: Finds a hero by name and removes them, shifting the rest of the array elements.
*/
bool moveArrayElements(string heroName, int numHeroes, Heroes* heroList)
{
	string lowerSearch = "";
	for (size_t i = 0; i < heroName.length(); i++)
		lowerSearch += tolower(heroName[i]);

	for (int i = 0; i < numHeroes; i++)
	{
		string currentHero = "";
		for (size_t j = 0; j < heroList[i].name.length(); j++)
			currentHero += tolower(heroList[i].name[j]);

		if (currentHero == lowerSearch)
		{
			// Shift elements to the left to overwrite the deleted hero
			for (int j = i; j < numHeroes - 1; j++)
			{
				heroList[j] = heroList[j + 1];
			}
			return true;
		}
	}
	return false;
}

/*
	Function Name: deleteHero
	Purpose: Displays all heroes and asks the user which one they would like to remove.
*/
int deleteHero(int numHeroes, Heroes* heroList)
{
	if (numHeroes == 0)
	{
		cout << "You have no heroes to delete.\n";
		return numHeroes;
	}

	cout << "The following is a list of all the heroes living in your condo complex:\n";
	for (int i = 0; i < numHeroes; i++)
	{
		cout << heroList[i].name << endl;
	}

	cout << "Which hero are you kicking out of your complex?\n";
	cout << "SUPERHERO NAME: ";
	string nameToDelete;
	cin.ignore(10000, '\n');
	getline(cin, nameToDelete);

	bool removed = moveArrayElements(nameToDelete, numHeroes, heroList);

	if (removed)
	{
		numHeroes--;
		cout << "You have removed " << nameToDelete << ".\n";
	}
	else
	{
		cout << "Sorry, a hero by the name " << nameToDelete << " could not be found.\n";
	}

	return numHeroes;
}

/*
	Function Name: printHeroes
	Purpose: Prints all heroes and their details. Implements bonus word-wrapping.
*/
void printHeroes(int numHeroes, Heroes* heroList)
{
	for (int i = 0; i < numHeroes; i++)
	{
		cout << "\n---SUPERHERO " << (i + 1) << "---\n";
		cout << left << setw(15) << "NAME:" << heroList[i].name << endl;
		
		// Bonus: Word wrapping logic for description
		cout << left << setw(15) << "DESCRIPTION:";
		string desc = heroList[i].description;
		int maxLineLength = 55; 
		int currentLineLength = 0;
		string word = "";

		for (size_t j = 0; j < desc.length(); j++)
		{
			// When we hit a space or the end of the description string
			if (desc[j] == ' ' || j == desc.length() - 1)
			{
				if (j == desc.length() - 1 && desc[j] != ' ')
					word += desc[j];

				if (currentLineLength + word.length() > (size_t)maxLineLength)
				{
					cout << "\n" << setw(15) << " "; // Indent the next line
					currentLineLength = 0;
				}
				
				cout << word << " ";
				currentLineLength += word.length() + 1;
				word = "";
			}
			else
			{
				word += desc[j];
			}
		}
		cout << endl;

		cout << left << setw(15) << "DANGEROUS?";
		if (heroList[i].dangerous) 
			cout << "yes\n";
		else 
			cout << "no\n";

		cout << left << setw(15) << "RENT PRICE:" << "$ " << fixed << setprecision(2) << heroList[i].rentPrice << endl;
		cout << left << setw(15) << "DAMAGE COST:" << "$ " << fixed << setprecision(2) << heroList[i].damageCost << endl;
		cout << left << setw(15) << "YEARS:" << fixed << setprecision(2) << heroList[i].numYears << endl;
	}
}

/*
	Function Name: printRentDetails
	Purpose: Prints a formatted table using setw showing rent details and damage costs.
*/
void printRentDetails(int numHeroes, Heroes* heroList)
{
	float totalRent = 0.0;
	float totalDamage = 0.0;

	cout << "\nRENT DETAILS OF EACH HERO:\n";
	cout << left << setw(20) << "SUPERHERO" 
		 << right << setw(15) << "MONTHLY RENT" 
		 << right << setw(15) << "DAMAGE COST" << endl;

	for (int i = 0; i < numHeroes; i++)
	{
		cout << left << setw(20) << heroList[i].name 
			 << right << setw(4) << "$" << setw(11) << fixed << setprecision(2) << heroList[i].rentPrice 
			 << right << setw(4) << "$" << setw(11) << fixed << setprecision(2) << heroList[i].damageCost << endl;
		
		totalRent += heroList[i].rentPrice;
		totalDamage += heroList[i].damageCost;
	}

	cout << left << setw(20) << "TOTALS:" 
		 << right << setw(4) << "$" << setw(11) << fixed << setprecision(2) << totalRent 
		 << right << setw(4) << "$" << setw(11) << fixed << setprecision(2) << totalDamage << endl;
}

/*
	Function Name: saveToFile
	Purpose: Saves the array of heroes to a text file separated by '#' without endlines.
*/
void saveToFile(int numHeroes, Heroes* heroList)
{
	string filename;
	cout << "What is the name of the file you want to save your heroes to?\nFILENAME: ";
	cin.ignore(10000, '\n');
	getline(cin, filename);

	ofstream outFile(filename);

	if (outFile.is_open())
	{
		for (int i = 0; i < numHeroes; i++)
		{
			outFile << heroList[i].name << "#"
					<< heroList[i].description << "#"
					<< heroList[i].dangerous << "#"
					<< heroList[i].rentPrice << "#"
					<< heroList[i].damageCost << "#"
					<< heroList[i].numYears << "#";
		}
		outFile.close();
		cout << "Your superheroes were successfully saved to the " << filename << " file.\n";
	}
	else
	{
		cout << "Error opening file for writing.\n";
	}
}