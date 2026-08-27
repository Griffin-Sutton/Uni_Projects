/*
	Title:      lab_4.cpp
	Author:     Griffin Sutton
	Date:       02/18/26	
	Purpose:    Text Game about a mathematician trying to work his way through a 
				math dungeon full of math monsters to get to treasure
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	
	//variable initialization
	string horizontal_line(100, '-'), mathematician, restart_choice, q1_answer, q4_answer;
	int answer;
	bool fisch = false;
	srand(time(0));
	int rnumber1 = rand() % 9 + 1, rnumber2 = rand() % 4 + 1, rnumber3 = rand() % 49 + 1;
	
	do
	{
	
		//reset death statement and value
		string math_dead = "You didn't answer correctly. The monster tears you apart... GAME OVER.";
		bool is_alive = true;
		
		//opening statement
		cout << endl;
		cout << horizontal_line << endl;
		cout << "Welcome to the Math Dungeon!" << endl;
		cout << horizontal_line << endl;
		cout << "You have just discovered the entrance to a dungeon full of terrifying   " << endl;
		cout << "math monsters. They can only be defeated by shouting the correct answer " << endl;
		cout << "to their equations. There are great rewards for those who reach the end!" << endl;
		cout << "2 + 2 = fish..." << endl;
		cout << horizontal_line << endl;
		cout << "What is the name of the brave mathematician entering the dungeon? \n> ";
		getline(cin, mathematician);
		
		//question 1
		cout << horizontal_line << endl;
		cout << "As " << mathematician << " enters the first layer, the cave reveals itself as a massive, " << endl;
		cout << "dimly lit hallway. Slowly, the heavy stone door behind you begins to  " << endl;
		cout << "close, plunging the cave into darkness. Suddenly, torches ignite along" << endl;
		cout << "the walls, casting flickering shadows. The cave is brighter, but still" << endl;
		cout << "too dark to see far. Up ahead, " << mathematician << " spots a rabbit with glowing red " << endl;
		cout << "eyes full of killer intent. It scurries over and whispers: \"2 + 2?\"" << endl;
		cout << horizontal_line << endl;
		cout << "What does " << mathematician << " respond with? \n> ";
		getline(cin, q1_answer);
		
		//correct
		cout << horizontal_line << endl;
		if (q1_answer == "4")
			cout << "You answered correctly. The rabbit loses interest and lets you pass." << endl;
		
		//incorrect + secret true solution
		else
		{
			if (q1_answer == "Fish" || q1_answer == "fish")
			{
				math_dead = "I bet you think you're a funny person. You should confront the Koi Fish. " + math_dead;
				fisch = true;
			}
			
			is_alive = false;
			cout << math_dead << endl;
		}
		
		//question 2
		if (is_alive == true)
		{
			cout << horizontal_line << endl;
			cout << mathematician << " walks deeper into the cave. Ahead, deep growling and snarling " << endl;
			cout << "echoes off the walls. Suddenly, a massive wolf leaps out of the dark! " << endl;
			cout << "It is quickly wagging its tail back and forth while baring its teeth  " << endl;
			cout << "aggressively. The wolf barks at " << mathematician << ": \"What is 8 x 8 + 3?\"" << endl;
			cout << horizontal_line << endl;
			cout << "What does " << mathematician << " respond with? \n> ";
			cin >> answer;
			
			//correct
			cout << horizontal_line << endl;
			if (answer == 67)
				cout << "You answered correctly. The wolf calms down and lumbers past you." << endl;
			
			//incorrect
			else
			{
				is_alive = false;
				cout << math_dead << endl;
			}
		}
		
		//question 3
		if (is_alive == true)
		{
			cout << horizontal_line << endl;
			cout << mathematician << " presses further into the cavern. The ground trembles as a giant" << endl;
			cout << "cyclops stomps forward. The beast is so tall its face is hidden in the" << endl;
			cout << "shadows; all that is visible is a single, glowing red eye. The cyclops" << endl;
			cout << "rumbles in a deep, airy voice: \"What is " << rnumber1 << " squared plus " << rnumber3 << " / " << rnumber2 << "?\"" << endl;
			cout << horizontal_line << endl;
			cout << "What does " << mathematician << " respond with? \n> ";
			cin >> answer;
			cin.ignore(1000, '\n');
			
			//correct
			cout << horizontal_line << endl;
			if (answer == rnumber1 * rnumber1 + rnumber3 / rnumber2)
			{
				cout << "You answered correctly. The cyclops freezes, standing perfectly still." << endl;
				cout << mathematician << " carefully walks around the giant and continues on." << endl;
			}
			//incorrect
			else
			{
				is_alive = false;
				cout << math_dead << endl;
			}
		}
		
		//question 4
		if (is_alive == true)
		{
			cout << horizontal_line << endl;
			cout << mathematician << " navigates the winding tunnels until reaching a dead-end wall. " << endl;
			cout << "It seems there is nowhere left to go. But where is the treasure? " << mathematician << endl;
			cout << "is about to turn back in disappointment when the ground begins to     " << endl;
			cout << "violently shake. The stone floor cracks wide open! Before " << mathematician << endl;
			cout << "can react, the ground collapses, sending them tumbling into the dark  " << endl;
			cout << "hole below." << endl;
			cout << "\n" << mathematician << " recovers from the fall, dusting off, and looks around this  " << endl;
			cout << "hidden chamber. In the center sits a grand chest overflowing with     " << endl;
			cout << "gold! Suddenly, a glowing Koi Fish hovers up from behind the treasure." << endl;
			
			//lose the game
			if (fisch == false)
			{
				cout << "The fish says in a heavenly tone: \"Your final challenge... prove the  " <<endl;
				cout << "Riemann Hypothesis.\"" << endl;
				cout << horizontal_line << endl;
				cout << "What does " << mathematician << " respond with? \n> ";
				getline(cin, q4_answer);
				is_alive = false;
				cout << horizontal_line << endl;
				cout << "\"" << q4_answer << "\" wasn't even close to the right answer." << endl;
				cout << "You should try solving your problems with \"fish\" in the next life. Goodbye, mortal." << endl;
				cout << "Find another way, " << mathematician << "! GAME OVER..." << endl;
			}
			
			//win game using secret
			else if (fisch == true)
			{
				cout << "The fish says in a heavenly tone: \"Your final challenge... find the   " << endl;
				cout << "derivative of 4x squared + 18x - 547.\"" << endl;
				cout << horizontal_line << endl;
				cout << "What does " << mathematician << " respond with? \n> ";
				getline(cin, q4_answer);
				
				while (q4_answer != "8x + 18" && q4_answer != "8x+18")
				{
					cout << "\nThe fish grows angry and yells: \"INCORRECT, TRY AGAIN!\"" << endl;	
					cout << "What does " << mathematician << " respond with? \n> ";
					getline(cin, q4_answer);
				} 
				
				cout << "\n\"Correct.\" The fish bows. \"Take the treasure and leave this cave.\"\n";
				cout << horizontal_line << endl;
				cout << "Congratulations, you survived the dungeon and claimed the treasure " << mathematician << "!" << endl;
			}
		}
		
		//ask if the user wants to retry the game
		cout << "\nWould you like to play again? (Y/N): ";
		cin >> restart_choice;
		cin.ignore(1000, '\n');
		
	} while (restart_choice == "Y" || restart_choice == "y");
	
	cout << "\nThanks for playing!" << endl;
	
	return 0;
	
}