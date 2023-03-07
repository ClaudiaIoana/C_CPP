//
// Created by dell on 11.03.2022.
//

#include "../Header files/dinamic vector.h"
#include <stdlib.h>

///it is the creation function which creates a vector of pointer
///capacity represents the capacity of the vector
///the structure contains the capacity, the size of the vector and the elements that are of Medicine type
DynamicVector* createVector(int capacity) {
    DynamicVector *v = malloc(sizeof(DynamicVector));
    if (v == NULL)
        return NULL;
    v->capacity = capacity;
    v->size = 0;
    v->elem = malloc(sizeof(TElem) * v->capacity);
    if (v->elem == NULL) {
        free(v);
        return NULL;
    }
    return v;
}


///the function deallocates the memory that is dynamically allocated
///the parameter is v, the dynamic vector
void destroyVector(DynamicVector* v)
{
    if (v == NULL)
        return;
    if(v->elem == NULL)
        return;
    for(int i = 0; i < v->size; i++)
        destroyMedicine(v->elem[i]);
    free(v->elem);
    free(v);
}

