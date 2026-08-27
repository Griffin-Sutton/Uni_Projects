/*
	Title:  	prog4.cpp
	Author:		Griffin Sutton
	Date:		04/07/26	
	Purpose:	Contains the main game loop and dynamic memory initialization for Jeopardy
*/

#include "jeopardy.h"

int main()
{
	//initializing variables
	const int NUM_USERS = 3;
	const int NUM_CATEGORIES = 5;
	const int NUM_QUESTIONS = 5;
	bool game_running = true;

	//seed randomizer
	srand(time(0));

	//dynamic memory allocation
	string* categories = new string[NUM_CATEGORIES];
	categories[0] = "Science";
	categories[1] = "History";
	categories[2] = "Math";
	categories[3] = "Comics"; 
	categories[4] = "Music";

	string** questions = new string*[NUM_CATEGORIES];
	string** answers = new string*[NUM_CATEGORIES];
	int** board = new int*[NUM_CATEGORIES];

	for (int i = 0; i < NUM_CATEGORIES; i++)
	{
		questions[i] = new string[NUM_QUESTIONS];
		answers[i] = new string[NUM_QUESTIONS];
		board[i] = new int[NUM_QUESTIONS];
		
		for (int j = 0; j < NUM_QUESTIONS; j++)
		{
			questions[i][j] = "";
			answers[i][j] = "";
		}
	}

	string* users = new string[NUM_USERS];
	int* points = new int[NUM_USERS];
	
	for (int i = 0; i < NUM_USERS; i++)
	{
		points[i] = 0;
	}

	//initialize game states
	loadQuestionsAndAnswers(categories, questions, answers, NUM_CATEGORIES, NUM_QUESTIONS);
	initializeBoard(board, NUM_CATEGORIES, NUM_QUESTIONS);
	printWelcomeMessage();

	//get player names
	for (int i = 0; i < NUM_USERS; i++)
	{
		cout << "Player " << (i + 1) << ", what is your name? ";
		getline(cin, users[i]);
	}

	//main game loop
	while (game_running)
	{
		bool round_played = false;

		for (int p = 0; p < NUM_USERS; p++)
		{
			if (!showBoard(categories, board, NUM_CATEGORIES, NUM_QUESTIONS))
			{
				game_running = false;
				break;
			}
			round_played = true;

			cout << "\n" << users[p] << ", it's your turn!\n";
			
			int chosen_category = 0, chosen_question = 0;
			bool valid_selection = false;
			
			//input validation
			do {
				cout << "Select a category (1-5): ";
				if (!(cin >> chosen_category) || chosen_category < 1 || chosen_category > 5)
				{
					cout << "Invalid input. ";
					cin.clear();
					string garbage;
					getline(cin, garbage);
					continue;
				}

				cout << "Select a question (1-5): ";
				if (!(cin >> chosen_question) || chosen_question < 1 || chosen_question > 5)
				{
					cout << "Invalid input. ";
					cin.clear();
					string garbage;
					getline(cin, garbage);
					continue;
				}

				if (board[chosen_category - 1][chosen_question - 1] == 0)
				{
					cout << "We have to do that all over again, you fool\n";
					continue;
				}

				valid_selection = true;
			} while (!valid_selection);

			cin.ignore(10000, '\n'); 

			//gameplay logic
			int points_at_stake = chosen_question * 100;
			bool is_daily_double = (board[chosen_category - 1][chosen_question - 1] == 2);

			if (is_daily_double)
			{
				cout << "*** DAILY DOUBLE! ***\n";
			}

			string user_ans = printQuestionsGetAnswer(questions, board, chosen_category - 1, chosen_question - 1);
			bool is_correct = checkAnswer(answers, user_ans, chosen_category - 1, chosen_question - 1);

			if (is_correct)
			{
				cout << "Correct!\n";
				if (is_daily_double)
				{
					cout << "You found a DAILY DOUBLE! Points doubled!\n";
					points[p] += (points_at_stake * 2);
				}
				else
				{
					points[p] += points_at_stake;
				}
			}
			else
			{
				cout << "Incorrect. The correct answer was: " << answers[chosen_category - 1][chosen_question - 1] << "\n";
				points[p] -= points_at_stake; 
			}
		}

		//print standings
		if (round_played)
		{
			cout << "\n**********Current Points**********\n";
			for (int i = 0; i < NUM_USERS; i++)
			{
				cout << users[i] << " : " << points[i] << " points\n";
			}
			cout << "==== NEW ROUND ====\n";
		}
	}

	//end of game
	int winner_idx = getWinner(points, NUM_USERS);
	cout << "\nCongratulations " << users[winner_idx] << "! You are the winner with " << points[winner_idx] << " points!\n";

	//cleanup dynamic memory
	for (int i = 0; i < NUM_CATEGORIES; i++)
	{
		delete[] questions[i];
		delete[] answers[i];
		delete[] board[i];
	}
	delete[] questions;
	delete[] answers;
	delete[] board;
	delete[] categories;
	delete[] users;
	delete[] points;

	return 0;
}