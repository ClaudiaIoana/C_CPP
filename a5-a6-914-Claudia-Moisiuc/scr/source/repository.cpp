//
// Created by dell on 20.03.2022.
//

#include "../header/repository.h"

///create a repository
Repository::Repository()
{
}

void Repository::DestroyRepository() {
    arr.DestroyVector();
}

///getter for the elements
Tutorial* Repository::getAll() const
{
    return arr.getAllElems();
}

///getter for an element
Tutorial* Repository::getElemm(int i) const {
    return arr.getElem(i);
}

///getter for the size
int Repository::getSiz() const
{
    return arr.getSize();
}

///add an element to the dynamic vector
void Repository::addTutorial(const Tutorial& newTutorial)
{
    arr + newTutorial;
}

///remove an element from the dynamic vector
void Repository::removeTutorial(int poz)
{
    arr.remove(poz);
}

///update an element from the dynamic vector
void Repository::updateTutorial(int poz, const Tutorial& e)
{
    arr.update(poz, e);
}
//