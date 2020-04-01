//
// Created by zahme on 3/16/2020.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
using namespace std;

class Song{

private:
    string title;
    string artist;
    int size;

public:
    //constructors
    Song();

    Song(string artist, string title, int size);

    //returns song size
    int getSongSize() const;

    //returns song title
    string getSongTitle() const;

    //returns song artist
    string getSongArtist() const;

    //sets song size
    void setSongSize(int size);

    //sets song title
    void setSongTitle(string title);

    //sets song artist
    void setSongArtist(string artist);

    //checks if Songs are the same
    bool operator ==(Song const &s);

    //checks if Songs are before or after each other
    bool operator >(Song const &s);

    bool operator <(Song const &s);

    //Deconstructor
    ~Song();
};
#endif //UTPOD_SONG_H
