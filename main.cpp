#include <iomanip> //manipulates the output 
#include <iostream> //allows me to use cout, cin..
#include <fstream> //filestream (has the capabiltities of both ostream and ifstream)
#include <vector> 
#include <string> 
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

#include "Song.h"

using namespace std; 

vector<Song> GetDataFromFile(string filePath){
    ifstream inFile(filePath); 
    vector<Song> songs; 

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
    return songs; 
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

map<string, int> ListAllArtists(vector<Song>& songs){
    map<string,int> artistNames; 
    string name; 
    for(int i=0; i<songs.size(); i++){
        name = songs.at(i).getArtistName(); 
        if(artistNames.find(name) == artistNames.end()){ //the name is not in the set yet
            artistNames.emplace(name,0); 
        }   
    }
    return artistNames;
}

void SettingArtistNameMap(map<string, int>& artistNameMap, vector<Song>&songs){
    
}
void PrintArtistNameMap(map<string,int>& artistNameMap){ 
    map<string,int>::iterator iter;  
    for(iter = artistNameMap.begin(); iter != artistNameMap.end(); iter++){
        cout << "Artist Name: " << iter->first << endl; 
        cout << "Number of songs: " << iter->second << endl; 
    }
}


int main(){

    vector<Song> songs = GetDataFromFile("Songs.csv"); 
    Alphabetize(songs); 
    map<string,int> artistNameMap = ListAllArtists(songs); 


    cout << "Type in the number of the choice you would like. " << endl; 
    
    cout << "1. List all songs in alphabetical order with their info." << endl; 
    cout << "2. List all songs of a particular artist." << endl; 
    cout << "3. List the number of songs that are by each artist." << endl;  //I should make a map??..
    
    int input;
    cin >> input; 
    if(input == 1){
        ListAllSongs(songs); 
    } 
    else if (input ==2){
        cout << "Type the artist name." << endl; 
        string artist; 
        cin.ignore();
        getline(cin, artist); 
        FindArtist(songs,artist); 
    } 
    else if (input ==3){
        PrintArtistNameMap(artistNameMap); 
    } 
  
    
}
