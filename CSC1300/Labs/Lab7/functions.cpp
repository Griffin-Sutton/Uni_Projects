/*
	Title:      functions.cpp
	Author:     Griffin Sutton
	Date:       03/11/26	
	Purpose:    function file for dinosaur file parsing
*/

#include "lab7.h"

//appends dinosaur details to saurus.txt
void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc){
	ofstream out_file;
	out_file.open("saurus.txt", ios::app);
	if (out_file.is_open()){
		out_file << "Name: " << dName << endl;
		out_file << "Height: " << dHeight << endl;
		out_file << "Weight: " << dMass << endl;
		out_file << "Eats: " << dEat << endl;
		out_file << "Description: " << dDesc << endl << endl;
		out_file.close();
	}
}

//appends dinosaur details to over10Grand.txt
void printOver10(string dName, string dHeight, string dMass, string dEat, string dDesc){
	ofstream out_file;
	out_file.open("over10Grand.txt", ios::app);
	if (out_file.is_open()){
		out_file << "Name: " << dName << endl;
		out_file << "Height: " << dHeight << endl;
		out_file << "Weight: " << dMass << endl;
		out_file << "Eats: " << dEat << endl;
		out_file << "Description: " << dDesc << endl << endl;
		out_file.close();
	}
}

//determines if a dinosaur weighs over 10,000 lbs by parsing the mass string
bool overTenGrand(string dMass){
	string weight_digits = "";
	int max_weight = 0;
	
	//extract the first number found in the string
	for (size_t x = 0; x < dMass.length(); x++){
		if (isdigit(dMass[x])){
			weight_digits += dMass[x];
		}
		else if (dMass[x] != ',') {
			if (weight_digits != "") {
				int weight = stoi(weight_digits);
				if (weight >= max_weight){
					max_weight = weight;
				}
				weight_digits = "";
			}
		}
	}
	
	if (weight_digits != "") {
		int weight = stoi(weight_digits);
		if (weight > max_weight) {
			max_weight = weight;
		}
	}
	
	return (max_weight > 10000);
}