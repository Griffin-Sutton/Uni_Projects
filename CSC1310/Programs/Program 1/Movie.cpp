/*********************************************************************
	Filename:	Movie.cpp
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	function definitions for the Movie class
	
**********************************************************************/

#include "Movie.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Movie::Movie() {
    title = "";
    releaseYear = 0;
    runtimeMinutes = 0;
    rating = "Unknown";
}

// Parameterized constructor
Movie::Movie(string t, int ry, int rm, string r) {
    title = t;
    releaseYear = ry;
    runtimeMinutes = rm;
    rating = r;
}

// Set the movie title
void Movie::setTitle(string st) {
    title = st;
}

// Set the release year
void Movie::setReleaseYear(int sry) {
    releaseYear = sry;
}

// Set the runtime in minutes
void Movie::setRuntimeMinutes(int srm) {
    runtimeMinutes = srm;
}

// Set the movie rating
void Movie::setRating(string sr) {
    rating = sr;
}

// Return the movie title
string Movie::getTitle() {
    return title;
}

// Return the release year
int Movie::getReleaseYear() {
    return releaseYear;
}

// Return the runtime minutes
int Movie::getRuntimeMinutes() {
    return runtimeMinutes;
}

// Return the rating
string Movie::getRating() {
    return rating;
}

// Display edit menu and modify attributes
void Movie::editMovie() {
    int pick_edit;
    int pick_year;
    int pick_runtime;
    string pick_title;
    string pick_rating;

    cout << "\nWhat would you like to edit?\n";
    cout << "1. Title\n";
    cout << "2. Release Year\n";
    cout << "3. Runtime\n";
    cout << "4. Rating\n";
    cout << "5. Done Editing\n";
    cout << "Choose 1-5: ";
    cin >> pick_edit;

    while (pick_edit <= 0 || pick_edit > 5) {
        cout << "Oops! You didn't enter a valid number.\n";
        cout << "What would you like to edit? ";
        cin.ignore(10000, '\n');
        cin >> pick_edit;
    }

    while (pick_edit != 5) {
        switch (pick_edit) {
            case 1:
                cin.ignore();
                cout << "Current title: " << getTitle() << endl;
                cout << "New title: ";
                getline(cin, pick_title);
                setTitle(pick_title);
                break;
            case 2:
                cout << "Current release year: " << getReleaseYear() << endl;
                cout << "New release year: ";
                cin >> pick_year;
                setReleaseYear(pick_year);
                break;
            case 3:
                cout << "Current runtime: " << getRuntimeMinutes() << endl;
                cout << "New runtime: ";
                cin >> pick_runtime;
                setRuntimeMinutes(pick_runtime);
                break;
            case 4:
                cin.ignore();
                cout << "Current rating: " << getRating() << endl;
                cout << "New rating: ";
                getline(cin, pick_rating);
                setRating(pick_rating);
                break;
        }

        cout << "\nWhat would you like to edit?\n";
        cout << "1. Title\n";
        cout << "2. Release Year\n";
        cout << "3. Runtime\n";
        cout << "4. Rating\n";
        cout << "5. Done Editing\n";
        cout << "Choose 1-5: ";
        cin >> pick_edit;

        while (pick_edit <= 0 || pick_edit > 5) {
            cout << "Oops! You didn't enter a valid number.\n";
            cout << "What would you like to edit? ";
            cin.ignore(10000, '\n');
            cin >> pick_edit;
        }
    }
}

// Print all movie details
void Movie::printMovie() {
    cout << "Title: " << getTitle() << endl;

    if (getReleaseYear() == 0) {
        cout << "Release Year: Unknown\n";
    } else {
        cout << "Release Year: " << getReleaseYear() << endl;
    }

    if (getRuntimeMinutes() == 0) {
        cout << "Runtime: Unknown\n";
    } else {
        cout << "Runtime: " << getRuntimeMinutes() << " minutes\n";
    }

    cout << "Rating: " << getRating() << endl;
}