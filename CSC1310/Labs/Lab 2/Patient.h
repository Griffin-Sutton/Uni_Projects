#ifndef PATIENT_H
#define PATIENT_H

using namespace std;
#include <string>
#include "Doctor.h"
#include "Treatment.h"

class Patient {
  private:
    string name;
    int age;
    string chiefComplaint;
    int severityLevel;
    Doctor doctor;
    Treatment treatment;
   
  public:
    Patient();

    Patient(string, int, string, int);

    void setName(string);

    void setAge(int);

    void setChiefComplaint(string);

    void setSeverityLevel(int);

    string getName() const;

    int getAge() const;

    string getChiefComplaint() const;

    int getSeverityLevel() const;

    void assignDoctor(Doctor);

    void assignTreatment(Treatment);

    Doctor getDoctor() const;

    Treatment getTreatment() const;

    void printPatient();

};

#endif