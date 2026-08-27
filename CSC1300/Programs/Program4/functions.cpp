/*
	Title:  	functions.cpp
	Author:		Griffin Sutton
	Date:		04/07/26	
	Purpose:	This file contains the implementations of the functions for Jeopardy
*/

#include "jeopardy.h"

/*
Function Name: showBoard
Purpose: This function should print the current state of the board. 
A spot will have 0 if the question has been answered, 1 if the question is still available, and 2 if the question is a daily double.
It will return true if there are still spots on the board available to answer.
*/
bool showBoard(string categories[], int** board, int rows, int columns)
{
	bool available = false;
	string separator(60, '-');
	
	cout << "\n" << setw(15) << " ";
	for (int c = 0; c < columns; ++c)
	{
		cout << right << setw(7) << "|   " << (c+1);
	}
	
	cout << "   |\n";
	cout << separator << "\n";
	
	for (int i = 0; i < rows; ++i)
	{
		cout << left << i+1 << left << ". " << setw(15) << categories[i];
		for (int j = 0; j < columns; ++j)
		{
			cout << "|  ";
			if (board[i][j] == 0)
			{
				cout << "  X  ";
			}
			else
			{
				cout << setw(4) << (j+1)*100 << " ";
				available = true;
			}
		}
		cout << "|\n";
	}
	cout << separator << "\n";
	
	return available;
}

/*
Function Name: printWelcomeMessage
Purpose: This function should print the welcome message for the game.
*/
void printWelcomeMessage()
{
	string line_of_stars(60, '*');
	string blank_space_part(17, ' ');
	string blank_space_full(58, ' ');

	cout << line_of_stars << endl;
	cout << "*" << blank_space_full << "*" << endl;
	cout << "*" << blank_space_part << "Welcome to \"Jeopardy...\"" << blank_space_part << "*" << endl;
	cout << "*" << blank_space_full << "*" << endl;
	cout << line_of_stars << endl << endl;
}

/*
Function Name: toLowerString
Purpose: Converts a given string entirely to lowercase and returns it.
*/
string toLowerString(string str)
{
	string lower_str = "";
	
	for (size_t i = 0; i < str.length(); i++)
	{
		lower_str += tolower(str[i]);
	}
	
	return lower_str;
}

/*
Function Name: loadQuestionsAndAnswers
Purpose: Loads questions and answers from text files, handling lines that may be broken/split.
*/
void loadQuestionsAndAnswers(string categories[], string** questions, string** answers, int num_categories, int num_questions)
{
	for (int i = 0; i < num_categories; i++)
	{
		string filename = toLowerString(categories[i]) + ".txt";
		ifstream file(filename);
		
		if (file.is_open())
		{
			string line;
			string current_entry = ""; // Buffer to hold multi-line questions
			
			while (getline(file, line))
			{
				// If our buffer is empty, start it. Otherwise, append the next line.
				if (current_entry == "")
				{
					current_entry = line;
				}
				else
				{
					// Add a space to prevent merging words together (e.g. "well\nknown" -> "well known")
					if (current_entry.back() != ' ')
					{
						current_entry += " ";
					}
					current_entry += line;
				}
				
				// Check if our accumulated entry now has both '#' delimiters
				size_t first_hash = current_entry.find('#');
				size_t second_hash = string::npos;
				
				if (first_hash != string::npos)
				{
					second_hash = current_entry.find('#', first_hash + 1);
				}
				
				// If we found both hashes, we have a complete question entry!
				if (first_hash != string::npos && second_hash != string::npos)
				{
					string q = current_entry.substr(0, first_hash);
					string a = current_entry.substr(first_hash + 1, second_hash - first_hash - 1);
					int point_value = stoi(current_entry.substr(second_hash + 1));
					
					int index = (point_value / 100) - 1; 
					
					if (index >= 0 && index < num_questions)
					{
						if (questions[i][index] == "")
						{
							questions[i][index] = q;
							answers[i][index] = a;
						}
					}
					
					// Clear the buffer to get ready for the next question
					current_entry = "";
				}
			}
			file.close();
		}
		else
		{
			cout << "Warning: Could not open " << filename << endl;
		}
	}
}

/*
Function Name: initializeBoard
Purpose: Initializes board spots to 1 and randomly sets 3 Daily Doubles to 2.
*/
void initializeBoard(int** board, int num_categories, int num_questions)
{
	for (int i = 0; i < num_categories; i++)
	{
		for (int j = 0; j < num_questions; j++)
		{
			board[i][j] = 1;
		}
	}
	
	int doubles_set = 0;
	while (doubles_set < 3)
	{
		int r = rand() % num_categories;
		int c = rand() % num_questions;
		
		if (board[r][c] == 1)
		{
			board[r][c] = 2;
			doubles_set++;
		}
	}
}

/*
Function Name: getWinner
Purpose: Returns the index of the player with the highest score.
*/
int getWinner(int points[], int num_users)
{
	int max_index = 0;
	
	for (int i = 1; i < num_users; i++)
	{
		if (points[i] > points[max_index])
		{
			max_index = i;
		}
	}
	
	return max_index;
}

/*
Function Name: printQuestionsGetAnswer
Purpose: Prints the question, updates board status to 0 (answered), and gets the user's answer.
*/
string printQuestionsGetAnswer(string** questions, int** board, int category, int question)
{
	string user_answer;
	
	cout << "Question: " << questions[category][question] << endl;
	board[category][question] = 0; 
	
	cout << "Your answer: ";
	getline(cin, user_answer);
	
	return user_answer;
}

/*
Function Name: checkAnswer
Purpose: Compares lowercase user answer to lowercase actual answer. Correct if exact or contained within.
*/
bool checkAnswer(string** answers, string user_answer, int category, int question)
{
	string correct_answer = toLowerString(answers[category][question]);
	string user_lower = toLowerString(user_answer);
	
	if (user_lower == correct_answer)
	{
		return true;
	}
	if (user_lower.find(correct_answer) != string::npos)
	{
		return true;
	}
	
	return false;
}