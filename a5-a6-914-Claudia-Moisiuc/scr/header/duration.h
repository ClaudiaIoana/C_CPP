//
// Created by dell on 19.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_DURATION_H
#define A5_6_914_CLAUDIA_MOISIUC1_DURATION_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_DURATION_H

class Duration{
private:
    int minutes;
    int seconds;

public:
    ///create a structure called duration
    Duration();

    ///create a structure called duration with given minutes and seconds
    Duration(int minutes, int seconds);

    ///create a structure called duration that is a copy
    Duration(const Duration& copy);

    ///getter of the minutes
    int get_minutes();

    ///getter of the seconds
    int get_seconds();

    ///setter of the minutes
    void set_minutes(int minutes);

    ///setter of the seconds
    void set_seconds(int seconds);
};
//