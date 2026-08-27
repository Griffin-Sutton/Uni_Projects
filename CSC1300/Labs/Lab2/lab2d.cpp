/*
	Title:  	lab_2d.cpp
	Author:		Griffin Sutton
	Date:		02/04/26	
	Purpose:	This program is written for a dog to calculate the time they
				will serve in prison for stealing bones.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	//initialization of variables
	double bones;
	double sentence_per_bone = 83;
	double days_served_double;
	int days_served_int;
	double years;
	
	//input
	cout <<	setprecision(5) << fixed << showpoint;
	cout << "\nHow many bones have you stolen: ";
	cin >> bones;
	
	//math
	days_served_int = bones * sentence_per_bone;
	days_served_double = bones * sentence_per_bone;
	years = days_served_double / 365;
	
	//output
	cout << "\nYou must go to prison for " << days_served_int << " days which is " << years << " years.";
	
	return 0;
	
}