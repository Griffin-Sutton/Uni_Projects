/*********************************************************************
	Filename:	Theater.cpp
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	function definitions for the Theater class
	
**********************************************************************/

#include "Movie.h"
#include "Showing.h"
#include "Theater.h"

#include <string>
using namespace std;

class Theater{
    private:
        string theaterName;
        Movie** movieArray;
        int numMovies;
        int maxMovies;
        Showing** showingArray;
        int numShowings;
        int maxShowings;
    public:
        Theater();

        ~Theater();

        int getNumMovies(){
            return numMovies;
        };

        int getNumShowings(){
            return numShowings;
        };

        void addMovie(){

        };

        void editMovie();

        void addShowing();

        void editShowing();

        void printMovies();

        void printShowings();

        void printMovieNames();

        void printShowingNames();
};