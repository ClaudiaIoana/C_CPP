//
// Created by dell on 12.05.2022.
//

#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    this->index = 0;
    while (this->index < this->map.capacity && (this->map.elems[this->index] == NULL_TELEM))
        this->index++;
    this->firstElement = this->index;
}


void MapIterator::first() {
    this->index = 0;
    while (this->index < this->map.capacity && (this->map.elems[this->index] == NULL_TELEM))
        this->index++;
    this->firstElement = index;
}


void MapIterator::next() {
    if (this->index >= this->map.capacity)
        throw exception();
    this->index++;
    while (this->index < this->map.capacity && (this->map.elems[this->index] == NULL_TELEM))
        this->index++;
}


TElem MapIterator::getCurrent(){
    if (this->index >= this->map.capacity)
        throw exception();
    return this->map.elems[this->index];
}


bool MapIterator::valid() const {
    if(this->index < this->map.capacity)
        return true;
    return false;
    return false;
}



