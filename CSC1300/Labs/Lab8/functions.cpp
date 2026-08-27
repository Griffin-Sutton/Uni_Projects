/*
	Title:      functions.cpp
	Author:     Griffin Sutton
	Date:       03/25/26
	Purpose:    function file for student budget
*/

#include "budget.h"

//function used to receive the users input
void get_user_input(char categories[][max_cstring], string names[], double incomes[], double expenditures[][num_students]){
	cout << "\nWelcome to the student budget calculator!" << endl;
	cout << "\nPlease enter the expenditure category names." << endl;
	
	//gather categories
	for (int x = 0; x < num_categories; x++){
		cout << "name of category " << (x + 1) << " - ";
		cin.getline(categories[x], max_cstring);
	}
	
	//gather student data
	cout << "\nPlease enter each student's data." << endl;
	
	for (int x = 0; x < num_students; x++){
		cout << "\nSTUDENT " << (x + 1) << endl;
		
		cout << "name: ";
		getline(cin, names[x]);
		
		cout << "\nincome: ";
		cin >> incomes[x];
		
		cout << "\nEXPENDITURES" << endl;
		for (int i = 0; i < num_categories; i++){
			cout << "\n" << categories[i] << ": ";
			cin >> expenditures[i][x];
		}
		
		cin.ignore();
	}
}

//function to calculate the final balances for the students
void calculate_balance(double incomes[], double expenditures[][num_students], double balances[]){
	for (int x = 0; x < num_students; x++){
		double total_expended = 0;
		for (int i = 0; i < num_categories; i++){
			total_expended += expenditures[i][x];
		}
		balances[x] = (incomes[x] - total_expended);
	}
}

//function to calculate the highest remaining balance
int get_highest(double balances[]){
	int highest_bal = 0;
	for (int x = 1; x < num_students; x++){
		if (balances[x] > balances[highest_bal]){
			highest_bal = x;
		}
	}
	return highest_bal;
}

//function to calculate the lowest remaining balance
int get_lowest(double balances[]){
	int lowest_bal = 0;
	for (int x = 1; x < num_students; x++){
		if (balances[x] < balances[lowest_bal]){
			lowest_bal = x;
		}
	}
	return lowest_bal;
}