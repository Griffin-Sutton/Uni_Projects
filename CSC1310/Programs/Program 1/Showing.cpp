/*********************************************************************
	Filename:	Showing.cpp
	Author:		Griffin Sutton
	Date:		September 8th, 2026
	Purpose:	function definitions for the Showing class
	
**********************************************************************/

#include "Movie.h"
#include "Showing.h"
#include "Theater.h"

#include <string>
using namespace std;

class Showing{
    private:
        Movie* movie;
        string showTime;
        int auditoriumNumber;
        float ticketPrice;
        int seatsAvailable;
    public:
        Showing(){
            movie = nullptr;
            showTime = "";
            auditoriumNumber = 0;
            ticketPrice = 0;
            seatsAvailable;
        };

        Showing(Movie* m, string st, int an, float tp, int sa){
            movie = m;
            showTime = st;
            auditoriumNumber = an;
            ticketPrice = tp;
            seatsAvailable = sa;
        };

        void setMovie(Movie* m){
            movie = m;
        };

        void setShowTime(string st){
            showTime = st;
        };

        void setAuditoriumNumber(int an){
            auditoriumNumber = an;
        };

        void setTicketPrice(float tp){
            ticketPrice = tp;
        };

        void setSeatsAvailable(int sa){
            seatsAvailable = sa;
        };

        Movie* getMovie(){
            return movie;
        };

        string getShowTime(){
            return showTime;
        };

        int getAuditoriumNumber(){
            return auditoriumNumber;
        };

        float getTicketPrice(){
            return ticketPrice;
        };

        int getSeatsAvailable(){
            return seatsAvailable;
        };

        void editShowing();
        void printShowing();
};