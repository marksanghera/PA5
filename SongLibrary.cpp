#include "Song.h"

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

SongLibrary::SongLibrary() {
    songs = nullptr;
    numSongs = 0;
}

SongLibrary::SongLibrary(const int numSongs) {
    this->numSongs = numSongs;
    this->songs = new Song[numSongs];
}

SongLibrary::~SongLibrary() {
    delete[] songs;
    songs = nullptr;
    numSongs = 0;
}

/*a.	Adds the Song parameter to the end of the library
    b.	This requires dynamically allocated an array of size one bigger, copying the old array into the new array,
     freeing the old array, and inserting the new Song at the last position in the new array.
    c.	Be cautious of any special cases!!*/
void SongLibrary::performAddSong(Song newSong) {
    Song* oldArray = songs;
    songs = new Song[numSongs + 1];
    for(int i = 0; i < numSongs; i++) {
        songs[i] = oldArray[i];
    }
    songs[numSongs] = newSong;
    delete[] oldArray;
    numSongs++;
}

void SongLibrary::performAddSongFromString(string attributes, const char delimiter, bool sort, string option) {
    Song song;
    int startingIndex = 0;

    song.setTitle(getNextToken(attributes, startingIndex, delimiter));
    startingIndex += song.getTitle().size() + 1;
    song.setArtist(getNextToken(attributes, startingIndex, delimiter));
    startingIndex += song.getArtist().size() + 1;
    song.setGenre(getNextToken(attributes, startingIndex, delimiter));
    startingIndex += song.getGenre().size() + 1;
    song.setRating(stoi(getNextToken(attributes, startingIndex, delimiter)));
    if(option == "add") {
        performAddSong(song);
    }
    else {
        performInsertSong(song);
    }

    //if(sort) {
    //    performSort(currentlySorttedBy);
    //}
}

void SongLibrary::performInsertSong(Song newSong) {
    Song* oldArray = songs;
    songs = new Song[numSongs + 1];
    bool inserted = false;
    for(int i = 0, j = 0; i < numSongs; j++) {
        if(!inserted && (oldArray + i)->getStringAttributeValue(currentlySorttedBy) > newSong.getStringAttributeValue(currentlySorttedBy)) {
            songs[j] = newSong;
            inserted = true;
        }
        else {
            songs[j] = oldArray[i];
            i++;
        }
    }
    delete[] oldArray;
    numSongs++;
}

/*  a.	Removes a Song from the library based on its index in the array
    b.	This requires dynamically allocated an array of size one smaller, copying the old array into the new array (minus the song to be removed), and freeing the old array.
    c.	Be cautious of any special cases!! */
void SongLibrary::performRemoveSong(int indexToRemove) {
    if(numSongs > 0) {
        Song* oldArray = songs;
        songs = new Song[numSongs - 1];
        for(int i = 0, j = 0; i < numSongs - 1; i++) {
            if(j == indexToRemove) {
                j++;
            }
            songs[i] = oldArray[j];
            j++;
        }
        delete[] oldArray;
        numSongs--;
    }
}

string getNextToken(string &line, int startingIndex, char delimiter) {
    int endingIndex = line.find(delimiter, startingIndex);
    return line.substr(startingIndex, endingIndex - startingIndex);
}

// Opens a file using the passed in string file path
// Reads song data in from the file that is the format specified in library.txt included in the starter code (song title, artist, genre, and rating with a blank line between song data)
// Adds Songs to song library in order read in from the file
// Closes the file
void SongLibrary::performLoad(string filename) {
    ifstream inputFile;
    string line;
    const char delimiter = ',';

    inputFile.open(filename);
    if(inputFile.is_open()) {
        
        while(!inputFile.eof()) {
            getline(inputFile, line);
            // check if the line is empty
            if(line.size() == 0) {
                continue;
            }
            performAddSongFromString(line, delimiter, false, "add");
        }
        performSort(currentlySorttedBy);
        inputFile.close();
    }
    else {
        cerr << "Input File name: " << filename << " is invalid." << endl;
    }
}

// Opens a file using the passed in string file path
// Writes Song data from the library to the file that is the format specified in library.txt included in the starter code (song title, artist, genre, and rating with a blank line between song data)
// Closes the file
void SongLibrary::performSave(string fileName) {
    ofstream outputFile;
    string line;

    outputFile.open(fileName);
    if(outputFile.is_open()) {
        for(int i = 0; i < numSongs; i++) {
            line = songs[i].toString();
            outputFile << line << endl;
        }
        outputFile.close();
    }
}

/*
a.  Searches the library for the first Song with searchAttribute equal to searchAttributeValue. For example, if the searchAttribute is “title” 
    and searchAttributeValue is “smooth”, then this function searches for the first Song with title attribute equal to “smooth”
b.	Returns true if a Song is found and false otherwise. 
c.	Also returns the found Song and index of the found Song via output parameters*/
bool SongLibrary::performSearch(string searchAttributeName, string searchAttributeValue, Song* foundSong, int* index) {
    if(index == nullptr || foundSong == nullptr) {
        cerr << "Invalid arguments" << endl;
        return false;
    }
    int i = 0;
    for(; i < numSongs; i++) {
        if(songs[i].getStringAttributeValue(searchAttributeName) == searchAttributeValue) {
            *index = i;
            *foundSong = songs[i]; 
            return true;
        }
    }
    return false;
}

bool SongLibrary::performSearchByIndex(int index, Song*foundSong) {
    if(foundSong == nullptr) {
        cerr << "Invalid argument" << endl;
        return false;
    }
    if(index >= 0 && index < numSongs) {
        *foundSong = songs[index];
        return true;
    }
    return false;
}

void SongLibrary::displayLibrary() {
    for(int i = 0; i < numSongs; i++) {
        cout << i << ": ";
        songs[i].displaySong();
    }
}

void SongLibrary::removeAllSongs() {
    delete[] songs;
    songs = nullptr;
    numSongs = 0;
}

void SongLibrary::swapString(Song* lValue, Song* rValue) {
    Song emptyContainer = *lValue;
    *lValue = *rValue;
    *rValue = emptyContainer; 
}

void SongLibrary::selectionSort(Song* songs, string &attributeName, const int numSongs) {
    for(int i = 0; i < numSongs; i++) {
        // assume index of the smallest value is the first element of the first unsorted vector
        int indexOfSmallestValue = i;
        // search through the vector to find the index of the smallest value in the unsorted section of the vector
        for(int j = i + 1; j < numSongs; j++) {
            if((songs + indexOfSmallestValue)->getStringAttributeValue(attributeName) > (songs + j)->getStringAttributeValue(attributeName)) {
                indexOfSmallestValue = j;
            }
        }
        // if index of the smallest value is different than our current unsorted element, then swap
        if(indexOfSmallestValue != i) {
            swapString(songs + i, songs + indexOfSmallestValue);
        }
    }
}

// Sorts the library by the attribute parameter
// Calls the getStringAttributeValue() member function to get a Song’s value for the sort attribute
void SongLibrary::performSort(string attributeName) {
    selectionSort(songs, attributeName, numSongs);
    currentlySorttedBy = attributeName;
}

/*Updates the Song’s attribute at indexToEdit to have the new value newAttributeValue*/
void SongLibrary::performEditSong(int indexToEdit, string attributeName, string newAttributeValue) {
    songs[indexToEdit].setAttributeValueFromString(attributeName, newAttributeValue);
}