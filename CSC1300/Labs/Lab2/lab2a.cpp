/*
	Title:  	lab_2a.cpp
	Author:		Griffin Sutton
	Date:		02/04/26	
	Purpose:	This program is written for waiters & waitresses at
				TGI Fridays so that they can calculate total cost
				of hot wings for their customers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//define your variables here
	double tax = 0.085;
	double wing_price = 0.99;
	double wing_amount;
	double price;
	double total_price;
	
	/* 	the line below will allow floating point amounts to display
		two numbers after the decimal point.  (it will make amounts pretty) 
	*/
	cout <<	setprecision(2) << fixed << showpoint;
	
	//	Fill in the	input statement to bring in	the	quantity of hot wings.
	cout << "\n\nPlease input the number of hot wings purchased:  ";
	cin >> wing_amount;
	
	//	Fill in the assignment statement to determine the total bill.
	price = wing_amount * wing_price;
	total_price = price - (price * tax);
	
	//	Fill in	the	output statement to print total	bill as shown in sample output
	cout << "\nYour total price is: $" << total_price;
	
	return 0;
}