#include "Patient.h"
#include "Treatment.h"
#include "Doctor.h"

using namespace std;
#include <string>
#include <iostream>

Patient::Patient(){
    name = "";
    age = 0;
    chiefComplaint = "";
    severityLevel = 0;
}

Patient::Patient(string n, int a, string cc, int sl){
    name = n;
    age = a;
    chiefComplaint = cc;
    severityLevel = sl;
}

void Patient::setName(string n){
    name = n;
}

void Patient::setAge(int a){
    age = a;
}

void Patient::setChiefComplaint(string cc){
    chiefComplaint = cc;
}
    
void Patient::setSeverityLevel(int sl){
    severityLevel = sl;
}

string  Patient::getName() const{
    return name;
}

int  Patient::getAge() const{
    return age;
}

string Patient::getChiefComplaint() const{
    return chiefComplaint;
}

int Patient::getSeverityLevel() const{
    return severityLevel;
}

void Patient::assignDoctor(Doctor d) {
    doctor = d;
}

void Patient::assignTreatment(Treatment t) {
    treatment = t;
}

Doctor Patient::getDoctor() const{
    return doctor;
}

Treatment Patient::getTreatment() const{
    return treatment;
}

void Patient::printPatient() {
    cout << "NAME:\t" << name << "\n";
    cout << "AGE:\t" << age << "\n";
    cout << "CHIEF COMPLAINT:\t" << chiefComplaint << "\n";
    cout << "SEVERITY LEVEL:\t" << severityLevel << "\n";
    
    Doctor d = Patient::getDoctor();
    Treatment t = Patient::getTreatment();

    d.printDoctor();
    t.printTreatment();
}