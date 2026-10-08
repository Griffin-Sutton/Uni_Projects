/*
	Filename: lab5.cpp
	Author: April Crockett and Griffin Sutton
	Date: 9/27/2026
	Purpose: Practice with vectors
*/

#include <iostream>
#include <vector>
#include <string>
#include <parallel/algorithm>

using namespace std;

////*********************LOOK! Add function prototypes here
void printActivities(vector<string>&, vector<int>&);
void selectionSort(vector<string>&, vector<int>&);

int main() {

	string temp;
	int rate;
	//*********************LOOK! Create activities vector (should be a string vector)
    vector<string> activities;
	
	//*********************LOOK! Create rating vector (should be a int vector)
    vector<int> rating;

	//Tell user what is going on (give instructions)
	cout << "\n\nWelcome to Crockett Farms Pumpkin Festival!\n";
	cout << "Please enter each activity you did at the festival and score the activities.\n";
	cout << "\nThen, rate the activity from 1 to 100 where 1 means the activity was buns \n"
		     << "and 100 means it was your favorite activity you have ever done in your life.";
	cout << "\n\nEnter \"done\" to quit entering activities.\n\n";
	
	//Begin getting the activities from the user.
	cout << "Activity: ";
	getline(cin, temp);
	while(temp != "done"){
		//*********************LOOK! Add activity to the end of the activities vector
		activities.push_back(temp);
		cout << "\nRating: ";
		cin >> rate;
		cin.ignore();
		
		//*********************LOOK! Add rate to the end of the rating vector
		rating.push_back(rate);
		
		cout << "\nActivity: ";
		getline(cin, temp);
	}
	
	//Print the full list of activities
    cout << "\n\nActivities Entered:";
    printActivities(activities, rating);

    // Sort the parallel vectors by rating
    selectionSort(activities, rating);

    cout << "\nActivities Sorted by Rating:";
    printActivities(activities, rating);

    return 0;
}

//*********************LOOK! Complete the printActivities function
// Print all activities and popularity scores
void printActivities(vector<string> &a, vector<int> &r) {
	int size = a.size();

	cout << "\n\nFall Activities:\n";
    cout << "---------------\n";
	for (int i = 0; i < size; i++){
		cout << a.at(i) << ": " << r.at(i) << endl;
	}

}

//*********************LOOK! Write the selectionSort function
// Make sure to use the sort function (from the algorithm library) when you have to swap elements
// Sort activities from highest popularity to lowest popularity
void selectionSort(vector<string> &a, vector<int> &r)
{
	int size = a.size();
	int maxIndex;

    for (int i = 0; i < size - 1; i++) {
        maxIndex = i;

        // find the largest rating from i through the end
        for (int j = i + 1; j < size; j++) {
            if (r.at(j) > r.at(maxIndex)) {
                maxIndex = j;
            }
        }

        // swap BOTH vectors so names stay paired with their ratings
        swap(r.at(i), r.at(maxIndex));
        swap(a.at(i), a.at(maxIndex));
	}
}