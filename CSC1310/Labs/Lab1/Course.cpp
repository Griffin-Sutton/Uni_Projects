/*
	Course Structure Implementation
	LAB 1 CSC 1310
	Authors: Griffin Sutton
	Date: 8/26/2026
*/

#include "Course.h"

//functions
Course* createCourse(string name, string location, int numSections, int numHours){
	Course* newCourse = new Course;
	(*newCourse).name = name;
	(*newCourse).location = location;
	(*newCourse).numSections = numSections;
	(*newCourse).numHours = numHours;
	
	// Dynamically allocating the sections array based on the number of sections
	(*newCourse).sections = new string[numSections];

	return newCourse;
}

void destroyCourse(Course* myCourse){
	// Deleting the dynamically allocated sections array to prevent memory leaks
	delete [] myCourse->sections;
	// Deleting the dynamically allocated course structure
	delete myCourse;
}

void printCourse(Course* myCourse){
	// Printing course details in a user-friendly format
	cout << "COURSE NAME:\t\t" << myCourse->name << endl;
	cout << "COURSE LOCATION:\t" << myCourse->location << endl;
	cout << "COURSE HOURS:\t\t" << myCourse->numHours << endl;
	cout << "COURSE SECTIONS:\t";
	
	// Looping through the sections array to display each section
	for(int i = 0; i < myCourse->numSections; i++)
	{
		if(i == 0)
		{
			cout << myCourse->sections[i] << endl;
		}
		else
		{
			cout << "\t\t\t" << myCourse->sections[i] << endl;
		}
	}
}