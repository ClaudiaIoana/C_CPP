//
// Created by dell on 09.05.2022.
//

#ifndef A11_12_914_CLAUDIA_MOISIUC_TUTORIAL_H
#define A11_12_914_CLAUDIA_MOISIUC_TUTORIAL_H

#endif //A11_12_914_CLAUDIA_MOISIUC_TUTORIAL_H

#include <string>
#include <Windows.h>
#include "duration.h"

class Tutorial{
private:
    std::string title;
    std::string presenter;
    Duration duration;
    std::intmax_t likes;
    std::string link;

public:
    ///create a structure of type tutorial
    Tutorial();

    ///create a structure of type tutorial with title, presenter, duration, likes and link
    Tutorial(std::string, std::string, Duration, std::intmax_t, std::string);

    ///create a structure of type tutorial that is a copy
    Tutorial(const Tutorial& tut);

    ///getter for the title
    std::string getTitle() const;
    ///getter for the presenter
    std::string getPresenter() const;
    ///getter for the duration
    Duration getDuration() const;
    ///getter for the likes
    std::intmax_t getLikes() const;
    ///getter for the link
    std::string getLink() const;

    ///setter for the title
    void setTitle(std::string _title);
    ///setter for the presenter
    void setPresenter(std::string _presenter);
    ///setter for the duration
    void setDuration(Duration _duration);
    ///setter for the likes
    void setLikes(std::intmax_t _likes);
    ///setter for the link
    void setLink(std::string _link);

    void play() const;
    friend std::istream& operator>>(std::istream& is, Tutorial& t);
    friend std::ostream& operator<<(std::ostream& os, const Tutorial& t);
};