/*
	Title:  	Prog2.cpp
	Author:		Griffin Sutton
	Date:		02/28/26	
	Purpose:	A collection of three interactive dice games 
	(Roll Call, Over/Under, and Lucky Dice) that simulate 
	random dice rolls, track points, and calculate the total 
	number of games won against games played.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

//function prototypes
int display_menu_choice();
int roll_dice();
int lucky_dice(string player_name);

//main function
int main(){
	
	//vairable initialization and seed
	int games_played = 0, games_won = 0, choice = 0;
	srand(time(0));
	
	//menu output
	cout << "------------------------------DICE GAMES------------------------------\n";
	cout << "This program offers three unique dice games for the user to play.\n";
	cout << "Roll Call allows you to guess the total roll of two 6-sided die.\n";
	cout << "Over Under tells you the total roll of two 6-sided die and have you\n";
	cout << "guess if the next roll will be over, under, or match\n";
	cout << "Lucky Dice allows you to roll two 6-sided die until you want to hold\n";
	cout << "your points. But be careful, if you roll doubles you lose all\n";
	cout << "your points. You can play against friends too!\n";
	cout << "----------------------------------------------------------------------\n";
	
	do {
		
		//call dice game choice selection
		choice = display_menu_choice();
		
		//play dice game chosen
		switch(choice){
			
			//roll call game
			case 1:{
				
				int guess = 0, total = 0;
				cout << "\nWhat do you think the total of two numbers will be: ";
				cin >> guess;
				
				while (!cin || guess > 12 || guess < 2){
					cout << "\nThat isn't a valid input. Please choose 2-12: ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> guess;
				}
				
				total = roll_dice();
				
				cout << "\nThe total is " << total;
				if (guess == total){
					cout << "\nYou guessed right!";
					games_won++;
				}
				else
					cout << "\nYou didn't get it this time!";
				games_played++;
				break;
			}
			
			//over under game
			case 2:{
				int original_roll = roll_dice(), second_roll = roll_dice();
				char guess;
				bool win = false;
				
				cout << "The first roll was " << original_roll;
				cout << "\nDo you think the next roll will be over, under, or match the first roll?\n";
				cout << "Enter O (over), U (under), or M (match): ";
				cin >> guess;
				
				while (!cin || (toupper(guess) != 'O' && toupper(guess) != 'U' && toupper(guess) != 'M')){
					cout << "That isn't a valid input. Please choose O, U, or M: ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> guess;
				}
				
				if ((toupper(guess) == 'O' && second_roll > original_roll) ||
					(toupper(guess) == 'U' && second_roll < original_roll) ||
					(toupper(guess) == 'M' && second_roll == original_roll)){
					win = true;
				}
				
				cout << "The second roll was " << second_roll;
				
				if (win == true){
					cout << "\nYou guessed right!";
					games_won++;
				}
				else
					cout << "\nYou didn't get it this time!";
				
				games_played++;
				break;
			}
			
			//lucky dice game
			case 3:{
				int player_count, high_score = -1;
				string winning_player;
				
				cout << "How many people will be playing: ";
				cin >> player_count;
				
				while (!cin || player_count < 1){
					cout << "That isn't a valid input. Please choose a number above 0: ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> player_count;
				}
				cin.ignore(10000, '\n');
				
				for (int i = 1; i <= player_count; i++){
					string player_name;
					cout << "what is the name of player " << i << ": ";
					getline(cin, player_name);
					
					int score = lucky_dice(player_name);
					
					if (score > high_score){
						high_score = score;
						winning_player = player_name;
					}
				}
				
				if (high_score > 0){
					cout << winning_player << " won with " << high_score << " points.";
					games_won++;
				}
				games_played++;
				break;
			}
			case 4:{
				break;
			}
		}
	} while (choice != 4);
	
	//final output
	cout << "You won " << games_won << " out of the " << games_played << " games you played!\nGoodbye!\n";
	
	return 0;
}

/*
Function Name: displayMenuGetChoice
Purpose: Show the menu and let the user choose an option (1-4).
*/
int display_menu_choice(){
	
	int choice = 0;
	
	cout << "\n\nWhat would you like to play?\n";
	cout << "1. Roll Call\n";
	cout << "2. Over Under\n";
	cout << "3. Lucky Dice\n";
	cout << "4. Quit playing\n";
	cout << "Please choose 1-4: ";
	cin >> choice;
	
	while (!cin || choice > 4 || choice < 1)
	{
		cout << "\nThat isn't a valid input. Please choose 1-4: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}
	
	return choice;
}

/*
Function Name: rollDice
Purpose: Simulates rolling two dice (6 sided) and returns the total.
*/
int roll_dice(){
	
	int dice1 = rand() % 6 + 1, dice2 = rand() % 6 + 1;
	
	return dice1 + dice2;
}

/*
Function Name: luckyDice
Purpose: Allows the player to choose to keep rolling two dice or stop 
with their current points. Ends turn on doubles.
*/
int lucky_dice(string player_name){
	
	int total_points = 0;
	char choice;
	bool rolling = true;
	
	do {
		
		int dice1 = rand() % 6 + 1, dice2 = rand() % 6 + 1;
		cout << player_name << " rolled a " << dice1 << " and " << dice2 << ".\n";
		
		if (dice1 == dice2){
			cout << player_name << " rolled doubles! the game is over.\n";
			return 0;
		}
		
		total_points += (dice1 + dice2);
		cout << player_name << " has " << total_points << " points.\n";
		
		cout << "Would you like to roll again?\nEnter Y or N: ";
		cin >> choice;
		
		while (!cin || (toupper(choice) != 'Y' && toupper(choice) != 'N')){
				cout << "That isn't a valid input. Please enter Y or N: ";
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> choice;
		}
		
		cin.ignore(10000, '\n');
		
		if (toupper(choice) == 'N'){
			rolling = false;
			cout << player_name << " is stopping at " << total_points << " points.\n";
		}
		
		
	} while (rolling == true);
	
	return (total_points);
}