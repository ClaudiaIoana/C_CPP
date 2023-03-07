//
// Created by dell on 11.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_DINAMIC_VECTOR_H
#define A3_4_914_CLAUDIA_MOISIUC_DINAMIC_VECTOR_H

#endif //A3_4_914_CLAUDIA_MOISIUC_DINAMIC_VECTOR_H

#include "medicine.h"

typedef Medicine* TElem;
typedef void (*DestroyElementFunctionType)(void*);

typedef struct{
    TElem* elem;
    int size, capacity;
}DynamicVector;

DynamicVector* createVector(int capacity);
///it is the creation function which creates a vector of pointer
///capacity represents the capacity of the vector
///the structure contains the capacity, the size of the vector and the elements that are of Medicine type

void destroyVector(DynamicVector* v);
///the function deallocates the memory that is dynamically allocated
///the parameter is v, the dynamic vector
