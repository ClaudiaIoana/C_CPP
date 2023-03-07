//
// Created by dell on 14.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_UNDO_REDO_H
#define A3_4_914_CLAUDIA_MOISIUC_UNDO_REDO_H

#endif //A3_4_914_CLAUDIA_MOISIUC_UNDO_REDO_H
#include "operation.h"

typedef void* TElement;

typedef struct{
    TElement* elem;
    int size, capacity;
}UnredoVector;

UnredoVector* createUnredo(int capacity);
///it is the creation function which creates a vector of pointer
///capacity represents the capacity of the vector
///the structure contains the capacity, the size of the vector and the elements that are of Medicine type

void destroyUnredo(UnredoVector* v);
///the function deallocates the memory that is dynamically allocated
///the parameter is v, the dynamic vector

void addunredo(UnredoVector * v, TElement elem);
///the function adds a command in the undo stack

int getLength(UnredoVector * arr);
///the function returns the size of the array

TElement get(UnredoVector * arr, int pos);
///the function returns the element from a position of the array

void removeunredo(UnredoVector* v, int e);