/*
	Title:      lab7.h
	Author:     Griffin Sutton
	Date:       03/11/26	
	Purpose:    Header file for dinosaur file parsing
*/

#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void printOver10(string dName, string dHeight, string dMass, string dEat, string dDesc);
void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc);
bool overTenGrand(string dMass);

#endif