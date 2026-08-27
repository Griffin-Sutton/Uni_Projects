/*
	Title:  	prog5.h
	Author:		Griffin Sutton
	Date:		04/27/26	
	Purpose:	Header file containing the structure definition and function prototypes 
                for the Superhero Condo program.
*/

#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Structure to hold all the data for a single superhero tenant
struct Heroes
{
	string name;
	string description;
	bool dangerous;
	float rentPrice;
	float damageCost;
	float numYears;
};

// Function Prototypes
int enterHeroes(int max, int numHeroes, Heroes* heroList);
int deleteHero(int numHeroes, Heroes* heroList);
bool moveArrayElements(string heroName, int numHeroes, Heroes* heroList);
void printHeroes(int numHeroes, Heroes* heroList);
void printRentDetails(int numHeroes, Heroes* heroList);
void saveToFile(int numHeroes, Heroes* heroList);

#endif