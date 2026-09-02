/*******************************************************************
	Title: Driver.cpp (given file for Lab 2)
	Author:	April Crockett
	Date: August 26, 2026
	Purpose: Lab 2 Program for CSC 1310 to practice
			 working with Classes & Objects
			 
	DO NOT ALTER THIS FILE!
	
*******************************************************************/

#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Treatment.h"

using namespace std;

int main()
{
    const int NUM_PATIENTS = 5;

    Patient patients[NUM_PATIENTS];

    // Create doctors
    Doctor doctor1("Dr. Maya Patel", "Emergency Medicine");
    Doctor doctor2("Dr. Marcus Chen", "Trauma Surgery");
    Doctor doctor3("Dr. Elena Ramirez", "Cardiology");

    // Create treatments
    Treatment treatment1("X-Ray and wrist splint", 325.00);
    Treatment treatment2("IV fluids and blood work", 475.50);
    Treatment treatment3("EKG and cardiac monitoring", 820.00);
    Treatment treatment4("CT scan and neurological evaluation", 1450.00);
    Treatment treatment5("Wound cleaning and stitches", 275.75);

    // Create patients
    patients[0] = Patient("Jordan Blake", 21, "Possible broken wrist", 2);
    patients[1] = Patient("Taylor Morgan", 44, "Severe dehydration", 3);
    patients[2] = Patient("Robert Ellis", 67, "Chest pain", 5);
    patients[3] = Patient("Avery Collins", 35, "Head injury after a fall", 4);
    patients[4] = Patient("Sam Wilson", 19, "Deep cut on left hand", 2);

    // Assign doctors
    patients[0].assignDoctor(doctor1);
    patients[1].assignDoctor(doctor1);
    patients[2].assignDoctor(doctor3);
    patients[3].assignDoctor(doctor2);
    patients[4].assignDoctor(doctor1);

    // Assign treatments
    patients[0].assignTreatment(treatment1);
    patients[1].assignTreatment(treatment2);
    patients[2].assignTreatment(treatment3);
    patients[3].assignTreatment(treatment4);
    patients[4].assignTreatment(treatment5);

    // Print Emergency Department Patient Report
    cout << "========================================" << endl;
    cout << "       EMERGENCY DEPARTMENT REPORT      " << endl;
    cout << "========================================" << endl;

    for(int i = 0; i < NUM_PATIENTS; i++)
    {
        cout << endl;
        cout << "PATIENT #" << i + 1 << endl;
        cout << "----------------------------------------" << endl;

        patients[i].printPatient();

        cout << "----------------------------------------" << endl;
    }

    return 0;
}
