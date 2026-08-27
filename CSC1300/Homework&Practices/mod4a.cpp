/*
	Title:      mod4a.cpp
	Author:     Griffin Sutton
	Date:       02/19/26	
	Purpose:    A program for a restaurant host to assist him or her with seating patrons
*/

#include <iostream>
using namespace std;

int main()
{
	int party_count;
	
	cout << "\nhow many people are in your party: ";
	cin >> party_count;
	
	if (party_count == 1 || party_count == 2)
		cout << "\nYou may be seated at a small table." << endl;
	
	else
		cout << "\nYou may be seated at a large table." << endl;
	
	return 0;
}