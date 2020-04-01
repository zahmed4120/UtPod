/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;

    Song s2("The Weeknd", "After Hours", 31);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    Song s3("Post Malone", "Circles", 15);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Dua Lipa", "Don't Start Now", 15);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Juice Wrld", "Lucid Dreams", 24);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Post Malone", "Sunflower", 12);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Post Malone", "Sunflower", 13);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("Harry Styles", "Adore You", 14);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("Drake", "Hotline Bling", 23);
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    Song s10("Arizona Zervas", "Roxanne", 18);
    result = t.addSong(s10);
    cout << "add result = " << result << endl;

    Song s11("Jonas Brothers", "Sucker", 11);
    result = t.addSong(s11);
    cout << "add result = " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << endl << endl;

    //show then sort songs then shuffle
    cout << "Original Song List:" << endl;
    t.showSongList();
    t.sortSongList();
    cout << "Sorted Original Song List:" << endl;
    t.showSongList();
    t.shuffle();
    cout << "Shuffled Original Song List:" << endl;
    t.showSongList();
    t.shuffle();
    cout << "Shuffled Original Song List again: " << endl;
    t.showSongList();

    //removing songs
    result = t.removeSong(s10);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s7);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.addSong(s7);
    cout << "add result = " << result << endl << endl;

    cout << "Updated song list after removing a few songs: " << endl;
    t.showSongList();
    t.sortSongList();
    cout << "Sorted updated song list: " << endl;
    t.showSongList();
    t.shuffle();
    cout << "Shuffled updated song list: " << endl;
    t.showSongList();

    cout << "memory = " << t.getRemainingMemory() << endl << endl;

    //invalid songs
    cout << "Testing Song constructor with invalid songs: " << endl;
    Song s12("", "Yesterday", 10);
    Song s13("ABBA", "", 12);
    Song s14("Michael Jackson", "Beat It", -1);
    cout << endl;

    //too large to add
    cout << "Trying to add too large song: " << endl;
    Song s15("Michael Jackson", "Bad", 513);
    result = t.addSong(s15);
    cout << "add result = " << result << endl << endl;

    //adding same song again and check if both songs next to each other
    cout << "Adding duplicate song and checking if after sort they are next to each other: " << endl;
    Song s16("Jonas Brothers", "Sucker", 11);
    result = t.addSong(s16);
    cout << "add result = " << result << endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s16);
    cout << "delete result = " << result << endl << endl;

    //trying to delete unadded song
    cout << "Attempting to delete unadded song: " << endl;
    Song s17("Travis Scott", "Sicko Mode", 15);
    result = t.removeSong(s17);
    cout << "delete result = " << result << endl;
    result = t.addSong(s17);
    cout << "add result = " << result << endl << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s6);
    cout << "delete result = " << result << endl << endl;

    //trying to delete already deleted song
    cout << "Attempting to deleted already deleted song: " << endl;
    result = t.removeSong(s6);
    cout << "delete result = " << result << endl << endl;

    result = t.removeSong(s17);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s7);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s8);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s9);
    cout << "delete result = " << result << endl << endl;

    //sort and shuffle only one song
    cout << "Updated song list with only one song:" << endl;
    t.showSongList();
    t.sortSongList();
    t.shuffle();
    cout << "One song after being sorted and shuffled: " << endl;
    t.showSongList();

    //UTPod with small size
    cout << "Creating UTPod with limited size that can only add two songs: " << endl;
    UtPod r(50);

    //only can add s2 and s3
    result = r.addSong(s2);
    cout << "add result = " << result << endl;
    result = r.addSong(s3);
    cout << "add result = " << result << endl;
    result = r.addSong(s4);
    cout << "add result = " << result << endl << endl;

    //only s2 and s3 should show
    r.showSongList();
    cout << "memory = " << r.getRemainingMemory() << endl;

}

