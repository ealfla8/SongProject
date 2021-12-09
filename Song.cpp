#include <iostream>  
#include <string> 
#include "Song.h"
using namespace std; 


Song::Song(string songTitle, string artistName, string album, string genre, string favLyric)
{
    this->songTitle = songTitle; 
    this->artistName = artistName; 
    this->album = album; 
    this->genre = genre; 
    this->favLyric = favLyric; 
}

string Song::getSongTitle(){
    return songTitle; 
}

string Song::getArtistName(){
    return artistName; 
}

string Song::getAlbumName(){
    return album; 
}

string Song::getGenre(){
    return genre; 
}

string Song::getFavLyric(){
    return favLyric; 
}

void Song::PrintInfo(){
    cout << "Title: " << songTitle << endl; 
    cout << "Artist Name: " << artistName << endl; 
    cout << "Album: " << album << endl; 
    cout << "Genre: " << genre << endl; 
    cout << "Favorite Lyric: " << favLyric << endl; 
    cout << endl; 
} 

bool Song::operator<(Song& p) {
    return songTitle < p.getSongTitle(); 
}
