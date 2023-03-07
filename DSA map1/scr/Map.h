//
// Created by dell on 12.05.2022.
//

#ifndef DSA_MAP1_MAP_H
#define DSA_MAP1_MAP_H

#endif //DSA_MAP1_MAP_H
#pragma once
#include <utility>
#include <math.h>
//DO NOT INCLUDE MAPITERATOR


//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111)
class MapIterator;

using namespace std;

class Map {
    //DO NOT CHANGE THIS PART
    friend class MapIterator;

private:
    TElem* elems;
    int* next;
    int firstEmpty;
    int capacity;
    int sizee;
    int hash(TKey c) const;

public:

    // implicit constructor
    Map();

    // adds a pair (key,value) to the map
    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
    //if the key does not exist, a new pair is added and the value null is returned
    TValue add(TKey c, TValue v);

    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
    TValue search(TKey c) const;

    //removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
    TValue remove(TKey c);

    //returns the number of pairs (key,value) from the map
    int size() const;

    //checks whether the map is empty or not
    bool isEmpty() const;

    //returns an iterator for the map
    MapIterator iterator() const;

    // destructor
    ~Map();

    void change_first();

    void resize();

    bool verify_load_factor() const;

};



