//
// Created by dell on 09.05.2022.
//

#ifndef A11_12_914_CLAUDIA_MOISIUC_REPOSITORY_H
#define A11_12_914_CLAUDIA_MOISIUC_REPOSITORY_H

#endif //A11_12_914_CLAUDIA_MOISIUC_REPOSITORY_H

#include "validators.h"
#include <iostream>
#include <vector>
#include <fstream>
class Repository
{
public:
    std::vector<Tutorial> arr;

public:
    ///create a repository
    Repository();
    ///destroy a repository
    void DestroyRepository();

    ///getter for the elements
    virtual std::vector<Tutorial> getAll() const;
    ///getter for the size
    virtual int getSiz() const;
    ///getter for an element
    virtual Tutorial getElemm(int i) const;
    ///add an element to the dynamic vector
    virtual void addTutorial(const Tutorial& newTutorial);
    ///remove an element from the dynamic vector
    virtual void removeTutorial(int poz);
    ///update an element from the dynamic vector
    virtual void updateTutorial(int poz, const Tutorial& e);

};

class Repository_file:public Repository{
protected:
    std::string filename;
public:
    ///create the file repository
    Repository_file();
    ///write the tutorials in a file
    void writeinfile(std::vector<Tutorial> arr);
    ///read the tutorials from a file
    std::vector<Tutorial> readfromfile();
};

class Repository_playlist{
protected:
    std::vector<Tutorial> tutorials;
    int currentIndex;
public:
    Repository_playlist();
    ///destroy a repository
    void DestroyPlaylist();
    ///add an element to the dynamic vector
    void addTutorial(const Tutorial& newTutorial);
    ///remove an element from the dynamic vector
    void removeTutorial();
    ///update an element from the dynamic vector
    void updateTutorial(const Tutorial& e);
    ///getter for an element
    Tutorial getElemm();
    //getter for the size
    int getSiz() const;
    std::vector<Tutorial> getAll() const;
    ///play the tutorial
    void play() const;
    ///go to the next element in the watch list
    void next();
    ///virtual write function
    virtual void writeinfile(std::vector<Tutorial> tutorials){};
    ///virtual open function
    virtual void open(){};
};

//create the html playlist class
class Playlist_file_html:public Repository_playlist{
private:
    std::string filename;
public:
    ///creator of the html playlist repo
    Playlist_file_html();
    ///write the playlist in the html file
    void writeinfile(std::vector<Tutorial> tutorials) override;
    ///open the html file
    void open() override;
};

//create the csv playlist class
class Playlist_file_csv:public Repository_playlist{
private:
    std::string filename;
public:
    ///creator of the csv playlist repo
    Playlist_file_csv();
    ///write the playlist in the csv file
    void writeinfile(std::vector<Tutorial> tutorials) override;
    ///open the csv file
    void open() override;
};