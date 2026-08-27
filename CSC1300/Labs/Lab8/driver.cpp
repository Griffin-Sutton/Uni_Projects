/*
	Title:      driver.cpp
	Author:     Griffin Sutton
	Date:       03/25/26	
	Purpose:    driver file for student budgets
*/

#include "budget.h"

int main(){
	
	//array declarations
	char categories[num_categories][max_cstring];
	string names[num_students];
	double incomes[num_students], balances[num_students], expenditures[num_categories][num_students];
	
	//get user input
	get_user_input(categories, names, incomes, expenditures);
	
	//calculate balances
	calculate_balance(incomes, expenditures, balances);
	
	//calculate highest and lowest balance
	int highest_index = get_highest(balances);
	int lowest_index = get_lowest(balances);
	
	//output
	cout << fixed << setprecision(2);
	
	//highest balance output
	cout << "\nThe student that has the highest remaining balance of " << balances[highest_index] << " is " << names[highest_index]
	<< ",who started out with an\nincome of $" << incomes[highest_index] << " and expenditures of ";
	for (int x = 0; x < num_categories; x++) {
		cout << categories[x] << " $" << expenditures[x][highest_index] << " ";
	}
	
	//lowest balance output
	cout << "\nThe student that has the lowest remaining balance of " << balances[lowest_index] << " is " << names[lowest_index]
	<< ", who started out with an\nincome of $" << incomes[lowest_index] << " and expenditures of ";
	for (int x = 0; x < num_categories; x++) {
		cout << categories[x] << " $" << expenditures[x][lowest_index] << " ";
	}
	
	return 0;
}