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