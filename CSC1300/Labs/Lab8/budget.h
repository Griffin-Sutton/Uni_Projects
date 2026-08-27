/*
	Title:      budget.h
	Author:     Griffin Sutton
	Date:       03/25/26	
	Purpose:    Header file for student budget
*/

#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//constant variables
const int num_students = 3, num_categories = 4, max_cstring = 50;


//function prototypes
void get_user_input(char categories[][max_cstring], string names[], double incomes[], double expenditures[][num_students]);
void calculate_balance(double incomes[], double expenditures[][num_students], double balances[]);
int get_highest(double balances[]);
int get_lowest(double balances[]);

#endif