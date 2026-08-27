/*
	Title:      lab_5c.cpp
	Author:     Griffin Sutton
	Date:       02/25/26	
	Purpose:    Find the average between two positive integers
*/

#include <iostream>
using namespace std;

int main()
{
	
	int first_number, second_number, average;
	cout << "You can enter two numbers and find the average of them." << endl;
	cout << "Please enter the beginning positive integer: ";
	cin >> first_number;
	
	while (first_number < 0)
	{
		cout << "The beginning number must be positive: ";
		cin >> first_number;
	}
	
	cout << "Please enter the ending positive integer: ";
	cin >> second_number;
	
	while (second_number < first_number || second_number < 0)
	{
		cout << "The second number has to be equal to or bigger than the first number: ";
		cin >> second_number;
	}
	
	average = (first_number + second_number) / 2;
	cout << "The mean average of the consecutive positive integers from " << first_number << " to " << second_number << " is " << average;
	
	return 0;
}