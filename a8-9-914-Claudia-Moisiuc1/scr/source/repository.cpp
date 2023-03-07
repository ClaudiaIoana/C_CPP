//
// Created by dell on 21.04.2022.
//

#include "../header/repository.h"

///create a repository
Repository::Repository()
{
}


Repository_file::Repository_file(){
    this->filename = "E:\\2\\a8-9-914-Claudia-Moisiuc1\\scr\\source\\data_tutorials.txt";
}

Playlist_file_html::Playlist_file_html(){
    this->filename = "E:\\2\\a8-9-914-Claudia-Moisiuc1\\scr\\source\\data_tutorials.html";
}

Playlist_file_csv::Playlist_file_csv(){
    this->filename = "E:\\2\\a8-9-914-Claudia-Moisiuc1\\scr\\source\\data_tutorials.csv";
}

void Repository::DestroyRepository() {
    arr.clear();
}

///getter for the elements
std::vector<Tutorial> Repository::getAll() const
{
    std::vector<Tutorial> copy;
    for (const auto & i : arr)
        copy.push_back(i);
    return copy;
}

std::vector<Tutorial> Repository_playlist::getAll() const {
    std::vector<Tutorial> copy;
    for (const auto & i : tutorials)
        copy.push_back(i);
    return copy;
}

///getter for an element
Tutorial Repository::getElemm(int i) const
{
    return arr.at(i);
}

///getter for the size
int Repository::getSiz() const
{
    return arr.size();
}

///add an element to the dynamic vector
void Repository::addTutorial(const Tutorial& newTutorial)
{
    int ok = 1;
    try {
        TutorialValidator::validate(newTutorial);
    }
    catch (ValidationException& ex)
    {
        std::cout<< ex.getMessage()<<std::endl;
        ok = 0;
    }
    if(ok == 1)
    {arr.push_back(newTutorial);
    }
}

///remove an element from the dynamic vector
void Repository::removeTutorial(int poz)
{
    std::vector<Tutorial> copy;
    for (int i = 0; i < arr.size(); i++)
        if(i != poz)
            copy.push_back(arr[i]);
    arr.swap(copy);
    copy.clear();
}

///update an element from the dynamic vector
void Repository::updateTutorial(int poz, const Tutorial& e)
{
    int ok = 1;
    try {
        TutorialValidator::validate(e);
    }
    catch (ValidationException& ex)
    {
        std::cout<< ex.getMessage()<<std::endl;
        ok = 0;
    }
    if(ok == 1){
        std::vector<Tutorial> copy;
        for (int i = 0; i < arr.size(); i++)
            if(i != poz)
                copy.push_back(arr[i]);
            else
                copy.push_back(e);
        arr.swap(copy);
        copy.clear();
    }
}

void Repository_file::writeinfile(std::vector<Tutorial> arr) {
    std::ofstream file(this->filename);

    int index = 0;
    if(!file.is_open())
        return;

    for(const auto& t : arr) {
        if (index != 0)
            file << "\n";
        file << t;
        index++;
    }

    file.close();
}

std::vector<Tutorial> Repository_file::readfromfile() {
    std::ifstream file(this->filename);

    std::vector<Tutorial> arr;
    if(!file.is_open())
        return arr;

    Tutorial t;
    while(file >> t)
        arr.push_back(t);
    std::cout<<arr[0].getTitle();
    file.close();
    return arr;
}

Repository_playlist::Repository_playlist() : currentIndex(0)
{
}

///add a tutorial to the play list
void Repository_playlist::addTutorial(const Tutorial& tutorial)
{
    tutorials.push_back(tutorial);
}

///play the tutorial
void Repository_playlist::play() const
{
    auto allTutorials = tutorials.begin();
    allTutorials[currentIndex].play();
}

///go to the next element in the watch list
void Repository_playlist::next()
{
    currentIndex++;
    currentIndex %= tutorials.size();
}

///get the current element in the watchlist
Tutorial Repository_playlist::getElemm()
{
    return tutorials.at(currentIndex);
}

int Repository_playlist::getSiz() const {
    return tutorials.size();
}

void Repository_playlist::removeTutorial() {
    std::vector<Tutorial> copy;
    for (int i = 0; i < tutorials.size(); i++)
        if(i != currentIndex)
            copy.push_back(tutorials[i]);
    tutorials.swap(copy);
    copy.clear();
}

void Repository_playlist::updateTutorial(const Tutorial &e) {
    std::vector<Tutorial> copy;
    for (int i = 0; i < tutorials.size(); i++)
        if(i != currentIndex)
            copy.push_back(tutorials[i]);
        else
            copy.push_back(e);
    tutorials.swap(copy);
    copy.clear();
}

void Playlist_file_csv::writeinfile(std::vector<Tutorial> tutorial) {
    std::ofstream file(this->filename);
    int index = 0;
    if(!file.is_open())
        return;

    for(const auto& t : tutorial) {
        if (index != 0)
            file << "\n";
        file << t;
        index++;
    }
    file.close();
}

void Playlist_file_html::writeinfile(std::vector<Tutorial> tutorials) {
    std::ofstream file(this->filename);

    if(!file.is_open())
        return;

    file<<"<!DOCTYPE html>\n<html>\n<head>\n    <title>Playlist</title>\n</head>";
    file<<"<body>\n<table border=\"1\">\n    <tr>\n        <td>Title</td>\n";
    file<<"        <td>Presenter</td>\n        <td>Duration</td>\n        <td>Likes</td>\n        <td>Youtube link</td>\n    </tr>\n";

    for(const auto& t : tutorials) {
        file<<"    <tr>\n";
        file <<"        <td>"<< t.getTitle()<<"</td>";
        file <<"        <td>"<< t.getPresenter()<<"</td>";
        file <<"        <td>"<< t.getDuration().get_minutes()<<":"<<t.getDuration().get_seconds()<<"</td>";
        file <<"        <td>"<< t.getLikes()<<"</td>";
        file <<"        <td><a href="<< t.getLink()<<">Link</a></td>";
        file<<"</tr>";
    }
    file<<"</table>\n</body>\n</html>";
    file.close();
}

void Playlist_file_csv::open(){
    system("notepad.exe data_tutorials3.csv");
}

void Playlist_file_html::open() {
    ShellExecuteA(nullptr, nullptr, "chrome.exe", "http://localhost:63342/a8_9_914_Claudia_Moisiuc/scr/source/data_tutorials.html?_ijt=vetan4jliccjomte94h0b0uuus&_ij_reload=RELOAD_ON_SAVE", nullptr, SW_SHOWMAXIMIZED);
}