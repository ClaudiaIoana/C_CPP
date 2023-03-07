//
// Created by dell on 21.04.2022.
//

#include "../header/duration.h"

///create a structure called duration
Duration::Duration()
{
    this->minutes = 0;
    this->seconds = 0;
}

///create a structure called duration with given minutes and seconds
Duration::Duration(int minutes, int seconds)
{
    this->minutes = minutes;
    this->seconds = seconds;
}

///create a structure called duration that is a copy
Duration::Duration(const Duration& copy)
{
    this->minutes = copy.minutes;
    this->seconds = copy.seconds;
}

///getter of the minutes
int Duration::get_minutes() const {
    return minutes;
}

///getter of the seconds
int Duration::get_seconds() const {
    return seconds;
}

///setter of the minutes
void Duration::set_minutes(int minutes)
{
    this->minutes = minutes;
}

///setter of the seconds
void Duration::set_seconds(int seconds)
{
    this->seconds = seconds;
}
