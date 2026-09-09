/*********************************************************************
	Filename:	Showing.h
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	Header file for the Showing Class prototype
	
**********************************************************************/

#ifndef SHOWING_H
#define SHOWING_H

#include <string>
#include <iostream>
using namespace std;

class Showing {
	private:
		Movie* movie;
		string showTime;
		int auditoriumNumber;
		float ticketPrice;
		int seatsAvailable;
	public:
		Showing();
		Showing(Movie*, string, int, float, int);
		void setMovie(Movie*);
		void setShowTime(string);
		void setAuditoriumNumber(int);
		void setTicketPrice(float);
		void setSeatsAvailable(int);
		Movie* getMovie();
		string getShowTime();
		int getAuditoriumNumber();
		float getTicketPrice();
		int getSeatsAvailable();
		void editShowing();
		void printShowing();
};

#endif