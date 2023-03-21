#ifndef __SONG_H
#define __SONG_H

#include <vector>
#include <fstream>
#include <iostream>

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

using namespace std;

class Song {
    private:
        //	title – a lowercase string
        string title;
        //	artist – a lowercase string
        string artist;
        //	genre – a lowercase string
        string genre;
        //	rating – an integer in the range [1, 5]
        int rating;
    public: 
    // Default value constructor. 
    Song();
    // Explicit value constructor. 
    Song(string titleParam, string artistParam, string genreParam, int ratingParam);

    string getTitle();
    void setTitle(string titleParam);
    string getArtist();
    void setArtist(string artistParam);
    string getGenre();
    void setGenre(string genreParam);
    int getRating();
    void setRating(int ratingParam);
    // Returns a string representation of the value of the attribute parameter
    // For example, if the attribute is “rating”, returns the value of the rating attribute
    string getStringAttributeValue(string attributeName);
    void setAttributeValueFromString(const string &attributeName, const string &attributeValue);
    void displaySong();
    string toString();
};

class SongLibrary {
    private:
    // songs - a dynamic array of Song objects that is perfectly fit to the number of songs
	// This means you must resize your array and properly free memory with every add and remove
    Song* songs;
	// numSongs - an integer representing the size of the songs array
    int numSongs;

    public:
    // Default Constructor
    SongLibrary();
    // Stack Constructor
    SongLibrary(const int numSongs);
    // Destructor that frees songs memory and sets songs to NULL
	// Sets numSongs to 0
    ~SongLibrary();
    // Opens a file using the passed in string file path
	// Reads song data in from the file that is the format specified in library.txt included in the starter code (song title, artist, genre, and rating with a blank line between song data)
	// Adds Songs to song library in order read in from the file
	// Closes the file
    void performLoad(string fileName);
    // Opens a file using the passed in string file path
	// Writes Song data from the library to the file that is the format specified in library.txt included in the starter code (song title, artist, genre, and rating with a blank line between song data)
    // Closes the file
    void performSave(string fileName);
    // Sorts the library by the attribute parameter
	// Calls the getStringAttributeValue() member function to get a Song’s value for the sort attribute
    void performSort(string attribute);
    /*a.	Searches the library for the first Song with searchAttribute equal to searchAttributeValue. For example, if the searchAttribute is “title” and searchAttributeValue is “smooth”, then this function searches for the first Song with title attribute equal to “smooth”
    b.	Returns true if a Song is found and false otherwise. 
    c.	Also returns the found Song and index of the found Song via output parameters*/
    bool performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index);
    bool performSearchByIndex(int index, Song*foundSong);
    /*a.	Adds the Song parameter to the end of the library
    b.	This requires dynamically allocated an array of size one bigger, copying the old array into the new array, freeing the old array, and inserting the new Song at the last position in the new array.
    c.	Be cautious of any special cases!!*/
    void performAddSong(Song newSong);
    void performAddSongFromString(string attributes, const char delimiter);
    /*a.	Removes a Song from the library based on its index in the array
    b.	This requires dynamically allocated an array of size one smaller, copying the old array into the new array (minus the song to be removed), and freeing the old array.
    c.	Be cautious of any special cases!! */
    void performRemoveSong(int indexToRemove);
    /*Updates the Song’s attribute at indexToEdit to have the new value newAttributeValue*/
    void performEditSong(int indexToEdit, string attributeName, string newAttributeValue);
    void displayLibrary();
    void removeAllSongs();
    void selectionSort(Song* songs, string &attributeName, const int numSongs);
    void swapString(Song* lValue, Song* rValue);
};

string convertToLowercase(string s);
string getNextToken(string &line, int startingIndex, char delimiter);

#endif