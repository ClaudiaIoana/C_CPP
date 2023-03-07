//
// Created by dell on 20.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_SERVICE_H
#define A5_6_914_CLAUDIA_MOISIUC1_SERVICE_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_SERVICE_H
#include "playlist.h"
#include <cstring>

class Service
{
private:
    Repository repository;
    Playlist playlist;

public:
    ///create a service
    Service(Repository r, Playlist p);
    ///destroy a service
    void DestroyService();
    ///getter for the elements
    Tutorial* getAllElem() const;
    ///getter for an element
    Tutorial* getElem(int i) const;
    ///getter for the size
    int getSize() const;
    ///10 star-up data
    void startdata();
    ///remove an element from the dynamic vector
    void removeTutorial(std::string title, std::string presenter);
    ///update an element from the dynamic vector
    void updateTutorial(std::string title, std::string presenter, Duration duration, std::intmax_t likes,
                                 std::string link);
    ///find if a given element is in the dynamic vector
    int find(std::string title, std::string presenter);
    ///search if 2 elements have the same presenter
    int samePresenter(std::string presenter, int i);
    ///add a tutorial in the dynamic vector
    void addTutorial(std::string title, std::string presenter, Duration duration, std::intmax_t likes, std::string link);
    ///add a tutorial in the watchlist
    void addUser(std::string title, std::string presenter, Duration duration, std::intmax_t likes,
                 std::string link);
    ///play a video in the watchlist
    void playUser();
    ///get the current element in the watchlist
    Tutorial* getElemm();
    ///go to the next user in the watchlist
    void nextUser();
    ///get the length of the watchlist
    int getlen();
    ///like a video in the watch list and in the dynamic vector
    void like();
    ///remove a tutorial from the watchlist
    void removeUser();
    ///find if a given element is in the watchlist
    int findUser(std::string title, std::string presenter);
    ///search if 2 elements have the same presenter
    int samePresUser(std::string presenter);
};
//