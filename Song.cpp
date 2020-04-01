//
// Created by zahme on 3/16/2020.
//

#include "Song.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

Song::Song(){
    this -> artist = "";
    this -> title = "";
    this -> size = 0;
}

Song::Song(string artistName, string titleSong, int sizeSong){
    string empty = "";
    if(titleSong == empty){
        cout << "Not a valid title" << endl;
        return;
    }
    else if(artistName == empty){
        cout << "Not a valid artist" << endl;
        return;
    }
    else if(sizeSong <= 0){
        cout << "Not a valid size" << endl;
        return;
    }
    else{
        this -> title = titleSong;
        this -> artist = artistName;
        this -> size = sizeSong;
    }

}

int Song::getSongSize() const {
    return size;
}

string Song::getSongTitle() const{
    return title;
}

string Song::getSongArtist() const{
    return artist;
}

void Song::setSongSize(int sizeSong){
    this -> size = sizeSong;
}

void Song::setSongTitle(string titleSong){
    this -> title = titleSong;
}

void Song::setSongArtist(string artistName){
    this -> artist = artistName;
}

bool Song::operator ==(Song const &s){
    return title == s.title && artist == s.artist && size == s.size;
}

bool Song::operator >(Song const &s){
    if(artist < s.artist){
        return false;
    }
    else{
        if(artist == s.artist){
            if(title < s.title){
                return false;
            }
            else{
                if(title == s.title){
                    if(size < s.size){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
                else{
                    return true;
                }
            }
        }
        return true;
    }
}

bool Song::operator <(Song const &s){
    if(artist > s.artist){
        return true;
    }
    else{
        if(artist == s.artist){
            if(title > s.title){
                return true;
            }
            else{
                if(title == s.title){
                    if(size > s.size){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
}

Song::~Song(){
    return;
}