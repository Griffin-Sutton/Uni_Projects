/*********************************************************************
	Filename:	Movie.h
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	Header file for the Movie Class prototype
	
**********************************************************************/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie {
	private:
		string title;
		int releaseYear;
		int runtimeMinutes;
		string rating;
	public:
		Movie();
		Movie(string, int, int, string);
		void setTitle(string);
		void setReleaseYear(int);
		void setRuntimeMinutes(int);
		void setRating(string);
		string getTitle();
		int getReleaseYear();
		int getRuntimeMinutes();
		string getRating();
		void editMovie();
		void printMovie();
};

#endif