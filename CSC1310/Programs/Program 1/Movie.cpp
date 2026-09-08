#include "Movie.h"
#include "Showing.h"
#include "Theater.h"

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
        Movie(){
            title = "";
            releaseYear = 0;
            runtimeMinutes = 0;
            rating = "Unknown";
        };

        Movie(string t, int ry, int rm, string r){
            title = t;
            releaseYear = ry;
            runtimeMinutes = rm;
            rating = r;
        };

        void setTitle(string st){
            title = st;
        };

        void setReleaseYear(int sry){
            releaseYear = sry;
        };

        void setRuntimeMinutes(int srm){
            runtimeMinutes = srm;
        };

        void setRating(string sr){
            rating = sr;
        };

        string getTitle(){
            return title;
        };

        int getReleaseYear(){
            return releaseYear;
        };

        int getRuntimeMinutes(){
            return runtimeMinutes;
        };

        string getRating(){
            return rating;
        };

        void editMovie();
        
        void printMovie();

};