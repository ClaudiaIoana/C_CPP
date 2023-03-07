//
// Created by dell on 25.04.2022.
//

#ifndef A8_9_914_CLAUDIA_MOISIUC_SERVICE_H
#define A8_9_914_CLAUDIA_MOISIUC_SERVICE_H

#endif //A8_9_914_CLAUDIA_MOISIUC_SERVICE_H

#include "repository.h"
#include <cstring>

class Service
{
private:
    Repository repository;
    Repository_playlist *playlist;
    Repository_file file;

public:
    ///create a service
    Service(Repository *r, Repository_playlist *p);
    ///destroy a service
    void DestroyService();
    ///getter for the elements
    std::vector<Tutorial> getAllElem() const;
    ///getter for an element
    Tutorial getElem(int i) const;
    ///getter for the size
    int getSize() const;
    ///10 star-up data
    void startdata();
    ///remove an element from the dynamic vector
    void removeTutorial(const std::string& title, const std::string& presenter);
    ///update an element from the dynamic vector
    void updateTutorial(const std::string& title, const std::string& presenter, const Duration& duration, std::intmax_t likes,
                        std::string link);
    ///find if a given element is in the dynamic vector
    int find(const std::string& title, const std::string& presenter);
    ///search if 2 elements have the same presenter
    int samePresenter(const std::string& presenter, int i);
    ///add a tutorial in the dynamic vector
    void addTutorial(std::string title, std::string presenter, const Duration& duration, std::intmax_t likes, std::string link);
    ///add a tutorial in the watchlist
    void addUser(const std::string& title, const std::string& presenter, const Duration& duration, std::intmax_t likes,
                 std::string link);
    ///play a video in the watchlist
    void playUser();
    ///get the current element in the watchlist
    Tutorial getElemm();
    ///go to the next user in the watchlist
    void nextUser();
    ///get the length of the watchlist
    int getlen();
    ///like a video in the watch list and in the dynamic vector
    void like();
    ///remove a tutorial from the watchlist
    void removeUser();
    ///find if a given element is in the watchlist
    int findUser(const std::string& title, const std::string& presenter);
    ///search if 2 elements have the same presenter
    int samePresUser(const std::string& presenter);
    void open();
    std::vector<Tutorial> filter(const std::string& presenter);
    std::vector<Tutorial> filterUser(const std::string& presenter);
};
