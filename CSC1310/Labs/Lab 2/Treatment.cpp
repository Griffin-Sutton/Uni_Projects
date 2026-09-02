#include "Doctor.h"
#include "Patient.h"
#include "Treatment.h"

#include <iostream>
#include <string>
Treatment::Treatment() {
    description = "No treatment assigned";
    cost = 0.0;
}

Treatment::Treatment(string d, double c) {
    description = d;
    cost = c;
}

void Treatment::setDescription(string d) {
    description = d;
}

void Treatment::setCost(double c) {
    cost = c;
}

string Treatment::getDescription() const{
    return description;
}

double Treatment::getCost() const{
    return cost;
}

void Treatment::printTreatment() {
    cout << "DESCRIPTION:\t" << description << "\n";
    cout << "COST:\t$" << cost << "\n";
}