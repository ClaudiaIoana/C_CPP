#include "../Header files/repository.h"
#include <stdlib.h>
#include <string.h>

///the function creates a repository of a given capacity
MedicineRepo* createRepo(int capacity)
{
    MedicineRepo* v = (MedicineRepo*)malloc(sizeof(MedicineRepo));
    if (v == NULL)
        return NULL;
    v->medicine = createVector(capacity);

    return v;
}

///the function deallocates the memory that is dynamically allocated
void destroyRepo(MedicineRepo* v)
{
    if (v == NULL)
        return;
    destroyVector(v->medicine);
    free(v);
}

///the function reallocates the dynamically allocated space
///the parameter is the dynamic vector
void resize(DynamicVector* v)
{
    if(v == NULL)
        return;
    v->capacity *=2;
    TElem* new_elem = malloc(sizeof(TElem) * v->capacity);
    for(int i = 0; i < v->size; i++)
        new_elem[i] = v->elem[i];
    free(v->elem);
    v->elem = new_elem;
}

///the function adds a new element to the list
///the parameters are the dynamic vector and the element of type Medicine that is a pointer
///if the vector has reached its full capacity, the reserved space will be reallocated
void addElem(DynamicVector* v, TElem elem)
{
    if (v == NULL)
        return;
    int old_capacity = v->capacity;
    if(v->size == v->capacity) {
        resize(v);
        if(old_capacity == v->capacity)
            return;
    }

    v->elem[v->size++] = elem;
}

///the function removes an element from the list
///the parameters are the dynamic vector and the element of type Medicine that is a pointer
void removeElem(DynamicVector* v, TElem elem)
{
    if (v == NULL)
        return;
    for (int i = 0; i < v->size; i++)
        if(strcmp(v->elem[i]->name, elem->name) == 0 && v->elem[i]->concentration == elem->concentration)
        {destroyMedicine(v->elem[i]);
            for (int j = i; j < v->size-1; j++)
                v->elem[j] = v->elem[j+1];
            v->size--;

        }
}

///the function updates an element from the vector, with a given name and capacity
///the parameters are the dynamic vector and the element of type Medicine that is a pointer
void updateElem(DynamicVector* v, TElem elem)
{
    if (v == NULL)
        return;
    for (int i = 0; i < v->size; i++)
        if(strcmp(v->elem[i]->name, elem->name) == 0 && v->elem[i]->concentration == elem->concentration) {
            v->elem[i]->quantity = elem->quantity;
            v->elem[i]->price = elem->price;
        }
}
