#ifndef TREATMENT_H
#define TREATMENT_H
using namespace std;
class Treatment {
    private:
        string description;
        double cost;
    public:
        Treatment();
        Treatment(string, double);
        void setDescription(string);
        void setCost(double);
        string getDescription() const;
        double getCost() const;
        void printTreatment();
};

#endif