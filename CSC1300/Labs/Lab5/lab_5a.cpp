/*
	Title:      lab_5a.cpp
	Author:     Griffin Sutton
	Date:       02/25/26	
	Purpose:    come up with a nickname for the user using random number generation and user-selection
*/

#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	
	//initialization
	srand(time(0));
	int first_letter_int, second_randletter = rand() % 5 + 1;
	char first_letter, second_letter, third_letter = rand() % 26 + 97, fourth_letter = 'y';
	string nickname = "";
	
	//starting menu
	cout << "\nHello! Let's figure out a nickname for you!" << endl;
	cout << "\nChoose a number between (and including) 65 to 90: ";
	cin >> first_letter_int;
	while (first_letter_int < 65 || first_letter_int > 90){
		cout << "Oops! Invalid entry. Choose between 65-90: ";
		cin >> first_letter_int;
	}
	
	//calculations
	first_letter = (char)first_letter_int;
	
	switch (second_randletter) {
		case 1:
			second_letter = 'a';
			break;
		case 2:
			second_letter = 'e';
			break;
		case 3:
			second_letter = 'i';
			break;
		case 4:
			second_letter = 'o';
			break;
		case 5:
			second_letter = 'u';
			break;
	}
	
	//output
	nickname += first_letter;
	nickname += second_letter;
	nickname += third_letter;
	nickname += fourth_letter;
	cout << "Your nickname is " << nickname << "!" << endl;
	
	return 0;
	
}