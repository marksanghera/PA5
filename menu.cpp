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

void mainMenu() {
    string userSelection;
    SongLibrary dmm;

    do {
        cout << "DMM Menu: select from the following options" << endl;
        cout << "1. load" << endl << "2. store" << endl << "3. display" << endl << "4. search" << endl
                << "5. add" << endl << "6. remove" << endl << "7. edit" << endl << "8. exit" << endl;

        cout << "Enter Option: ";
        cin >> userSelection;

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
        else if(userSelection == "search") {
            string attributeName;
            string attributeValue;
            Song foundSong;
            Song* foundSongPtr = &foundSong;
            int index = 0;
            int* indexPtr = &index;
            cout << "Enter either title, artist, genre, rating, or index: ";
            cin.ignore();
            getline(cin, attributeName);
            cout << attributeName << endl;
            if(attributeName == "index") {
                cout << "Enter the value for the attribute you chose: ";
                cin.ignore();
                getline(cin, attributeValue);
                cout << attributeValue << endl;
                index = stoi(attributeValue);
                dmm.performSearchByIndex(index, foundSongPtr);
            }
            else if(attributeName == "title" || attributeName == "artist" || attributeName == "genre" || attributeName == "rating") {
                cout << "Enter the value for the attribute you chose: ";
                cin.ignore();
                getline(cin, attributeValue);
                cout << attributeValue << endl;
                dmm.performSearch(attributeName, attributeValue, foundSongPtr, indexPtr);
            }
            else {
                cerr << "Invalid attribute" << endl;
            }
            foundSong.displaySong();
        }
        else if(userSelection == "add") {
            string attributes;
            cout << "Provide song title, artist, genre, rating: ";
            cin.ignore();
            getline(cin, attributes);
            cout << attributes << endl;
            dmm.performAddSongFromString(attributes, ',');
            dmm.displayLibrary();
        }
        else if(userSelection == "remove") {
        
        }
        else if(userSelection == "edit") {
        
        }
        else if(userSelection == "exit") {
            return;
        }
        else{
            cerr << "Invalid option" << endl;
        }
    } while(true);
}