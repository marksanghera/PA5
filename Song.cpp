#include "Song.h"

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

// Initializes string attributes to the empty string and int attributes to 1
Song::Song () {
    title = "";
    artist = "";
    genre = "";
    rating = 1;
}


// Initializes title, artist, genre, and rating based on the parameters in that order. 
// Calls setRating() to set the rating so basic range checking is performed.
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
    title = titleParam;
    artist = artistParam;
    genre = genreParam;
    setRating(ratingParam);
}

string Song::getTitle() {
    return title;
}
void Song::setTitle(string titleParam) {
    title = titleParam;
}
string Song::getArtist() {
    return artist;
}
void Song::setArtist(string artistParam) {
    artist = artistParam;
}
string Song::getGenre() {
    return genre;
}
void Song::setGenre(string genreParam) {
    genre = genreParam;
}
int Song::getRating() {
    return rating;
}
//	rating – check if the argument is in the range [1, 5]
void Song::setRating(int ratingParam) {
    if(ratingParam < 1 || ratingParam > 5) {
        cerr << "Invalid rating. Valid values are 1-5." << endl;
    }
    else {
        rating = ratingParam;
    }
}
// Returns the string s in all lower case letters
// Note that this function is not a member function of Song because it doesn’t operate on Song state
string convertToLowercase(string s) {
    string lowercase = s;
    for(int i = 0; i < s.size(); i++) {
        lowercase[i] = tolower(s[i]);
    }
    
    return lowercase;
}

string Song::toString() {
    string song;
    song = title + "," + artist + "," + genre + "," + to_string(rating);
    return song;
}

void Song::displaySong() {
    cout << toString() << endl;
}


string Song::getStringAttributeValue(string attributeName) {
    if(attributeName == "title") {
        return getTitle();
    }
    else if(attributeName == "artist") {
        return getArtist();
    }
    else if(attributeName == "genre") {
        return getGenre();
    }
    else if(attributeName == "rating") {
        return to_string(getRating());
    }
    else{
        cerr << "Invalid search attribute: " << attributeName << endl;
    }
    return "";
}

void Song::setAttributeValueFromString(const string &attributeName, const string &attributeValue) {
    if(attributeName == "title") {
        setTitle(attributeValue);
    }
    else if(attributeName == "artist") {
        setArtist(attributeValue);
    }
    else if(attributeName == "genre") {
        setGenre(attributeValue);
    }
    else if(attributeName == "rating") {
        setRating(stoi(attributeValue));
    }
    else{
        cerr << "Invalid search attribute: " << attributeName << endl;
    }
}