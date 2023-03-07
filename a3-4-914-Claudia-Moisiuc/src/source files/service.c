//
// Created by dell on 06.03.2022.
//

#include "../Header files/service.h"
#include <string.h>
#include <stdlib.h>

/// the function creates a service
Service* createService(MedicineRepo* r)
{
    Service* s = (Service*)malloc(sizeof(Service));
    if (s == NULL)
        return NULL;
    s->repo = r;
    s->undoStack = createUnredo(10);
    s->redoStack = createUnredo(10);
    return s;
}

///the function frees the memory that is dynamically allocated
void destroyService(Service* s)
{
    // first destroy the repository inside
    destroyRepo(s->repo);

    destroyUnredo(s->undoStack);
    destroyUnredo(s->redoStack);
    // then free the memory
    free(s);
}

int position(DynamicVector* med, Medicine* m)
{
    for (int i=0; i < med->size; i++)
        if (strcmp(med->elem[i]->name, m->name) == 0 && med->elem[i]->concentration == m->concentration)
            return i;
    return -1;
}

///the function adds an element to the dynamical vector
void add_medicine(Service* s, DynamicVector* med, Medicine* m)
{
    Operation* op2 = createOperation(ADD, m);
    addunredo(s->undoStack, op2);
    Operation* op = createOperation(DELETE, m);
    addunredo(s->redoStack, op);

    for (int i=0; i < med->size; i++)
        if (strcmp(med->elem[i]->name, m->name) == 0 && med->elem[i]->concentration == m->concentration)
        {
            med->elem[i]->quantity += m->quantity;
            return ;}

    addElem(med, m);

}

///the function removes an element from the dynamical vector
void remove_medicine(Service* s, DynamicVector* med, Medicine* elem)
{
    Medicine* m;
    m =  med->elem[position(med, elem)];
    Operation* op2 = createOperation(DELETE,m);
    addunredo(s->undoStack, op2);

    removeElem(med, elem);

    Operation* op = createOperation(ADD, m);
    addunredo(s->redoStack, op);
}

///the function updates an element from the dynamical vector
void update_medicine(Service* s, DynamicVector* med, Medicine* m)
{
    Operation* op2 = createOperation(UPDATE, med->elem[position(med, m)]);
    addunredo(s->undoStack, op2);

    updateElem(med, m);

    Operation* op = createOperation(UPDATE, med->elem[position(med, m)]);
    addunredo(s->redoStack, op);
}

 /// start up data
void random_data(DynamicVector* med)
{
    Medicine* m1= createMedicine("aspirina", 30, 1,  10);
    Medicine* m2= createMedicine("no-spa", 50, 10,  10);
    Medicine* m3= createMedicine("piafen", 80, 11,  11);
    Medicine* m4= createMedicine( "nurofen", 30, 10,  12);
    Medicine* m5= createMedicine("detrical", 70, 12,  13);
    Medicine* m6= createMedicine("aulin", 30, 13,  12);
    Medicine* m7= createMedicine("aspirina", 60, 16,  10);
    Medicine* m8= createMedicine( "parasinus", 90, 40,  10);
    Medicine* m9= createMedicine( "coldrex", 130, 13,  12);
    Medicine* m10= createMedicine("aspirina", 130, 12,  12);
    addElem(med, m1);
    addElem(med, m2);
    addElem(med, m3);
    addElem(med, m4);
    addElem(med, m5);
    addElem(med, m6);
    addElem(med, m7);
    addElem(med, m8);
    addElem(med, m9);
    addElem(med, m10);

}

///the function sorts the data in a vector after the name
void sort_medicine(DynamicVector* med)
{Medicine* aux;
    for (int i=0;i<med->size-1;i++)
        for (int j=i+1;j<med->size;j++)
            if (strcmp(med->elem[i]->name, med->elem[j]->name)>0) {
                aux = med->elem[i];
                med->elem[i] = med->elem[j];
                med->elem[j] = aux;
            }

}

///the function searches in a vector the data that has a given string
void find_medicine(DynamicVector* med, char string[], DynamicVector* medi)
{
    if (string == NULL)
    {
        for (int i = 0 ;i < med->size; i++)
            addElem(medi, med->elem[i]);
        return;
    }
    for (int i = 0 ;i < med->size; i++)
        if (strstr(med->elem[i]->name, string)!=NULL)
            addElem(medi, med->elem[i]);
}

///the function creates a vector with the data that has the quantity less than a given x
void find_less_q(DynamicVector* med, int x, DynamicVector* m)
{
    for(int i = 0; i < med->size; i++)
        if (med->elem[i]->quantity < x)
            addElem(m, med->elem[i]);
}

///the undo functionality
int undo(Service* s, DynamicVector* med)
{
    if (s == NULL)
        return -1; // error

    int stackSize = getLength(s->undoStack);
    if (stackSize == 0)
        return 1; // no more undos
    Operation* op = get(s->undoStack, stackSize - 1);
    if (op == NULL)
        return -1;
    Medicine * p = getOpObject(op);
    if (p == NULL)
        return -1;

    if (getOpType(op) == ADD)
        remove_medicine(s, med,p);
    else if (getOpType(op) == DELETE)
        add_medicine(s, med, copyMedicine(p)); // must have a copy, because p
    else if( getOpType(op) == UPDATE)
        update_medicine(s, med, copyMedicine(p));
    // will be destroyed when deleting
    // the operation from the stack

    // remove the operation from "the stack"
    // should be added to the redo stack

    removeunredo(s->undoStack, s->undoStack->size-1);
    s->undoStack->size--;
    return 0;
}

///the redo functionality
int redo(Service* s, DynamicVector* med)
{
    if (s == NULL)
        return -1; // error

    int stackSize = getLength(s->redoStack);
    if (stackSize == 0)
        return 1; // no more undos
    Operation* op = get(s->redoStack, stackSize - 1);
    if (op == NULL)
        return -1;
    Medicine * p = getOpObject(op);
    if (p == NULL)
        return -1;

    if (getOpType(op) == DELETE)
        remove_medicine(s, med,p);
    else if (getOpType(op) == ADD)
        add_medicine(s, med, copyMedicine(p)); // must have a copy, because p
    else if( getOpType(op) == UPDATE)
        update_medicine(s, med, copyMedicine(p));
    // will be destroyed when deleting
    // the operation from the stack

    // remove the operation from "the stack"
    // should be added to the undo stack
    removeunredo(s->redoStack, s->redoStack->size-1);
    s->redoStack->size--;
    return 0;
}


