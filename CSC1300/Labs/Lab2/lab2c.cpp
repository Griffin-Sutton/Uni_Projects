/*
	Title:  	lab_2c.cpp
	Author:		Griffin Sutton
	Date:		02/04/26	
	Purpose:	This program is written for the user to calculate their test average in a class.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	//initialization of variables
	std::string name;
	double test1;
	double test2;
	double test3;
	double average;
	
	cout <<	setprecision(4) << fixed << showpoint;
	
	//user inputs
	cout << "\nwhat is the student's first and last name: ";
	std::getline(std::cin, name);
	cout << "\nenter " << name << "'s first test grade: ";
	cin >> test1;
	cout << "\nenter " << name << "'s second test grade: ";
	cin >> test2;
	cout << "\nenter " << name << "'s third test grade: ";
	cin >> test3;
	
	//math and output
	average = (test1 + test2 + test3) / 3;
	cout << endl << name << " has a test average of " << average;
	
	return 0;
}