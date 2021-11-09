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
                //trying not the comma delimiter getline(stream, favLyric, ','); 
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

int main(){

    //cout << "The file that will be opened is the Songs.csv file" << endl; 

    vector<Song> songs; 
    GetDataFromFile("Songs.csv", songs); 

    cout << songs.size(); //The size of songs  is 44 when I have 11 songs... 
    for(unsigned int i=0; i<songs.size(); i++){
        songs.at(i).PrintInfo(); 
    }
    //Part of my code does not work I think it is with spacing and lyrics.. 
    
}
