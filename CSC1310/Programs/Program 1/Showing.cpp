/*********************************************************************
	Filename:	Showing.cpp
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	function definitions for the Showing class
	
**********************************************************************/

#include "Movie.h"
#include "Showing.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Default constructor
Showing::Showing() {
    movie = nullptr;
    showTime = "";
    auditoriumNumber = 0;
    ticketPrice = 0;
    seatsAvailable = 0;
}

// Parameterized constructor
Showing::Showing(Movie* m, string st, int an, float tp, int sa) {
    movie = m;
    showTime = st;
    auditoriumNumber = an;
    ticketPrice = tp;
    seatsAvailable = sa;
}

// Set the movie pointer
void Showing::setMovie(Movie* m) {
    movie = m;
}

// Set the show time
void Showing::setShowTime(string st) {
    showTime = st;
}

// Set the auditorium number
void Showing::setAuditoriumNumber(int an) {
    auditoriumNumber = an;
}

// Set the ticket price
void Showing::setTicketPrice(float tp) {
    ticketPrice = tp;
}

// Set seats available
void Showing::setSeatsAvailable(int sa) {
    seatsAvailable = sa;
}

// Return the movie pointer
Movie* Showing::getMovie() {
    return movie;
}

// Return the show time
string Showing::getShowTime() {
    return showTime;
}

// Return the auditorium number
int Showing::getAuditoriumNumber() {
    return auditoriumNumber;
}

// Return the ticket price
float Showing::getTicketPrice() {
    return ticketPrice;
}

// Return seats available
int Showing::getSeatsAvailable() {
    return seatsAvailable;
}

// Display edit menu and modify showing attributes
void Showing::editShowing() {
    int pick_edit;
    int pick_auditorium;
    int pick_seats_available;
    float pick_ticket_price;
    string pick_show_time;

    cout << "\nWhat would you like to edit?\n";
    cout << "1. Show Time\n";
    cout << "2. Auditorium Number\n";
    cout << "3. Ticket Price\n";
    cout << "4. Seats Available\n";
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
                cout << "Current show time: " << getShowTime() << endl;
                cout << "New show time: ";
                getline(cin, pick_show_time);
                setShowTime(pick_show_time);
                break;
            case 2:
                cout << "Current auditorium number: " << getAuditoriumNumber() << endl;
                cout << "New auditorium number: ";
                cin >> pick_auditorium;
                setAuditoriumNumber(pick_auditorium);
                break;
            case 3:
                cout << "Current ticket price: $" << getTicketPrice() << endl;
                cout << "New ticket price: $";
                cin >> pick_ticket_price;
                setTicketPrice(pick_ticket_price);
                break;
            case 4:
                cout << "Current seats available: " << getSeatsAvailable() << endl;
                cout << "New seats available: ";
                cin >> pick_seats_available;
                setSeatsAvailable(pick_seats_available);
                break;
        }
        
        cout << "\nWhat would you like to edit?\n";
        cout << "1. Show Time\n";
        cout << "2. Auditorium Number\n";
        cout << "3. Ticket Price\n";
        cout << "4. Seats Available\n";
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

// Print showing details
void Showing::printShowing() {
    cout << "Movie: ";
    if (movie == nullptr) {
        cout << "[NO MOVIE ASSIGNED]\n";
    } else {
        cout << movie->getTitle() << "\n";
    }
    
    cout << "Show Time: " << showTime << "\n";
    cout << "Auditorium: " << auditoriumNumber << "\n";
    cout << fixed << setprecision(2);
    cout << "Ticket Price: $" << ticketPrice << "\n";
    cout << "Seats Available: " << seatsAvailable << "\n";
}