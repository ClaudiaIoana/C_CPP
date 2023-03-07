//
// Created by dell on 11.03.2022.
//

#include "../Header files/medicine.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

///it is the creation function which creates a type
///the type contains a name, a concentration, a quantity and a price
Medicine* createMedicine(char *name, int concentration, float quantity, float price)
{
    Medicine* m = malloc(sizeof(Medicine));
    if(m == NULL)
        return NULL;
    m->name = malloc(sizeof(char) * (strlen(name)+1));
    if(m->name == NULL) {
        free(m);
        return NULL;
    }
    strcpy(m->name, name);
    m->concentration = concentration;
    m->quantity = quantity;
    m->price = price;

    return m;
}

///the function deallocates the memory that is dynamically allocated
///the parameter is m, an element of type MEDICINE
void destroyMedicine(Medicine *m)
{
    if (m == NULL)
        return;
    free(m->name);
    free(m);
}

///the function creates a copy of the medicine that is given
Medicine * copyMedicine(Medicine * p) {
    if (p == NULL)
        return NULL;
    return createMedicine(p->name, p->concentration, p->quantity, p->price);
}