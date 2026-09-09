/*********************************************************************
	Filename:	Theater.h
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	Header file for the Theater Class prototype
	
**********************************************************************/

#ifndef THEATER_H
#define THEATER_H

#include "Movie.h"
#include "Showing.h"
#include <string>
#include <iostream>
using namespace std;

class Theater {
	private:
		string theaterName;
		Movie** movieArray;
		int numMovies;
		int maxMovies;
		Showing** showingArray;
		int numShowings;
		int maxShowings;
	public:
		Theater(string, int, int);
		~Theater();
		int getNumMovies();
		int getNumShowings();
		void addMovie();
		void editMovie();
		void addShowing();
		void editShowing();
		void printMovies();
		void printShowings();
		void printMovieNames();
		void printShowingNames();
};

#endif