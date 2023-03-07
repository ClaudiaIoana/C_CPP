//
// Created by dell on 05.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_MEDICINE_H
#define A3_4_914_CLAUDIA_MOISIUC_MEDICINE_H

#endif //A3_4_914_CLAUDIA_MOISIUC_MEDICINE_H
#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    int concentration;
    float quantity;
    float price;
}Medicine;

Medicine* createMedicine(char name[], int concentration, float quantity, float price);
///it is the creation function which creates a type
///the type contains a name, a concentration, a quantity and a price

void destroyMedicine(Medicine *m);
///the function deallocates the memory that is dynamically allocated
///the parameter is m, an element of type MEDICINE

Medicine * copyMedicine(Medicine * p);
///the function creates a copy of the medicine that is given