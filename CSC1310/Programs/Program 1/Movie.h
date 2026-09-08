#ifndef MOVIE_H
#define MOVIE_H

#include <string>
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