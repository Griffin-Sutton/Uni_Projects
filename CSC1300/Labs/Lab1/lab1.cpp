#include <iostream>
using namespace std;

int main(){
	double fahrenheit;
	double celsius;
	
		cout << "\n What is the temperature in Celsius? ";
		cin >> celsius;
		
		fahrenheit = celsius * (9.0/5.0) + 32;
		
		cout << endl;
		cout << "RESULT:  " << celsius << " degrees Celsius is ";
		cout << fahrenheit << " degrees Fahrenheit. \n\n";
		
		return 0;
}