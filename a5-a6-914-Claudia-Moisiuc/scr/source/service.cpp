//
// Created by dell on 20.03.2022.
//

#include "../header/service.h"
#include <iostream>

///create a service
Service::Service(Repository r, Playlist p): repository(r), playlist(p)
{
}

///destroy a service
void Service::DestroyService()
{
    repository.DestroyRepository();
}

/*
///getter for the elements
Tutorial* Service::getAllElem() const
{
    return repository.getAll();
}*/

///getter for the size
int Service::getSize() const
{
    return repository.getSiz();
}

///getter for an element
Tutorial* Service::getElem(int i) const
{
    return repository.getElemm(i);
}

///add an element to the dynamic vector
void Service::addTutorial(std::string title, std::string presenter, Duration duration, std::intmax_t likes,
                          std::string link){
    Tutorial newTutorial(title, presenter, duration, likes, link);
    repository.addTutorial(newTutorial);
}

///remove an element from the dynamic vector
void Service::removeTutorial(std::string title, std::string presenter){
    Tutorial* v;
    for (int i = 0; i < repository.getSiz(); i++) {
        v = repository.getElemm(i);
        if(title == v->getTitle() && presenter ==v->getPresenter())
            repository.removeTutorial(i);
    }
    for (int i = 0; i < playlist.leng(); i++) {
        v = playlist.getElemm();
        if(title == v->getTitle() && presenter ==v->getPresenter())
            playlist.remove();
        playlist.next();
    }
}

///update an element from the dynamic vector
void Service::updateTutorial(std::string title, std::string presenter, Duration duration, std::intmax_t likes,
                             std::string link)
{
    Tutorial newTutorial(title, presenter, duration, likes, link);
    Tutorial* v;
    for (int i = 0; i < playlist.leng(); i++) {
        v = playlist.getElemm();
        if(title == v->getTitle() && presenter == v->getPresenter())
            playlist.update(i, newTutorial);
        playlist.next();
    }
    for (int i = 0; i < repository.getSiz(); i++) {
        v = repository.getElemm(i);
        if(title == v->getTitle() && presenter == v->getPresenter())
            repository.updateTutorial(i, newTutorial);
    }
}

///find if a given element is in the dynamic vector
int Service::find(std::string title, std::string presenter)
{
    for(int i = 0; i < repository.getSiz(); i++)
        if(title == repository.getElemm(i)->getTitle() && presenter == repository.getElemm(i)->getPresenter())
            return i;
    return -1;

}

///search if 2 elements have the same presenter
int Service::samePresenter(std::string presenter, int i)
{
    if (repository.getElemm(i)->getPresenter() == presenter)
        return 1;
    return 0;
}

///10 star-up data
void Service::startdata()
{
    Duration d;
    d.set_minutes(12);
    d.set_seconds(10);
    addTutorial("computer networks", "Anca Petcu", d, 120, "https://www.youtube.com/watch?v=3QhU9jd03a0");
    addTutorial("computer graphics", "Tomislav Jorrit", d, 12, "https://www.youtube.com/watch?v=TEAtmCYYKZA");
    addTutorial("computer organization", "Gedeon Monika", d, 1234, "https://www.youtube.com/watch?v=p3q5zWCw8J4");
    addTutorial("input data in c", "Hudson Zander", d, 445, "https://www.youtube.com/watch?v=oaGdiYGMJfA");
    addTutorial("input data in c++", "Hudson Zander", d, 5543, "https://www.youtube.com/watch?v=qhnARpYSqAA");
    addTutorial("input data in python", "Titus Rhonda", d, 34, "https://www.youtube.com/watch?v=4OX49nLNPEE");
    addTutorial("input data in java", "Branson Kylan", d, 5654, "https://www.youtube.com/watch?v=5DdacOkrTgo");
    addTutorial("separators in c", "Branson Kylan", d, 3454, "https://www.youtube.com/watch?v=auu1DCAZX7c");
    addTutorial("separators in c++", "Arline Corinna", d, 345, "https://www.youtube.com/watch?v=1EAL_RRCKhY");
    addTutorial("AI for beginners", "Arline Corinna", d, 67654, "https://www.youtube.com/watch?v=ad79nYk2keg");
}

///find if a given element is in the dynamic vector
int Service::findUser(std::string title, std::string presenter)
{
    for(int i = 0; i < playlist.leng(); i++)
    {   if(title == playlist.getElemm()->getTitle() && presenter ==playlist.getElemm()->getPresenter())
            return i;
        playlist.next();}
    return -1;

}

///search if 2 elements have the same presenter
int Service::samePresUser(std::string presenter)
{
    if (playlist.getElemm()->getPresenter() == presenter)
        return 1;
    return 0;
}

///add a tutorial in the watchlist
void Service::addUser(std::string title, std::string presenter, Duration duration, std::intmax_t likes,
             std::string link)
{
    if (findUser(title, presenter) == -1)
    {Tutorial newTutorial(title, presenter, duration, likes, link);
    playlist.addTutorial(newTutorial);}
}

///play a video in the watchlist
void Service::playUser()
{
    playlist.play();
}

///go to the next user in the watchlist
void Service::nextUser()
{
    playlist.next();
}

///get the current element in the watchlist
Tutorial* Service::getElemm()
{
    return playlist.getElemm();
}

///get the length of the watchlist
int Service::getlen()
{
    return playlist.leng();
}

///like a video in the watch list and in the dynamic vector
void Service::like()
{
    playlist.like();
    int i = find(playlist.getElemm()->getTitle(), playlist.getElemm()->getPresenter());
    repository.getElemm(i)->setLikes(repository.getElemm(i)->getLikes()+1);
}

///remove a tutorial from the watchlist
void Service::removeUser()
{
    playlist.remove();
}
//