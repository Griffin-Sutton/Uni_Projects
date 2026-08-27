/*
	Title:  	lab_3.cpp
	Author:		Griffin Sutton and Emily Dunlap
	Date:		02/011/26	
	Purpose:	Generates a work order for a customer at a repair shop.
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include <cmath>

int main()
{
	//Variable initilization
	const double TAX_RATE = 0.0975;
	const double LABOR_RATE = 47.50;
	double ticket_number, parts_cost, labor_hours, labor_cost, subtotal, tax, total;
	int age, severity;
	string fullName, horizontalLine(45, '-');
	char deviceType, warranty;
	
	//random number seed plus opening statement
	srand(time(0));
	ticket_number = rand() % 9500 + 500;
	cout << horizontalLine << endl;
	cout << "Welcome to Peely & Fishstick's Repair Shop!" << endl;
	cout << horizontalLine << endl;
	
	//input customer information
	cout << "Enter customer's age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter customer full name: ";
	getline(cin, fullName);
	cout << "Engter device type from the following menu options: \n";
	cout << "	C = Computer Device (laptop, server router, or network switch)\n";
	cout << "	A = Audio Device (USB audio interface, microphone or mixer)\n";
	cout << "	E = Electronic Device (oscilloscope, multimeter, microcontroller board)\n";
	cout << "Enter C, A, or E: ";
	cin >> deviceType;
	cout << "Does the deive have a warranty? (Y/N): ";
	cin >> warranty;
	
	//generate issue severity
	severity = rand() % 10 + 1;
	if (severity > 7)
		cout << "This is a dumpster fire situation! The diagnostic severity is: " << severity <<endl;
	else
		cout << "The diagnostic severity is: " << severity << endl;
	
	//output ticket
	cout << horizontalLine << endl;
	cout << "Repair Desk Quote\n";
	cout << "Ticket #: " << ticket_number << endl;
	cout << "Customer: " << fullName << endl;
	cout << "Device Type: " << deviceType << endl;
	cout << "Warranty: " << warranty << endl;
	cout << "Diagnostic Severity: " << severity << endl;
	cout << horizontalLine << endl;
	
	//parts cost and labor hours per device type
	if (deviceType == 'C')
	{
		parts_cost = 250.00;
		labor_hours = pow(severity, 1.1);
	}
	
	else if (deviceType == 'A')
	{
		parts_cost = 180.00;
		labor_hours = pow(severity, 1.5);
	}
	
	else if (deviceType == 'E')
	{
		parts_cost = 175.00;
		labor_hours = pow(severity, 1.7);
	}
	
	//first set of cost outputs
	cout << "Estimated Labor Hours: " << labor_hours << endl;
	cout << "Labor Rate: $" << LABOR_RATE << endl;
	cout << "Parts Cost: $" << parts_cost << endl;
	cout << horizontalLine << endl;
	
	//if user has warranty
	if (warranty == 'Y')
	{
		parts_cost = 0;
		labor_hours = labor_hours * 0.5;
		cout << "Adjusted parts cost after warranty: $0.00" <<endl;
		cout << "adjusted labor hours after warranty: " << labor_hours << endl;
		cout << horizontalLine << endl;
	}
	
	//final calculations and cost outputs.
	labor_cost = labor_hours * LABOR_RATE;
	subtotal = labor_cost + parts_cost;
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;
	
	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax (9.75%): $" << tax << endl;
	cout << "TOTAL DUE: $" << total;
	
	
	return 0;
	
}

