/*******************************************************************
	Title: Track.h
	Author:	Griffin Sutton
	Date: October 7th, 2026
	Purpose: Defines the track class to be used as a linked list
*******************************************************************/

#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
using namespace std;

class Track{
    private:
        string track_id;
        int popularity;
        string artist;
        string album_name;
        string track_name;
        bool explicit_flag;

    public:
        Track (){
            track_id = "";
            popularity = 0;
            artist = "";
            album_name = "";
            track_name = "";
            explicit_flag = false;
        }

        Track (string id, int p, string art, string an, string tn, bool ex){
            track_id = id;
            popularity = p;
            artist = art;
            album_name = an;
            track_name = tn;
            explicit_flag = ex;
        }

        friend ostream& operator<<(ostream& out, const Track& track){
            out << "Track ID:    " << track.track_id   << "\n"
                << "Popularity:  " << track.popularity << "\n"
                << "Track Name:  " << track.track_name << "\n"
                << "Artist(s):   " << track.artist     << "\n"
                << "Album:       " << track.album_name << "\n"
                << "Explicit:    " << track.explicit_flag;
            return out;
        }
};

#endif