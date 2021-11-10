#include <iomanip> //manipulates the output 
#include <iostream> //allows me to use cout, cin..
#include <fstream> //filestream (has the capabiltities of both ostream and ifstream)
#include <vector> 
#include <string> 
#include <sstream>

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
    for(int i=0; i<songs.size(); i++) //Why does it say I have one more song than I have... 
        songs.at(i).PrintInfo(); 
}

void FindArtist(vector<Song>& songs, string artist){
    cout << "Songs from " << artist << ":" << endl;  //should print out something if artist not found
    for(int i=0; i<songs.size(); i++){
        if(songs.at(i).getArtistName() == artist){
            string title = songs.at(i).getSongTitle(); 
            cout << title << endl;
        }
    }
}

int main(){

    vector<Song> songs; 
    GetDataFromFile("Songs.csv", songs); 

    cout << "Type in the number of the choice you would like. " << endl; 
    
    cout << "1. List all songs with their info." << endl; 
    cout << "2. List all songs of a particular artist." << endl; 

    int input;
    cin >> input; 
    if(input == 1){
        ListAllSongs(songs); 
    } 
    if (input ==2){
        cout << "Type the artist name." << endl; 
        string artist; 
        cin >> artist; //fix this so it works with names with more than one word
        FindArtist(songs,artist); 
    }


    //cout << "The number of songs is " << songs.size() << "." << endl; //Currently, I have 10 songs.. It says I have 11 songs... 
    
    
}
