/************************************************************************
 *	Title:             mod2.cpp
 *  Module:            2
 *	Author:            Griffin Sutton
 *	Date of Creation:  January 23rd, 2026
 *	Purpose:           Output the users favorite color and number to the screen
 ************************************************************************/
 
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
	string color;
	int number;
	 
	 cout << "What is your favorite color: ";
	 cin >> color;
	 cout << "What is your favorite number: ";
	 cin >> number;
	 cout << "Your favorite color is " << color << " and your favorite number is " << number;
	 return 0;
	}