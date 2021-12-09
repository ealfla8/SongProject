#include <iomanip> //manipulates the output 
#include <iostream> //allows me to use cout, cin..
#include <fstream> //filestream (has the capabiltities of both ostream and ifstream)
#include <vector> 
#include <string> 
#include <sstream>
#include <algorithm>

#include "Song.h"

using namespace std; 

void GetDataFromFile(string filePath, vector<Song>& songs){
    ifstream inFile(filePath); 

    if(inFile.is_open()){

        //Read the heading data from the file 
        string lineFromFile; 
        getline(inFile, lineFromFile); 

        //As long as there is a string to read 
        while( getline(inFile, lineFromFile) ){
            
                istringstream stream(lineFromFile); 

                //Temporary variables to get the data from the file
                string songTitle; 
                string artistName; 
                string album; 
                string genre; 
                string favLyric; 

                getline(stream, songTitle, ',');
                getline(stream, artistName, ','); 
                getline(stream, album, ','); 
                getline(stream, genre, ','); 
                getline(stream, favLyric); 

                Song a(songTitle, artistName, album, genre, favLyric); 
                songs.push_back(a); 
        }
    }  
    else 
    {
        cout << "File could not be opened" << endl; 
    }
} 

void ListAllSongs(vector<Song>& songs){
    for(int i=0; i<songs.size(); i++) 
        songs.at(i).PrintInfo(); 
}

void PrintSongTitles(vector<Song>& songs){
    for(int i=0; i<songs.size(); i++){
        cout << songs.at(i).getSongTitle() << endl; 
    }
}

void FindArtist(vector<Song>& songs, string artist){
    bool ArtistFound = false; 
    cout << "Songs from " << artist << ":" << endl; 
    for(int i=0; i<songs.size(); i++){
        if(songs.at(i).getArtistName() == artist){
            ArtistFound = true; 
            string title = songs.at(i).getSongTitle(); 
            cout << title << endl;
        }
    }
    if(!ArtistFound){
        cout << "No songs found for this artist" << endl;
    }
}

void Alphabetize(vector<Song>& songs){
    sort(songs.begin(), songs.end());
}

int main(){

    vector<Song> songs; 
    vector<string> songTitles; 

    GetDataFromFile("Songs.csv", songs); 

    cout << "Type in the number of the choice you would like. " << endl; 
    
    cout << "1. List all songs with their info." << endl; 
    cout << "2. List all songs of a particular artist." << endl; 
    cout << "3. Alphabetize the song titles." << endl; 

    int input;
    cin >> input; 
    if(input == 1){
        ListAllSongs(songs); 
    } 
    if (input ==2){
        cout << "Type the artist name." << endl; 
        string artist; 
        cin.ignore();
        getline(cin, artist); 
        FindArtist(songs,artist); 
    } 
    if(input == 3){
        Alphabetize(songs); 
        PrintSongTitles(songs); 
    }
    
}
