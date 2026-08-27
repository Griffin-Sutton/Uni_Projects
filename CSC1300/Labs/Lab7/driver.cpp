/*
	Title:      driver.cpp
	Author:     Griffin Sutton
	Date:       03/11/26	
	Purpose:    driver file for dinosaur file parsing
*/

#include "lab7.h"

int main(){
	
	//variable initialization
	ifstream dino_file;
	string filename;
	string dName, dHeight, dMass, dEat, dDesc;
	//accumulators
	int total_dinos = 0, saurus_count = 0, over_10_count = 0;
	
	//receive file
	cout << "Dinosaur Directory File Name (dinoDirectory.txt): ";
	cin >> filename;
	
	//open the file
	dino_file.open(filename);
	while (!dino_file){
		cout << "The file could not open. Please enter a valid filename: ";
		cin >> filename;
		dino_file.clear();
		dino_file.open(filename);
	}
	
	//process information in file
	while (getline(dino_file, dName, '#')){
		getline(dino_file, dHeight, '#');
		getline(dino_file, dMass, '#');
		getline(dino_file, dEat, '#');
		getline(dino_file, dDesc, '#');
		
		total_dinos++;
		
		//check for saurus
		if (dName.find("saurus") != string::npos) {
			saurus_count++;
			printSaurus(dName, dHeight, dMass, dEat, dDesc);
		}
		
		//check for over 10,000 lbs
		if (overTenGrand(dMass)){
			over_10_count++;
			printOver10(dName, dHeight, dMass, dEat, dDesc);
		}
	}
	
	dino_file.close();
	
	cout << "--------------------------------------------------" << endl;
	cout << "TOTAL DINOS: " << total_dinos << endl;
	cout << "DINOS OVER 10,000 LBS: " << over_10_count << endl;
	cout << "DINO NAMES END IN 'SAURUS: " << saurus_count << endl;
	cout << "--------------------------------------------------" << endl;
	
	return 0;
}