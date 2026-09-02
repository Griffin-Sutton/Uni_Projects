#include "Doctor.h"
#include "Treatment.h"
#include "Patient.h"

#include <string>
#include <iostream>
using namespace std;

Doctor::Doctor() {
    name = "Unassigned";
    specialty = "N/A";
}

Doctor::Doctor(string n, string s) {
    name = n;
    specialty = s;
}

void Doctor::setName(string n) {
    name = n;
}

void Doctor::setSpecialty(string s) {
    specialty = s;
}

string Doctor::getName() const{
    return name;
}

string Doctor::getSpecialty() const{
    return specialty;
}

void Doctor::printDoctor() {
    cout << "NAME:\t" << name << "\n";
    cout << "SPECIALTY:\t" << specialty << "\n";
}