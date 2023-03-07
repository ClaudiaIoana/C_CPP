//
// Created by dell on 25.04.2022.
//

#include "../header/service.h"
#include <iostream>
#include <algorithm>
#include <utility>

Service::Service(Repository *r, Repository_playlist *p): repository(* r), playlist( p)
{
}

void Service::DestroyService()
{
    repository.DestroyRepository();
}

std::vector<Tutorial> Service::getAllElem() const
{
    return repository.getAll();
}

int Service::getSize() const
{
    return repository.getSiz();
}

Tutorial Service::getElem(int i) const
{
    return repository.getElemm(i);
}

void Service::addTutorial(std::string title, std::string presenter, const Duration& duration, std::intmax_t likes,
                          std::string link){
    Tutorial newTutorial(std::move(title), std::move(presenter), duration, likes, std::move(link));
    repository.addTutorial(newTutorial);
    file.writeinfile(repository.getAll());
}

void Service::removeTutorial(const std::string& title, const std::string& presenter){
    Tutorial v;
    for (int i = 0; i < repository.getSiz(); i++) {
        v = repository.getElemm(i);
        if(title == v.getTitle() && presenter ==v.getPresenter())
            repository.removeTutorial(i);
    }
    for (int i = 0; i < playlist->getSiz(); i++) {
        v = playlist->getElemm();
        if(title == v.getTitle() && presenter ==v.getPresenter())
            playlist->removeTutorial();
        playlist->next();
    }
    file.writeinfile(repository.getAll());
}

void Service::updateTutorial(const std::string& title, const std::string& presenter, const Duration& duration, std::intmax_t likes,
                             std::string link)
{
    Tutorial newTutorial(title, presenter, duration, likes, std::move(link));
    Tutorial v;
    for (int i = 0; i < playlist->getSiz(); i++) {
        v = playlist->getElemm();
        if(title == v.getTitle() && presenter == v.getPresenter())
            playlist->updateTutorial(newTutorial);
        playlist->next();
    }
    for (int i = 0; i < repository.getSiz(); i++) {
        v = repository.getElemm(i);
        if(title == v.getTitle() && presenter == v.getPresenter())
            repository.updateTutorial(i, newTutorial);
    }
    file.writeinfile(repository.getAll());
}

int Service::find(const std::string& title, const std::string& presenter)
{
    for(int i = 0; i < repository.getSiz(); i++)
        if(title == repository.getElemm(i).getTitle() && presenter == repository.getElemm(i).getPresenter())
            return i;
    return -1;

}

int Service::samePresenter(const std::string& presenter, int i)
{
    if (repository.getElemm(i).getPresenter() == presenter)
        return 1;
    return 0;
}

void Service::startdata()
{
    repository.arr = file.readfromfile();
}

int Service::findUser(const std::string& title, const std::string& presenter)
{
    for(int i = 0; i < playlist->getSiz(); i++)
    {   if(title == playlist->getElemm().getTitle() && presenter ==playlist->getElemm().getPresenter())
            return i;
        playlist->next();}
    return -1;

}

int Service::samePresUser(const std::string& presenter)
{
    if (playlist->getElemm().getPresenter() == presenter)
        return 1;
    return 0;
}

void Service::addUser(const std::string& title, const std::string& presenter, const Duration& duration, std::intmax_t likes,
                      std::string link)
{
    if (findUser(title, presenter) == -1)
    {Tutorial newTutorial(title, presenter, duration, likes, std::move(link));
        playlist->addTutorial(newTutorial);}
    playlist->writeinfile(playlist->getAll());
}

///play a video in the watchlist
void Service::playUser()
{
    playlist->play();
}


///go to the next user in the watchlist
void Service::nextUser()
{
    playlist->next();
}


///get the current element in the watchlist
Tutorial Service::getElemm()
{
    return playlist->getElemm();
}

///get the length of the watchlist
int Service::getlen()
{
    return playlist->getSiz();
}

///like a video in the watch list and in the dynamic vector
void Service::like()
{
    int i = find(playlist->getElemm().getTitle(), playlist->getElemm().getPresenter());
    repository.getElemm(i).setLikes(repository.getElemm(i).getLikes()+1);
}

///remove a tutorial from the watchlist
void Service::removeUser()
{
    playlist->removeTutorial();
    playlist->writeinfile(playlist->getAll());
}

std::vector<Tutorial> Service::filter(const std::string& presenter)
{
    if(presenter.empty())
        return repository.getAll();

    std::vector<Tutorial> copy{repository.getAll().size()};
    std::vector<Tutorial> copies = repository.getAll();

    auto iter = std::copy_if(copies.begin(), copies.end(), copy.begin(), [presenter](const Tutorial& turorial){
        return turorial.getPresenter() == presenter;
    });
    std::cout<<"ok";
    copy.resize(std::distance(copy.begin(), iter));

    return copy;
}

std::vector<Tutorial> Service::filterUser(const std::string& presenter)
{
    std::vector<Tutorial> copy;

    for (int i = 0; i < playlist->getSiz(); i++)
    {copy.push_back(playlist->getElemm());
        playlist->next();}

    if(presenter.empty())
        return copy;

    std::vector<Tutorial> copies {copy.size()};

    auto iter = std::copy_if(copy.begin(), copy.end(), copies.begin(), [presenter](const Tutorial& turorial){
        return turorial.getPresenter() == presenter;
    });
    copies.resize(std::distance(copies.begin(), iter));

    return copies;
}

void Service::open() {
    playlist->open();
}
