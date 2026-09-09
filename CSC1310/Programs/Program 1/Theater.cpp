/*********************************************************************
	Filename:	Theater.cpp
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	function definitions for the Theater class
	
**********************************************************************/

#include "Theater.h"
#include <iostream>
using namespace std;


// Parameterized Constructor
Theater::Theater(string name, int max_m, int max_s) {
    theaterName = name;
    
    if (max_m < 1) {
        maxMovies = 1;
    } else {
        maxMovies = max_m;
    }
    
    if (max_s < 1) {
        maxShowings = 1;
    } else {
        maxShowings = max_s;
    }

    numMovies = 0;
    numShowings = 0;

    movieArray = new Movie*[maxMovies];
    for (int i = 0; i < maxMovies; i++) {
        movieArray[i] = nullptr;
    }

    showingArray = new Showing*[maxShowings];
    for (int i = 0; i < maxShowings; i++) {
        showingArray[i] = nullptr;
    }
}

// Destructor
Theater::~Theater() {
    cout << "Releasing showings...\n";
    for (int i = 0; i < numShowings; i++) {
        delete showingArray[i];
    }
    delete[] showingArray;
    showingArray = nullptr;

    cout << "Releasing movies...\n";
    for (int i = 0; i < numMovies; i++) {
        delete movieArray[i];
    }
    delete[] movieArray;
    movieArray = nullptr;
}

// Return current number of movies
int Theater::getNumMovies() {
    return numMovies;
}

// Return current number of showings
int Theater::getNumShowings() {
    return numShowings;
}

// Add a movie pointer to the theater array
void Theater::addMovie() {
    string movie_name;
    string rating;
    int year;
    int runtime;
    Movie* new_movie;

    if (numMovies >= maxMovies) {
        cout << "Sorry, no more movies can be added. You have hit max capacity.\n";
        return;
    }
    
    cin.ignore();
    cout << "Movie title: ";
    getline(cin, movie_name);
                
    cout << "Release year: ";
    cin >> year;

    cout << "Runtime in minutes: ";
    cin >> runtime;

    cin.ignore();
    cout << "Rating: ";
    getline(cin, rating);

    new_movie = new Movie(movie_name, year, runtime, rating);
    movieArray[numMovies] = new_movie;
    numMovies++;

    cout << movie_name << " was added.\n";
}

// Edit a movie utilizing the internal loop
void Theater::editMovie() {
    int pick_movie;

    if (numMovies == 0) {
        cout << "There are no movies to edit.\n";
        return;
    }

    printMovieNames();
    cout << "Which movie would you like to edit? ";
    cin >> pick_movie;

    while (pick_movie <= 0 || pick_movie > numMovies) {
        cout << "Oops! You didn't enter a valid movie number.\n";
        cout << "Which movie would you like to edit? ";
        cin.ignore(10000, '\n');
        cin >> pick_movie;
    }

    movieArray[pick_movie - 1]->editMovie();
}

// Add a showing pointer to the theater array
void Theater::addShowing() {
    int pick_movie;
    int user_auditorium;
    int user_seats;
    float user_ticket_price;
    string user_show_time;
    Showing* new_showing;

    if (numMovies == 0) {
        cout << "You must have at least one movie before creating a showing.\n";
        return;
    }
    
    if (numShowings >= maxShowings) {
        cout << "Sorry, no more showings can be added. You have hit max capacity.\n";
        return;
    }
    
    printMovieNames();
    cout << "Which movie is being shown? ";
    cin >> pick_movie;
    
    while (pick_movie <= 0 || pick_movie > numMovies) {
        cout << "Oops! You didn't enter a valid movie number.\n";
        cout << "Which movie is being shown? ";
        cin.ignore(10000, '\n');
        cin >> pick_movie;
    }

    cin.ignore();
    cout << "Show time (example: 7:30 PM): ";
    getline(cin, user_show_time);
                
    cout << "Auditorium number: ";
    cin >> user_auditorium;

    cout << "Ticket price: $";
    cin >> user_ticket_price;

    cout << "Seats available: ";
    cin >> user_seats;

    new_showing = new Showing(movieArray[pick_movie - 1], user_show_time, user_auditorium, user_ticket_price, user_seats);
    showingArray[numShowings] = new_showing;
    numShowings++;
    
    cout << "Showing was added.\n";
}

// Edit a showing utilizing the internal loop
void Theater::editShowing() {
    int pick_showing;

    if (numShowings == 0) {
        cout << "There are no showings to edit.\n";
        return;
    }
    
    printShowingNames();
    cout << "Which showing would you like to edit? ";
    cin >> pick_showing;
    
    while (pick_showing <= 0 || pick_showing > numShowings) {
        cout << "Oops! You didn't enter a valid showing number.\n";
        cout << "Which showing would you like to edit? ";
        cin.ignore(10000, '\n');
        cin >> pick_showing;
    }

    showingArray[pick_showing - 1]->editShowing();
}

// Output all configured movie structures
void Theater::printMovies() {
    if (numMovies == 0) {
        cout << "There are no movies.\n";
        return;
    }

    cout << "\n========== MOVIES ==========\n";
    for (int i = 0; i < numMovies; i++) {
        cout << "Movie #" << (i + 1) << endl;
        movieArray[i]->printMovie();
    }
}

// Output all configured showing structures
void Theater::printShowings() {
    if (numShowings == 0) {
        cout << "There are no showings.\n";
        return;
    }

    cout << "\n========== SHOWINGS ==========\n";
    for (int i = 0; i < numShowings; i++) {
        cout << "Showing #" << (i + 1) << endl;
        showingArray[i]->printShowing();
    }
}

// Sub-routine to list available movie objects
void Theater::printMovieNames() {
    for (int i = 0; i < numMovies; i++) {
        cout << i + 1 << ". " << movieArray[i]->getTitle() << endl;
    }
}

// Sub-routine to list available showing objects
void Theater::printShowingNames() {
    for (int i = 0; i < numShowings; i++) {
        cout << i + 1 << ". " << showingArray[i]->getMovie()->getTitle() << " at " << showingArray[i]->getShowTime() << endl;
    }
}