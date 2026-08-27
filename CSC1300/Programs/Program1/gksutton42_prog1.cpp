/*
	Title:  	program_1.cpp
	Author:		Griffin Sutton
	Date:		02/04/26	
	Purpose:	This program is written for the user to answer 10 personality
				questions and calculate which donut type they are based on
				the count of their answers.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//initializing variables
	int choice;
	int count_old_fashioned = 0;
	int count_boston_cream = 0;
	int count_regular_glazed = 0;
	int count_cinnamon = 0;
	int count_cream_filled = 0;
	int count_red_velvet = 0;
	int highest_count = 0;
	string winner_name = "Undetermined";

	//left text alignment.
	cout << left; 

	//display the intro
	cout << "========================================================\n";
	cout << "                DONUT PERSONALITY QUIZ                  \n";
	cout << "   Answer these 10 questions to find your donut match!  \n";
	cout << "========================================================\n";

	//Question 1
	cout << "\n1. What is your ideal Saturday morning?\n"; 
	cout << "   1: Reading\n   2: Drawing\n   3: Painting\n   4: Road Trip\n   5: Cleaning\n   6: Video Games\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 2
	cout << "\n2. How do you handle a crisis?\n";
	cout << "   1: Cry\n   2: Watch\n   3: Act\n   4: Cause Chaos\n   5: Run Away\n   6: Scream\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 3
	cout << "\n3. What is your fashion taste?\n";
	cout << "   1: Vintage\n   2: Business\n   3: Athletic\n   4: Edgy\n   5: Minimal\n   6: Comfy\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 4
	cout << "\n4. If you were a season, which would you be?\n";
	cout << "   1: Winter\n   2: Spring\n   3: Summer\n   4: Fall\n   5: Permafrost\n   6: Hurricane\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 5
	cout << "\n5. What is your favorite type of movie?\n";
	cout << "   1: Thriller\n   2: Horror\n   3: Rom-Com\n   4: Action\n   5: Sci-fi\n   6: Mystery\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 6
	cout << "\n6. How do your friends describe your humor?\n";
	cout << "   1: dark\n   2: Sarcastic\n   3: Goofy\n   4: Shocking\n   5: Witty\n   6: Self-deprecating\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 7
	cout << "\n7. Choose a travel destination:\n";
	cout << "   1: London\n   2: Paris\n   3: Tokyo\n   4: Rome\n   5: Washington DC\n   6: New York\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 8
	cout << "\n8. What is your comfort activity?\n";
	cout << "   1: Puzzles\n   2: Chess\n   3: Reading\n   4: Movies\n   5: Gardening\n   6: Baking\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 9
	cout << "\n9. How do you feel about rules?\n";
	cout << "   1: Neccesary\n   2: Required\n   3: Boring\n   4: Break Them\n   5: Guidelines\n   6: Good\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;

	cout << "\n--------------------------------------------------------";

	//Question 10
	cout << "\n10. What is your social battery like?\n";
	cout << "   1: Steady\n   2: Low Capacity\n   3: Solar\n   4: High Capacity\n   5: Efficient\n   6: Infinite\n";
	cout << "   Enter choice: ";
	cin >> choice;
	
	if (choice == 1) count_old_fashioned += 1;
	else if (choice == 2) count_boston_cream += 1;
	else if (choice == 3) count_regular_glazed += 1;
	else if (choice == 4) count_cinnamon += 1;
	else if (choice == 5) count_cream_filled += 1;
	else if (choice == 6) count_red_velvet += 1;
	
	//winner check
	highest_count = count_old_fashioned;
	winner_name = "Old Fashioned";
	
	if (count_boston_cream > highest_count)
	{
		highest_count = count_boston_cream;
		winner_name = "Boston Cream";
	}
	if (count_regular_glazed > highest_count)
	{
		highest_count = count_regular_glazed;
		winner_name = "Regular Glazed";
	}
	if (count_cinnamon > highest_count)
	{
		highest_count = count_cinnamon;
		winner_name = "Cinnamon";
	}
	if (count_cream_filled > highest_count)
	{
		highest_count = count_cream_filled;
		winner_name = "Cream Filled";
	}
	if (count_red_velvet > highest_count)
	{
		highest_count = count_red_velvet;
		winner_name = "Red Velvet";
	}
	
	//tie check
	if (count_old_fashioned == highest_count && winner_name != "Old Fashioned")
		winner_name += " & Old Fashioned. Guess you should to decide for yourself who you are.";
	
	if (count_boston_cream == highest_count && winner_name != "Boston Cream")
		winner_name += " & Boston Cream. Guess you should to decide for yourself who you are.";
	
	if (count_regular_glazed == highest_count && winner_name != "Regular Glazed")
		winner_name += " & Regular Glazed. Guess you should to decide for yourself who you are.";
	
	if (count_cinnamon == highest_count && winner_name != "Cinnamon")
		winner_name += " & Cinnamon. Guess you should to decide for yourself who you are.";
	
	if (count_cream_filled == highest_count && winner_name != "Cream Filled")
		winner_name += " & Cream Filled. Guess you should to decide for yourself who you are.";
	
	if (count_red_velvet == highest_count && winner_name != "Red Velvet")
		winner_name += " & Red Velvet. Guess you should to decide for yourself who you are.";
	
	//output statement
	cout << "\n========================================================";
	cout << "\n                       RESULTS                          ";
	cout << "\n========================================================\n";
	cout << setw(25) << "Old Fashioned:" << count_old_fashioned << endl;
	cout << setw(25) << "Boston Cream:" << count_boston_cream << endl;
	cout << setw(25) << "Regular Glazed:" << count_regular_glazed << endl;
	cout << setw(25) << "Cinnamon:" << count_cinnamon << endl;
	cout << setw(25) << "Cream Filled:" << count_cream_filled << endl;
	cout << setw(25) << "Red Velvet:" << count_red_velvet << endl;
	cout << "--------------------------------------------------------\n";
	cout << "Based on your answers, your Donut Personality is: " << winner_name << endl;
	
	return 0;
}