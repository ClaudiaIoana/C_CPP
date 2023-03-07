//
// Created by dell on 19.03.2022.
//

#include "../header/tutorials.h"

///create a structure of type tutorial
Tutorial::Tutorial()
: title(""), presenter(""), duration(), likes(0), link("")
{
}

///create a structure of type tutorial with title, presenter, duration, likes and link
Tutorial::Tutorial(std::string _title, std::string _presenter, Duration _duration, std::intmax_t _likes, std::string _link)
: title(_title), presenter(_presenter), duration(_duration), likes(_likes), link(_link)
{
}

///create a structure of type tutorial that is a copy
Tutorial::Tutorial(const Tutorial& tut)
:title(tut.title), presenter(tut.presenter), duration(tut.duration), likes(tut.likes), link(tut.link)
{
}

///getter for the title
std::string Tutorial::getTitle() const
{
    return title;
}

///getter for the presenter
std::string Tutorial::getPresenter() const
{
    return presenter;
}

///getter for the duration
Duration Tutorial::getDuration() const
{
    return duration;
}

///getter for the likes
std::intmax_t Tutorial::getLikes() const
{
    return likes;
}

///getter for the link
std::string Tutorial::getLink() const
{
    return link;
}

///setter for the title
void Tutorial::setTitle(std::string _title)
{
    title = _title;
}

///setter for the presenter
void Tutorial::setPresenter(std::string _presenter)
{
    presenter = _presenter;
}

///setter for the duration
void Tutorial::setDuration(Duration _duration)
{
    duration = _duration;
}

///setter for the likes
void Tutorial::setLikes(std::intmax_t _likes)
{
    likes = _likes;
}

///setter for the link
void Tutorial::setLink(std::string _link)
{
    link = _link;
}

void Tutorial::play() const
{
    ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}
//