#include <iostream>
#include <fstream>
#include <array>
#include "Song.h"
#include "menu.h"

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

/*void testAddRemoveSongs() {
    Song songs[] = {Song("creepin'", "the weeknd", "R&B", 5), Song("humble", "kendrick lamar", "R&B", 5), Song("god's plan", "drake", "R&B", 4),
                        Song("as you are", "harry styles", "pop", 4)};
    SongLibrary playlist;
    Song foundSong;
    Song* foundSongPtr = &foundSong;
    int index = 0;
    int* indexPtr = &index;

    cout << songs[3].getStringAttributeValue("title") << ", " << songs[3].getStringAttributeValue("artist") << ", "  << songs[3].getStringAttributeValue("genre") 
        << ", " << songs[3].getStringAttributeValue("rating") << endl;
    
    playlist.performLoad("./SongLibrary.csv");

    playlist.performAddSong(songs[0]);
    playlist.performAddSong(songs[1]);
    playlist.performAddSong(songs[2]);
    playlist.performAddSong(songs[3]);

    playlist.performSearch("artist", "the weeknd", foundSongPtr, indexPtr);
    foundSongPtr->displaySong();
    playlist.performSearch("title", "take my breath", foundSongPtr, indexPtr);
    foundSong.displaySong();
    playlist.performEditSong(index, "rating", "5");
    playlist.displayLibrary("Updated rating");
    playlist.performSearch("rating", "4", foundSongPtr, indexPtr);
    foundSong.displaySong();
    //playlist.performSearch("label", "sony records", foundSongPtr, indexPtr);
    //foundSongPtr->displaySong();
    //foundSong.displaySong();

    playlist.performSave("playlist_1.csv");

    playlist.displayLibrary("unsorted");

    playlist.performSort("title");
    playlist.displayLibrary("sorted by title");
     playlist.performSort("rating");
    playlist.displayLibrary("sorted by rating");

    playlist.performRemoveSong(1);
    playlist.performRemoveSong(2);
    playlist.performRemoveSong(0);
    playlist.performRemoveSong(0);
    playlist.performRemoveSong(3); // negative test case
    playlist.displayLibrary("post remove");
    foundSongPtr->displaySong();
    playlist.performSave("playlist_2.csv");
    playlist.removeAllSongs();
    playlist.performLoad("playlist_1.csv");
    playlist.displayLibrary("playlist 1");
} */

int main() {
    mainMenu();
    cout << "Goodbye!" << endl;
    
    return 0;
}