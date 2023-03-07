//
// Created by dell on 13.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_OPERATION_H
#define A3_4_914_CLAUDIA_MOISIUC_OPERATION_H

#endif //A3_4_914_CLAUDIA_MOISIUC_OPERATION_H

#include "dinamic vector.h"

typedef enum {
    ADD,
    DELETE,
    UPDATE
} opType;

typedef struct {
    opType type;
    Medicine* p;
} Operation;

Operation* createOperation(opType type, Medicine* p);
void destroyOperation(Operation* o);

opType getOpType(Operation* o);
Medicine * getOpObject(Operation* o);