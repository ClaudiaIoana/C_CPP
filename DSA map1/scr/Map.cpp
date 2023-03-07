//
// Created by dell on 12.05.2022.
//

#include "Map.h"
#include "MapIterator.h"

int Map::hash(TKey c) const {
    return abs(c) % this->capacity;
}

bool Map::verify_load_factor() const {
    return (double)sizee/capacity < 0.6;
}

Map::Map() {
    this->capacity = 13;
    this->sizee = 0;
    this->elems = new TElem[this->capacity];
    this->next = new int[this->capacity];
    for (int i = 0; i < this->capacity; i++){
        this->elems[i] = NULL_TELEM;
        this->next[i] = -1;
    }
    this->firstEmpty = 0;
}

Map::~Map() {
    delete[] this->elems;
    delete[] this->next;
}

void Map::resize(){
    int siz = this->sizee;
    int old_capacity = capacity;
    this->capacity = capacity * 2;
    auto copy = new TElem[old_capacity];
    int i;
    for(i = 0; i < old_capacity; i++)
        copy[i] = this->elems[i];

    delete[] this->elems;
    this->elems = new TElem [capacity];
    delete[] this->next;
    this->next = new int[capacity];

    for (i = 0; i < this->capacity; i++){
        this->elems[i] = NULL_TELEM;
        this->next[i] = -1;
    }

    this->firstEmpty = 0;
    for(i = 0; i < old_capacity; i++){
        if(copy[i] != NULL_TELEM)
            add(copy[i].first, copy[i].second);
    }
    this->sizee = siz;
    delete[] copy;
}

void Map::change_first() {
    this->firstEmpty = this->firstEmpty+1;
    while(this->firstEmpty < this->capacity && this->elems[firstEmpty] != NULL_TELEM)
        firstEmpty++;
}

TValue Map::add(TKey c, TValue v){
    if(!verify_load_factor())
        resize();


    TValue old = NULL_TVALUE;
    int hash_value = hash(c);

    if(this->elems[hash_value] == NULL_TELEM){
        if(hash_value == this->firstEmpty)
            change_first();
        this->next[hash_value] = -1;
        this->sizee++;
        this->elems[hash_value].first = c;
        this->elems[hash_value].second = v;
    }
    else{
        int parsing = hash_value;
        while(this->next[parsing] != -1 && this->elems[parsing].first != c)
            parsing = this->next[parsing];
        if(this->elems[parsing].first == c){
            old = this->elems[parsing].second;
            this->elems[parsing].second = v;
        }
        else if(this->next[parsing] == -1){
            this->elems[firstEmpty].first = c;
            this->elems[firstEmpty].second = v;
            this->next[firstEmpty] = -1;
            this->next[parsing] = firstEmpty;
            change_first();
            this->sizee++;
        }
    }
    return old;
}

TValue Map::search(TKey c) const{
    int hash_value = hash(c);
    while(this->next[hash_value] != -1 && this->elems[hash_value].first != c)
        hash_value = this->next[hash_value];
    if(this->elems[hash_value].first == c)
        return this->elems[hash_value].second;
    return NULL_TVALUE;
}

TValue Map::remove(TKey c){
    TValue returnValue = NULL_TVALUE;
    int current = this->hash(c);
    int prev = -1;
    while (current != -1 && this->elems[current].first != c) {
        prev = current;
        current = this->next[current];
    }

    if (current == -1) {
        returnValue = NULL_TVALUE;
    } else{
        returnValue = this->elems[current].second;
        bool over = false;
        do {
            int current2 = this->next[current];
            int prev2 = current;
            while (current2 != -1 && this->hash(this->elems[current2].first) != current) {
                prev2 = current2;
                current2 = this->next[current2];
            }
            if (current2 == -1)
                over = true;
            else {
                this->elems[current] = this->elems[current2];
                prev = prev2;
                current = current2;
            }
        } while (!over);
        if (prev == -1) {
            int idx = 0;
            while (idx < this->capacity && prev == -1)
                if (this->next[idx] == current) {
                    prev = idx;
                }else {
                    idx = idx + 1;
                }
        }
        if (prev != -1)
            this->next[prev] = this->next[current];
        this->sizee--;
        this->elems[current] = NULL_TELEM;
        this->next[current] = -1;
        if (this->firstEmpty > current)
            this->firstEmpty = current;
    }
    return returnValue;
}


int Map::size() const {
    return sizee;
}

bool Map::isEmpty() const{
    if(sizee == 0)
        return true;
    return false;
}

MapIterator Map::iterator() const {
    return MapIterator(*this);
}



