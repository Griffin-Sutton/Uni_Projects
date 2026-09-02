/*******************************************************************
	Title: Doctor.h
	Author:	Griffin Sutton, Bruce Myers
	Date: September 2, 2026
	Purpose: Defining data and public functions for the Doctor class
*******************************************************************/

#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
using namespace std;


class Doctor {
    private:
        string name;
        string specialty;
    public:
        Doctor();
        Doctor(string, string);
        void setName(string);
        void setSpecialty(string);
        string getName() const;
        string getSpecialty() const;
        void printDoctor();
};

#endif