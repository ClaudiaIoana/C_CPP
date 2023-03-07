//
// Created by dell on 13.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_SERVICE_H
#define A3_4_914_CLAUDIA_MOISIUC_SERVICE_H

#endif //A3_4_914_CLAUDIA_MOISIUC_SERVICE_H

#include "repository.h"

typedef struct
{
    MedicineRepo* repo;
    UnredoVector * undoStack;
    UnredoVector * redoStack;
} Service;

/// the function creates a service
Service* createService(MedicineRepo* r);

///the function frees the memory that is dynamically allocated
void destroyService(Service* s);

///the function adds an element to the dynamical vector
void add_medicine(Service* s, DynamicVector* med, Medicine* m);

///the function removes an element from the dynamical vector
void remove_medicine(Service* s, DynamicVector* med, Medicine* elem);

///the function updates an element from the dynamical vector
void update_medicine(Service* s, DynamicVector* med, Medicine* m);

/// start up data
void random_data(DynamicVector* med);

///the function sorts the data in a vector after the name
void sort_medicine(DynamicVector* med);

///the function searches in a vector the data that has a given string
void find_medicine(DynamicVector* med, char string[], DynamicVector* medi);

///the function creates a vector with the data that has the quantity less than a given x
void find_less_q(DynamicVector* med, int x, DynamicVector* m);

///the undo functionality
int undo(Service* s, DynamicVector* med);

///the redo functionality
int redo(Service* s, DynamicVector* med);





void find_less_q(DynamicVector* med,int x,DynamicVector* m);