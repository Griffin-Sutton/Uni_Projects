/************************************************************************
 *	Title:             mod3a.cpp
 *  Module:            3
 *	Author:            Griffin Sutton
 *	Date of Creation:  02/04/26
 *	Purpose:           print out math equations that use ints and doubles
 ************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	
	int result;
	int random_num;
	double more_money = 0.75;
	
	result = 6 - 3 * 2 + 7 - 1 + 17 % 2;
	cout << result << endl;
	
	result = more_money * result;
	cout << result << endl;
	
	result = (6 - 3) * 2 + (7 - 1) + 17 % 2;
	cout << result << endl;
	
	more_money = more_money * result;
	cout << setprecision(4) << more_money << endl;
	
	srand(time(0));
	random_num = rand() % 21 + 5;
	cout << random_num << endl;
	
	return 0;
	
}