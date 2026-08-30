#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//struct
struct Course{
    string name;
    string location;
    string *sections;
    int numSections;
    int numHours;
};

//function prototypes
Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif
//comment