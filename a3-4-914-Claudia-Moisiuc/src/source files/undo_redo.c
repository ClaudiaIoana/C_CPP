//
// Created by dell on 14.03.2022.
//


#include "../Header files/undo_redo.h"
#include <stdlib.h>

///it is the creation function which creates a vector of pointer
///capacity represents the capacity of the vector
///the structure contains the capacity, the size of the vector and the elements that are of Medicine type
UnredoVector* createUnredo(int capacity) {
    UnredoVector *v = malloc(sizeof(UnredoVector));
    if (v == NULL)
        return NULL;
    v->capacity = capacity;
    v->size = 0;
    v->elem = malloc(sizeof(TElement) * v->capacity);
    if (v->elem == NULL) {
        free(v);
        return NULL;
    }
    return v;
}


///the function deallocates the memory that is dynamically allocated
///the parameter is v, the dynamic vector
void destroyUnredo(UnredoVector * v)
{
    if (v == NULL)
        return;
    if(v->elem == NULL)
        return;
    for(int i = 0; i < v->size; i++)
        destroyOperation(v->elem[i]);
    free(v->elem);
    free(v);
}

///the function resizes the dynamically allocated memory
void resize_u(UnredoVector * v)
{
    if(v == NULL)
        return;
    v->capacity *=2;
    TElement* new_elem = malloc(sizeof(TElement) * v->capacity);
    for(int i = 0; i < v->size; i++)
        new_elem[i] = v->elem[i];
    free(v->elem);
    v->elem = new_elem;
}

///the function adds a command in the undo stack
void addunredo(UnredoVector * v, TElement elem)
{
    if (v == NULL)
        return;
    int old_capacity = v->capacity;
    if(v->size == v->capacity) {
        resize_u(v);
        if(old_capacity == v->capacity)
            return;
    }

    v->elem[v->size++] = elem;
}

//////the function removes a command from the undo stack
void removeunredo(UnredoVector* v, int e)
{
    if (v == NULL || e < 0 || e >= v->size)
        return;
    destroyOperation(v->elem[e]);
    // !!! Do this only if we delete any element but the last
    /*if (e != v->size - 1)
        v->elem[e] = v->elem[v->size - 1];*/
    v->size--;
}

///the function returns the size of the array
int getLength(UnredoVector * arr)
{
    if (arr == NULL)
        return -1;

    return arr->size;
}

///the function returns the element from a position of the array
TElement get(UnredoVector * arr, int pos)
{
    if (arr == NULL || pos < 0)
        return NULL;
    return arr->elem[pos];
}