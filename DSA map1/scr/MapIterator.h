//
// Created by dell on 12.05.2022.
//

#ifndef DSA_MAP1_MAPITERATOR_H
#define DSA_MAP1_MAPITERATOR_H

#endif //DSA_MAP1_MAPITERATOR_H
#pragma once
#include "Map.h"
class MapIterator
{
    //DO NOT CHANGE THIS PART
    friend class Map;
private:
    const Map& map;
    int index;
    int firstElement;

    MapIterator(const Map& m);
public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};


