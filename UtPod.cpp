//
// Created by zahme on 3/16/2020.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UtPod.h"
#include "Song.h"
using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = nullptr;

}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = nullptr;

}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &s){
    if(getRemainingMemory() <= s.getSongSize()){
        return -1;
    }

    SongNode *temp = new SongNode;
    temp -> next = nullptr;
    temp -> s = s;

    if(songs == nullptr){
        songs = temp;
        return 0;
    }

    SongNode *ptr;
    ptr = songs;
    while(ptr -> next != nullptr){
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    return 0;

}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms -

   output parms -
*/

int UtPod::removeSong(Song const &s){
    SongNode *ptr;
    SongNode *prev;
    ptr = songs;
    prev = nullptr;

    if(ptr -> s == s){
        songs = ptr -> next;
        return 0;
    }

    while(ptr != nullptr){
        if(ptr -> s == s){
            prev -> next = ptr -> next;
            return 0;
        }
        prev = ptr;
        ptr = ptr -> next;
    }
    return -1;

}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::shuffle(){
    SongNode *ptr1;
    SongNode *ptr2;
    ptr1 = songs;
    ptr2 = songs;

    if(ptr1 -> next == nullptr){
        return;
    }

    int numSongs = 0;
    while(ptr1 != nullptr){
        numSongs ++;
        ptr1 = ptr1 -> next;
    }

    unsigned int currentTime = (unsigned) time(nullptr);
    srand(currentTime);
    for(int i = 0; i < (numSongs * 2); i++){
        long randomNum = (rand() % numSongs);
        ptr1 = songs;
        ptr2 = songs;
        while(randomNum > 0){
            ptr2 = ptr2 -> next;
            randomNum --;
        }
        Song temp = ptr1 -> s;
        ptr1 -> s = ptr2 -> s;
        ptr2 -> s = temp;
    }
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList(){
    SongNode *ptr;
    ptr = songs;
    while(ptr != nullptr){
        cout << ptr -> s.getSongTitle() << " " << "by ";
        cout << ptr -> s.getSongArtist() << " ";
        cout << ptr -> s.getSongSize() << endl;
        ptr = ptr -> next;
    }
    cout << endl;

}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList(){
    SongNode *standingPtr;
    SongNode *movingPtr;
    standingPtr = songs;
    movingPtr = nullptr;

    if(standingPtr -> next == nullptr){
        return;
    }

    while(standingPtr -> next != nullptr){
        movingPtr = standingPtr -> next;
        while(movingPtr != nullptr){
            if(standingPtr -> s > movingPtr -> s){
                Song temp = standingPtr -> s;
                standingPtr -> s = movingPtr -> s;
                movingPtr -> s = temp;
            }
            movingPtr = movingPtr -> next;
        }
        standingPtr = standingPtr -> next;
    }

}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    SongNode *ptr;
    ptr = songs;
    while(ptr != nullptr){
        delete ptr;
        ptr = ptr -> next;
    }
    songs = nullptr;
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/

int UtPod::getRemainingMemory(){
    SongNode *ptr;
    ptr = songs;
    int usedSize = 0;
    while(ptr != nullptr){
        usedSize = usedSize + ptr -> s.getSongSize();
        ptr = ptr -> next;
    }
    return memSize - usedSize;

}


UtPod::~UtPod(){
    clearMemory();
    cout << "UTPod destroyed" << endl;
}
