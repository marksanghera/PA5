#include <iostream>
#include <fstream>
#include <array>
#include "Song.h"

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

bool search(SongLibrary &dmm, int &index) {
    string attributeName;
    string attributeValue;
    Song foundSong;
    Song* foundSongPtr = &foundSong;
    bool songFound = false;
    cout << "Enter either title, artist, genre, rating, or index: ";
    getline(cin, attributeName);
    cout << "Enter the value for " << attributeName << ": ";
    getline(cin, attributeValue);
    if(attributeName == "index") {
        index = stoi(attributeValue);
        songFound = dmm.performSearchByIndex(index, foundSongPtr);
    }
    else if(attributeName == "title" || attributeName == "artist" || attributeName == "genre" || attributeName == "rating") {
        songFound = dmm.performSearch(attributeName, attributeValue, foundSongPtr, &index);
    }
    else {
        cerr << "Invalid attribute" << endl;
    }
    if(songFound) {
        foundSong.displaySong();
    }
    else {
        cerr << "Song not found" << endl;
    }
    return songFound;
}

void mainMenu() {
    string userSelection;
    SongLibrary dmm;

    do {
        cout << "DMM Menu: select from the following options" << endl;
        cout << "1. load" << endl << "2. store" << endl << "3. display" << endl << "4. sort" << endl << "5. search" << endl
                << "6. add" << endl << "7. insert" << endl << "8. remove" << endl << "9. edit" << endl << "10. exit" << endl;

        cout << "Enter Option: ";
        cin >> userSelection;
        cin.ignore();

        if(userSelection == "load") {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            dmm.performLoad(filename);
            dmm.displayLibrary();
        } 
        else if(userSelection == "store") {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            dmm.performSave(filename);
        }
        else if(userSelection == "display") {
            dmm.displayLibrary();
        }
        else if(userSelection == "sort") {
            string attribute;
            cout << "Select an attribute to sort by: ";
            getline(cin, attribute);
            dmm.performSort(attribute);
            dmm.displayLibrary();
        }
        else if(userSelection == "search") {
            int index = -1;
            search(dmm, index);
        }
        else if(userSelection == "add") {
            string attributes;
            cout << "Provide song title, artist, genre, rating: ";
            getline(cin, attributes);
            cout << attributes << endl;
            dmm.performAddSongFromString(attributes, ',', true, userSelection);
            dmm.displayLibrary();
        }
        else if(userSelection == "insert") {
            string attributes;
            cout << "Provide song title, artist, genre, rating: ";
            getline(cin, attributes);
            cout << attributes << endl;
            dmm.performAddSongFromString(attributes, ',', true, userSelection);
            dmm.displayLibrary();
        }
        else if(userSelection == "remove") {
            int indexToRemove = -1;
            if(search(dmm, indexToRemove)) {
                dmm.performRemoveSong(indexToRemove);
                dmm.displayLibrary();
            }
        }
        else if(userSelection == "edit") {
            int indexToEdit = -1;
            if(search(dmm, indexToEdit)) {
                string line;
                string attributeName;
                string newAttributeValue;
                cout << "Select an attribute to edit and input new value: ";
                getline(cin, line);
                attributeName = getNextToken(line, 0, ',');
                newAttributeValue = getNextToken(line, attributeName.size() + 1, ',');
                dmm.performEditSong(indexToEdit, attributeName, newAttributeValue);
                dmm.displayLibrary();
            }
        }
        else if(userSelection == "exit") {
            return;
        }
        else{
            cerr << "Invalid option" << endl;
        }
    } while(true);
}