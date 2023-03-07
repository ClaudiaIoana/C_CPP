//
// Created by dell on 13.03.2022.
//
#include "../Header files/operation.h"
#include <stdlib.h>

///the function creates an operation
Operation* createOperation(opType type, Medicine* p) {
    Operation* op = malloc(sizeof(Operation));
    op->type = type;

    Medicine * copyOfP = createMedicine(p->name, p->concentration, p->quantity, p->price);
    op->p = copyOfP;

    return op;
}

///the function destroys an operation
void destroyOperation(Operation* o) {
    if (o == NULL)
        return;

    destroyMedicine(o->p);
    free(o);
}

///the function gets the type of the operation
opType getOpType(Operation* o) {
    if (o == NULL)
        return -1;
    return o->type;
}

///the function gets the element
Medicine* getOpObject(Operation* o) {
    if (o == NULL)
        return NULL;
    return o->p;
}

