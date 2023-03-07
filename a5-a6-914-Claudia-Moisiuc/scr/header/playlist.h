//
// Created by dell on 20.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_PLAYLIST_H
#define A5_6_914_CLAUDIA_MOISIUC1_PLAYLIST_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_PLAYLIST_H
#include "repository.h"

class Playlist
{
private:
    DynamicVector<Tutorial> tutorials;
    int currentIndex;

public:
    ///creae a playlist
    Playlist();
    ///add a tutorial to the play list
    void addTutorial(const Tutorial& tutorial);
    ///play the tutorial
    void play() const;
    ///go to the next element in the watch list
    void next();
    ///get the current element in the watchlist
    Tutorial* getElemm();
    ///get the length of the watch list
    int leng();
    ///like a video
    void like();
    ///remove a video from the watch list
    void remove();
    ///update a video in the watch list
    void update(int poz, const Tutorial& e);
};
//