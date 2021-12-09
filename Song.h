//Song.h file 

#pragma once 
#include <iostream> //check what I need iostream for 
#include <string> 
using namespace std; 

class Song{
    private: 
        string songTitle; 
        string artistName; 
        string album; 
        string genre; 
        string favLyric; 

    public: 

        //Constructor
        Song(string songTitle, string artistName, string album, string genre, string favLyric); 

        //Accesor Functions
        string getSongTitle(); 
        string getArtistName(); 
        string getAlbumName(); 
        string getGenre();
        string getFavLyric(); 

        void PrintInfo(); 

        bool operator<(Song& p); 
    
}; 
