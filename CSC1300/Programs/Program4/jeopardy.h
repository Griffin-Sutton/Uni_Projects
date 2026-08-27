/*
	Title:  	jeopardy.h
	Author:		Griffin Sutton
	Date:		04/07/26	
	Purpose:	Header file containing all includes, namespaces, and function prototypes for the Jeopardy program.
*/

#ifndef JEOPARDY_H
#define JEOPARDY_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

//function prototypes
bool showBoard(string categories[], int** board, int rows, int columns);
void printWelcomeMessage();
void loadQuestionsAndAnswers(string categories[], string** questions, string** answers, int num_categories, int num_questions);
void initializeBoard(int** board, int num_categories, int num_questions);
int getWinner(int points[], int num_users);
string printQuestionsGetAnswer(string** questions, int** board, int category, int question);
string toLowerString(string str);
bool checkAnswer(string** answers, string user_answer, int category, int question);

#endif