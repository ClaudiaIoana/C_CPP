//
// Created by dell on 20.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_REPOSITORY_H
#define A5_6_914_CLAUDIA_MOISIUC1_REPOSITORY_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_REPOSITORY_H
#include "dinamic vector.h"

class Repository
{
private:
    DynamicVector<Tutorial> arr;

public:
    ///create a repository
    Repository();
    ///destroy a repository
    void DestroyRepository();

    ///getter for the elements
    Tutorial* getAll() const;
    ///getter for the size
    int getSiz() const;
    ///getter for an element
    Tutorial* getElemm(int i) const;
    ///add an element to the dynamic vector
    void addTutorial(const Tutorial& newTutorial);
    ///remove an element from the dynamic vector
    void removeTutorial(int poz);
    ///update an element from the dynamic vector
    void updateTutorial(int poz, const Tutorial& e);
};
//