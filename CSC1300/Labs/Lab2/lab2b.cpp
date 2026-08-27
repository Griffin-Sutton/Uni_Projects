/*
	Title:  	lab_2b.cpp
	Author:		Griffin Sutton
	Date:		02/04/26	
	Purpose:	This program is written for the user to calculate their total for two items purchased.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//initialization of variables
	double tax = 0.0975;
	double total_price;
	double total_price_tax;
	std::string item1;
	std::string item2;
	double amount1;
	double amount2;
	double price1;
	double price2;
	
	cout <<	setprecision(2) << fixed << showpoint;
	
	//inputs for both items
	cout << "\nPlease input the name of the first item: ";
	cin >> item1;
	cout << "\nPlease input the amount of " << item1 << " bought: ";
	cin >> amount1;
	cout << "\nPlease input the price of " << item1 << ": ";
	cin >> price1;
	
	cout << "\nPlease input the name of the second item: ";
	cin >> item2;
	cout << "\nPlease input the amount of " << item2 << " bought: ";
	cin >> amount2;
	cout << "\nPlease input the price of " << item2 << ": ";
	cin >> price2;
	
	//calculation and final output
	total_price = (amount1 * price1) + (amount2 * price2);
	total_price_tax = total_price - (total_price * tax);
	
	cout << "\nThe total bill is: " << total_price_tax << endl;
	
	return 0;
}