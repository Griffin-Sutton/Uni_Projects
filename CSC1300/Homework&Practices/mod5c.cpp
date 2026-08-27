/*
	Title:      mod5c.cpp
	Author:     Griffin Sutton
	Date:       02/25/26	
	Purpose:    DnD Dice Roll for ability scores
*/

#include <iostream>

using namespace std;

int main()
{
	
	string horizontal_line(30, '-');
	
    //Seed the random number generator
    srand(time(0));

    //Intro block
	cout << horizontal_line << endl;
    cout << "DnD Stat Rolls:\n\n";
    cout << "1 - Strength\n\n";
    cout << "2 - Dexterity\n\n";
    cout << "3 - Constitution\n\n";
    cout << "4 - Intelligence\n\n";
    cout << "5 - Wisdom\n\n";
    cout << "6 - Charisma\n";
	cout << horizontal_line << endl;
    cout << "For your character stats, I\n";
    cout << "am rolling a 6-sided die\n";
    cout << "until an ODD dice roll\n";
    cout << "occurs more than once OR the\n";
    cout << "total of all dice rolled so\n";
    cout << "far is equal to or exceeds\n";
    cout << "20, whichever comes first.\n";
	
    cout << "If the total exceeds 20, then\n";
    cout << "the last dice roll is\n";
    cout << "removed.\n\n";
	
    cout << "I will then print the result\n";
    cout << "for each ability score.\n";
	cout << horizontal_line << endl;
	
    //Loop through the 6 abilities
    for (int i = 1; i <= 6; ++i) {
        int score = 0;
        int oddCount = 0;
        int lastRoll = 0;
        int rollCount = 0;

        //Roll until 2nd odd number OR total is >= 20
        while (oddCount <= 1 && score < 20) {
            lastRoll = rand() % 6 + 1;
            score += lastRoll;
            rollCount++;
            
            //Print the individual roll
            cout << "roll\n";
            cout << rollCount << ": " << lastRoll << "\n";
            
            //Check if the roll is odd
            if (lastRoll % 2 != 0) {
                oddCount++;
            }
        }

        //If the total exceeds 20, remove the last roll
        if (score > 20) {
            score -= lastRoll;
        }

        //Print the final output for this specific ability
        cout << horizontal_line << endl;
        cout << "Ability " << i << "\n";
        cout << "Score is\n";
        cout << score << "\n\n";
    }

    return 0;
}