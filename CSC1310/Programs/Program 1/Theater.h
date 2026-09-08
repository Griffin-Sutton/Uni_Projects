#ifndef THEATER_H
#define THEATER_H

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