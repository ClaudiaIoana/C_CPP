//
// Created by dell on 17.03.2022.
//

#include "../Header files/ui.h"
#include <assert.h>


// Tests
void testAdd() {
    MedicineRepo *r = createRepo(1);
    Service *s = createService(r);

    Medicine *p1 = createMedicine("no-spa", 10, 13, 10);
    addElem(r->medicine, p1);
    assert(r->medicine->size== 1);
    assert(strcmp(s->repo->medicine->elem[0]->name, "no-spa") == 0);

    Medicine *p2 = createMedicine("paracetamol", 10, 122, 12);
    add_medicine(s, s->repo->medicine, p2);
    assert(s->repo->medicine->size== 2);

    // destroy the test repository
    destroyService(s);

    destroyMedicine(p1);
    destroyMedicine(p2);
}

void testUpdate() {
    MedicineRepo *r = createRepo(10);
    Service *s = createService(r);

    Medicine *p1 = createMedicine("no-spa", 10, 13, 10);
    Medicine *p2 = createMedicine("no-spa", 10, 3, 0);
    addElem(r->medicine, p1);
    updateElem(r->medicine, p1);
    assert(r->medicine->elem[0]->price == 0);
    assert(r->medicine->elem[0]->quantity == 3);

    Medicine *p3 = createMedicine("paracetamol", 10, 122, 12);
    Medicine *p4 = createMedicine("paracetamol", 10, 1, 10);
    add_medicine(s, s->repo->medicine, p3);
    update_medicine(s, s->repo->medicine, p4);
    assert(s->repo->medicine->elem[0]->price == 1);
    assert(s->repo->medicine->elem[0]->quantity == 10);

    // destroy the test repository
    destroyService(s);

    destroyMedicine(p1);
    destroyMedicine(p2);
}

void testRemove() {
    MedicineRepo *r = createRepo(10);
    Service *s = createService(r);

    Medicine *p1 = createMedicine("no-spa", 10, 13, 10);
    addElem(r->medicine, p1);
    updateElem(r->medicine, p1);
    assert(r->medicine->size == 0);

    Medicine *p2 = createMedicine("paracetamol", 10, 122, 12);
    add_medicine(s, s->repo->medicine, p2);
    remove_medicine(s, s->repo->medicine, p2);
    assert(s->repo->medicine->size== 0);

    // destroy the test repository
    destroyService(s);

    destroyMedicine(p1);
    destroyMedicine(p2);
}

void testDestroy()
{
    Medicine *p1 = createMedicine("no-spa", 10, 13, 10);
    destroyMedicine(p1);
    assert(p1 == NULL);

    DynamicVector *v = createVector(10);
    destroyVector(v);
    assert(v == NULL);

    Medicine *p2 = createMedicine("no-spa", 10, 13, 10);
    Operation *p = createOperation(ADD, p2);
    destroyOperation(p);
    assert(p == NULL);

    MedicineRepo *r = createRepo(10);
    Service *s = createService(r);
    destroyService(s);
    assert(s == NULL);
    assert(r == NULL);
}

void testunredo()
{
    MedicineRepo *r = createRepo(10);
    Service *s = createService(r);

    Medicine *p1 = createMedicine("no-spa", 10, 13, 10);
    addElem(r->medicine, p1);
    updateElem(r->medicine, p1);
    assert(s->undoStack->size == 2);
    assert(s->redoStack->size == 2);

    destroyService(s);

    destroyMedicine(p1);
}

void testsMedicineRepo()
{
    testAdd();
    testRemove();
    testUpdate();
    testDestroy();
    testunredo();
}