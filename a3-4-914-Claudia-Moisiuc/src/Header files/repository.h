//
// Created by dell on 13.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_REPOSITORY_H
#define A3_4_914_CLAUDIA_MOISIUC_REPOSITORY_H

#endif //A3_4_914_CLAUDIA_MOISIUC_REPOSITORY_H

#include "undo_redo.h"


typedef struct {
    DynamicVector* medicine;
}MedicineRepo;


/// Creates a MedicineRepo.
MedicineRepo* createRepo(int capacity);

/// Destroys a given Medicine repository. The memory is freed.
void destroyRepo(MedicineRepo* v);

void addElem(DynamicVector* v, TElem elem);
///the function adds a new element to the list
///the parameters are the dynamic vector and the element of type Medicine that is a pointer
///if the vector has reached its full capacity, the reserved space will be reallocated

void removeElem(DynamicVector* v, TElem elem);
///the function removes an element from the list
///the parameters are the dynamic vector and the element of type Medicine that is a pointer

void updateElem(DynamicVector* v, TElem elem);
///the function updates an element from the vector, with a given name and capacity
///the parameters are the dynamic vector and the element of type Medicine that is a pointer
