//
// Created by dell on 13.03.2022.
//

#ifndef A3_4_914_CLAUDIA_MOISIUC_UI_H
#define A3_4_914_CLAUDIA_MOISIUC_UI_H

#endif //A3_4_914_CLAUDIA_MOISIUC_UI_H

#include "service.h"

typedef struct
{
    Service* serv;
} UI;

UI* createUI(Service* s);
void destroyUI(UI* ui);

void menu(UI* ui);