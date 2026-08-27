/*
	Title:  	lab10.cpp
	Author:		Griffin Sutton
	Date:		04/15/26	
	Purpose:	A program that allows the user to dynamically create, store, 
				and cast spells from a digital spell book.
*/

#include "lab10.h"

//main function
int main(){
	
	//initializing variables
	int max_spell_count = 0;
	
	//display the intro
	cout << "\nWelcome to your very own digital spell book!" << endl;
	cout << "How many spells can your digital spell book hold: ";
	cin >> max_spell_count;
	
	while (max_spell_count <= 0){
		cout << "\nThat is an invalid amount, please enter a positive number: ";
		cin >> max_spell_count;
	}
	
	//dynamic memory allocation
	spell* spellbook = new spell[max_spell_count];
	int spell_count = 0;
	int choice = 0;
	bool run = true;
	
	do {
		
		//menu output
		display_menu();
		
		cin >> choice;
		while (!cin || choice > 5 || choice < 1){
			cout << "That was an invalid choice, please choose an option 1 - 5: ";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choice;
		}
		
		//switch case to run selected choice
		switch (choice){
			
			//add a spell
			case 1:{
				learn_spell(spellbook, spell_count, max_spell_count);
				break;
			}
			
			//cast a spell
			case 2:{
				cast_spell(spellbook, spell_count);
				break;
			}
			
			//display top spells
			case 3:{
				display_top_spells(spellbook, spell_count);
				break;
			}
			
			//display extreme spells
			case 4:{
				display_extreme_spells(spellbook, spell_count);
				break;
			}
			
			//quit playing
			case 5:{
				cout << "The spellbook will be banished, goodbye.\n";
				run = false;
				break;
			}
		}
		
	} while (run == true);
	
	//cleanup dynamic memory
	delete [] spellbook;
	
	return 0;
}

/*
Function Name: display_menu
Purpose: Show the menu and let the user choose an option (1-5).
*/
void display_menu(){
	cout << "\n<----- Digital Spell Book Menu ----->\n";
	cout << "1. Add a spell to the book\n";
	cout << "2. Cast a spell from the book\n";
	cout << "3. Display the top 3 most powerful spells\n";
	cout << "4. Display the most and least powerful spells\n";
	cout << "5. Banish the digital spell book (Quit)\n";
	cout << "Enter your choice into the book: ";
}

/*
Function Name: learn_spell
Purpose: Prompts the user for spell details and adds it to the dynamically 
allocated array if there is available capacity.
*/
void learn_spell(spell* spellbook, int& spell_count, int max_spell_count){
	
	if (spell_count >= max_spell_count){
		cout << "Your spell book is full, you cannot add any new spells.\n";
		return;
	}
	
	cout << "\nEnter the spell's name: ";
	cin.ignore(10000, '\n');
	getline(cin, spellbook[spell_count].spell_name);
	
	cout << "Enter the spell's element: ";
	getline(cin, spellbook[spell_count].element);
	
	cout << "Enter the spell's power level: ";
	cin >> spellbook[spell_count].power_level;
	
	while (!cin || spellbook[spell_count].power_level < 0){
		cout << "Power level cannot be negative. Enter a valid power level: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> spellbook[spell_count].power_level;
	}
	
	spellbook[spell_count].is_learned = false;
	spell_count++;
	
	cout << "Spell successfully scribed into your book!\n";
}

/*
Function Name: cast_spell
Purpose: Lists available spells and allows the user to mark a specific spell 
as cast/learned.
*/
void cast_spell(spell* spellbook, int spell_count){
	
	if (spell_count == 0){
		cout << "Your spell book is empty. Add a spell first!\n";
		return;
	}

	cout << "\n<--- Spells in Book --->\n";
	for (int i = 0; i < spell_count; i++){
		cout << i + 1 << ". " << spellbook[i].spell_name;
		if (spellbook[i].is_learned == true){
			cout << " (Already cast)";
		}
		cout << "\n";
	}

	int index;
	cout << "Enter the number of the spell you wish to cast: ";
	cin >> index;

	if (index > 0 && index <= spell_count){
		spellbook[index - 1].is_learned = true;
		cout << "You cast " << spellbook[index - 1].spell_name << "!\n";
	} 
	else {
		cout << "Invalid spell number.\n";
	}
}

/*
Function Name: display_top_spells
Purpose: Sorts a temporary copy of the spellbook to display the top 3 
most powerful spells without altering the original array's order.
*/
void display_top_spells(spell* spellbook, int spell_count){
	
	if (spell_count == 0){
		cout << "Your spell book is empty.\n";
		return;
	}

	cout << "\n<--- Top Most Powerful Spells --->\n";
	
	spell* temp = new spell[spell_count];
	for(int i = 0; i < spell_count; i++){
		temp[i] = spellbook[i];
	}

	for(int i = 0; i < spell_count - 1; i++){
		for(int j = 0; j < spell_count - i - 1; j++){
			if(temp[j].power_level < temp[j+1].power_level){
				spell swap = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = swap;
			}
		}
	}

	int limit = spell_count;
	if (spell_count > 3){
		limit = 3;
	}

	for(int i = 0; i < limit; i++){
		cout << i + 1 << ". " << temp[i].spell_name 
			 << " (Power: " << temp[i].power_level << ")\n";
	}

	delete[] temp;
}

/*
Function Name: display_extreme_spells
Purpose: Iterates through the spell array to locate and display both the most 
powerful and the least powerful spells currently in the book.
*/
void display_extreme_spells(spell* spellbook, int spell_count){
	
	if (spell_count == 0){
		cout << "Your spell book is empty.\n";
		return;
	}

	int max_index = 0;
	int min_index = 0;

	for (int i = 1; i < spell_count; i++){
		if (spellbook[i].power_level > spellbook[max_index].power_level){
			max_index = i;
		}
		if (spellbook[i].power_level < spellbook[min_index].power_level){
			min_index = i;
		}
	}

	cout << "\n<--- Most Powerful Spell --->\n";
	cout << "Name: " << spellbook[max_index].spell_name << " | Power: " << spellbook[max_index].power_level << "\n";

	cout << "\n<--- Least Powerful Spell --->\n";
	cout << "Name: " << spellbook[min_index].spell_name << " | Power: " << spellbook[min_index].power_level << "\n";
}