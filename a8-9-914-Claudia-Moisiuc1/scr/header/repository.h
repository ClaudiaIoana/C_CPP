//
// Created by dell on 21.04.2022.
//

#ifndef A8_9_914_CLAUDIA_MOISIUC_REPOSITORY_H
#define A8_9_914_CLAUDIA_MOISIUC_REPOSITORY_H

#endif //A8_9_914_CLAUDIA_MOISIUC_REPOSITORY_H
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
    std::string filename = "E:\\2\\a8-9-914-Claudia-Moisiuc1\\scr\\source\\data_tutorials.txt";
public:
    Repository_file();
    void writeinfile(std::vector<Tutorial> arr);
    std::vector<Tutorial> readfromfile();
};

class Repository_playlist{
protected:
    std::vector<Tutorial> tutorials;
    int currentIndex;
public:
    Repository_playlist();
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
    virtual void writeinfile(std::vector<Tutorial> tutorials){};
    virtual void open(){};
};

class Playlist_file_html:public Repository_playlist{
private:
    std::string filename;
public:
    Playlist_file_html();
    void writeinfile(std::vector<Tutorial> tutorials) override;
    void open() override;
};

class Playlist_file_csv:public Repository_playlist{
private:
    std::string filename;
public:
    Playlist_file_csv();
    void writeinfile(std::vector<Tutorial> tutorials) override;
    void open() override;
};