/*
	Title:      lab_6.cpp
	Author:     Griffin Sutton
	Date:       03/04/26	
	Purpose:    a menu-based program that will allow the user to calculate the area for a few 
				different shapes: square, rectangle, parallelogram, and circle.
*/

#include <iostream>
using namespace std;

//global variables
const float PI = 3.14;

//function prototypes
int display_menu_choice();
float area_square();
float area_rectangle();
float area_parallelogram();
float area_circle();

//main function
int main(){
	
	int choice = 0;
	float final_area = 0;
	
	do {
		
		//call user choice function
		choice = display_menu_choice();
		
		switch (choice){
			//square case
			case 1:{
				
				final_area = area_square();
				cout << "\nThe area of your square is " << final_area << endl;
				break;
			}
			//rectangle case
			case 2:{
				final_area = area_rectangle();
				cout << "\nThe area of your rectangle is " << final_area << endl;
				break;
			}
			//parallelogram case
			case 3:{
				final_area = area_parallelogram();
				cout << "\nThe area of your parallelogram is " << final_area << endl;
				break;
			}
			//circle case
			case 4:{
				final_area = area_circle();
				cout << "\nThe area of your circle is " << final_area << endl;
				break;
			}
			//exit case
			case 5:{
				break;
			}
		}
			
		
	} while (choice != 5);
	
	cout << "\nGoodbye!\n";
	
	return 0;
}

int display_menu_choice(){
	
	int choice = 0;
		
		cout << "\nChoose a shape to calculate area or 5 to quit:" << endl;
		cout << "1. Square" << endl;
		cout << "2. Rectangle" << endl;
		cout << "3. Parallelogram" << endl;
		cout << "4. Circle" << endl;
		cout << "5. Exit Program" << endl;
		cout << "Choose 1 - 5: ";
		cin >> choice;
		
		while (!cin || choice < 1 || choice > 5){
			cout << "\nThat isn't a valid input. Please choose 1-5: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice;
		}
	
	return choice;
}

//function to calculate the area of a square
float area_square(){
	
	float area = 0;
	float height = 0;
	
	cout << "\nWhat is the height of the square: ";
	cin >> height;
	
	while (!cin || height < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> height;
	}
	
	area = height * height;
	
	return area;
}

//function to calculate the area of a rectangle
float area_rectangle(){
	
	float area = 0;
	float height = 0;
	float width = 0;
	
	cout << "\nEnter the height of the rectangle: ";
	cin >> height;
	
	while (!cin || height < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> height;
	}
	
	cout << "\nEnter the width of the rectangle: ";
	cin >> width;
	
	while (!cin || width < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> width;
	}
	
	area = height * width;
	
	return area;
}

//function to calculate the area of a parallelogram
float area_parallelogram(){
	
	float area = 0;
	float base = 0;
	float height = 0;
	
	cout << "\nEnter the base of the parallelogram: ";
	cin >> base;
	
	while (!cin || base < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> base;
	}
	
	cout << "\nEnter the height of the parallelogram: ";
	cin >> height;
	
	while (!cin || height < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> height;
	}
	
	area = base * height;
	
	return area;
}

//function to calculate the area of a circle
float area_circle(){
	
	float radius = 0;
	float area = 0;
	
	cout << "\nEnter the radius of the circle: ";
	cin >> radius;
	
	while (!cin || radius < 0){
			cout << "\nThat isn't a valid input. Please choose a positive value: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> radius;
	}
	
	area = (radius * radius) * PI;
	
	return area;
}