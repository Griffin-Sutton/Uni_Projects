/*
	Title:  	mod10b.cpp
	Author:		Griffin Sutton
	Date:		04/21/26	
	Purpose:	A program that dynamically allocates an array of structs 
				to hold information about different phones.
*/

#include <iostream>
#include <string>

using namespace std;

// struct declaration
struct Phone {
	string type;
	string color;
	double capacity;
};

// function prototypes
void addPhone(Phone* phoneArray, int size);
void printArray(Phone* phoneArray, int size);

// main function
int main() {
	
	// initializing variables
	int num_phones = 0;
	
	// get the number of phones from user
	cout << "How many phones? ";
	cin >> num_phones;
	
	// dynamic memory allocation for the array of structs
	Phone* my_phones = new Phone[num_phones];
	
	// call the function to populate the array
	addPhone(my_phones, num_phones);
	
	// call the function to print the array
	printArray(my_phones, num_phones);
	
	// free the dynamically allocated memory!
	delete[] my_phones;
	
	return 0;
}

/*
Function Name: addPhone
Purpose: Reads the data of each user’s phone and places it into the dynamically
allocated array.
*/
void addPhone(Phone* phoneArray, int size) {
	for(int i = 0; i < size; i++) {
		cout << "\nPHONE " << (i + 1) << "\n";
		
		// clear the input buffer before reading strings
		cin.ignore(10000, '\n'); 
		
		cout << "PHONE TYPE: ";
		getline(cin, phoneArray[i].type);
		
		cout << "PHONE COLOR: ";
		getline(cin, phoneArray[i].color);
		
		cout << "PHONE CAPACITY (in GB): ";
		cin >> phoneArray[i].capacity;
	}
}

/*
Function Name: printArray
Purpose: Prints all the phone data currently stored in the array.
*/
void printArray(Phone* phoneArray, int size) {
	cout << "\n";
	for(int i = 0; i < size; i++) {
		cout << "Phone: " << phoneArray[i].type << "\n";
		cout << "Color: " << phoneArray[i].color << "\n";
		cout << "Capacity: " << phoneArray[i].capacity << " GB\n";
		
		// adds a space between the phone outputs
		cout << "\n"; 
	}
}