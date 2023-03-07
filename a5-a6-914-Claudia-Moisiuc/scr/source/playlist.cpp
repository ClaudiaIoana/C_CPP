//
// Created by dell on 20.03.2022.
//

#include "../header/playlist.h"

Playlist::Playlist() : currentIndex(0)
{ }

///add a tutorial to the play list
void Playlist::addTutorial(const Tutorial& tutorial)
{
    tutorials + tutorial;
}

///play the tutorial
void Playlist::play() const
{
    Tutorial* allTutorials = tutorials.getAllElems();
    allTutorials[currentIndex].play();
}

///go to the next element in the watch list
void Playlist::next()
{
    currentIndex++;
    currentIndex %= tutorials.getSize();
}

///get the current element in the watchlist
Tutorial* Playlist::getElemm()
{
    return tutorials.getElem(currentIndex);
}

///get the length of the watch list
int Playlist::leng()
{
    return tutorials.getSize();
}

///like a video
void Playlist::like()
{
    tutorials.getElem(currentIndex)->setLikes(tutorials.getElem(currentIndex)->getLikes()+1);
}

///remove a video from the watch list
void Playlist::remove()
{
    tutorials.remove(currentIndex);
}

///update a video in the watch list
void Playlist::update(int poz, const Tutorial& e)
{
    tutorials.update(poz, e);
}
//