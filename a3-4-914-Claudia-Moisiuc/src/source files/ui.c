//
// Created by dell on 05.03.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Header files/ui.h"

#ifndef MAX
#define MAX 10
#endif

int position(DynamicVector* med, Medicine* m);

UI* createUI(Service* s)
{
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->serv = s;

    return ui;
}

void destroyUI(UI * ui)
{
    // first destroy the Service
    destroyService(ui->serv);
    // free the UI memory
    free(ui);
}

void menu_options()
{
    printf("0. Leave the program.\n");
    printf("1. List the medicine.\n");
    printf("2. Add a medicine.\n");
    printf("3. Remove a medicine.\n");
    printf("4. Update a medicine.\n");
    printf("5. Search for a string.\n");
    printf("6. Quantity less than x.\n");
    printf("7. Undo.\n");
    printf("8. Redo.\n");
}

Medicine* input_remove()
{
    char* name;
    char n;
    int c;
    float q, p;
    printf("NAME");
    scanf("%s", &n);
    name = &n;
    printf("CONCENTRATION");
    scanf("%d", &c);
    q = 0;
    p = 0;
    Medicine* m = createMedicine(name, c, q, p);
    return m;
}

void print_medicine(DynamicVector* med)
{
    int col1[]={1,2,3,4,5,6,7, 8,9,10, 11,12,13,14,15,16,17};
    char *row[] = {" ", "NAME", "CONCENTRATION", "QUANTITY", "PRICE"};
    printf("%*s | %*s | %*s | %*s | %*s\n", -5, row[0], -MAX, row[1], -MAX, row[2], -MAX, row[3], -MAX, row[4]);
    for (int i=0; i<med->size; i++)
    {printf("%-3d | %-10s | %10d | %-10f | %-10f\n", col1[i], med->elem[i]->name, med->elem[i]->concentration, med->elem[i]->quantity, med->elem[i]->price);

    }
}

Medicine* input_add()
{
    char* name;
    char n;
    int c;
    float q, p;
    printf("NAME   ");
    scanf("%s", &n);
    name = &n;
    printf("CONCENTRATION  ");
    scanf("%d", &c);
    printf("QUANTITY  ");
    scanf("%f", &q);
    printf("PRICE  ");
    scanf("%f", &p);

    Medicine* m = createMedicine(name, c, q, p);
    return m;

}

void find_string(DynamicVector* med, char string[])
{
    DynamicVector* m = createVector(10);
    find_medicine(med, string,m);
    sort_medicine(m);
    print_medicine(m);
}

void less_than(DynamicVector* med, int x)
{
   DynamicVector* m = createVector(10);
   find_less_q(med, x, m);
   sort_medicine(m);
   print_medicine(m);
}

void menu(UI* ui)
{
    Medicine* m;
    DynamicVector* med = createVector(10);

    random_data(med);
    menu_options();

    int ok = 1, option, x;
    while (ok == 1) {
        printf("OPTION");
        scanf("%d", &option);
        if (option == 0)
            ok = 0;
        else if (option == 1)
            print_medicine(med);
        else if (option == 2) {
            m = input_add();
            add_medicine(ui->serv, med, m);
            //add_undo(redo, med);
        } else if (option == 3) {
            m = input_remove();
            if(position(med, m) == -1)
                printf("invalid input");
            else
                remove_medicine(ui->serv,med, m);
        } else if (option == 4) {
            m = input_add();
            if(position(med, m) == -1)
                printf("invalid input");
            else
                update_medicine(ui->serv,med, m);
        } else if (option == 5) {
            char string[100], sth[1];
            scanf("%s", sth);
            printf("String");
            scanf("%s", string);
            find_string(med, string);
        } else if (option == 6) {
            scanf("%d", &x);
            less_than(med, x);
        } else if (option == 7) {
            int  u = undo(ui->serv, med);
            if (u == 1)
                printf("No more undoes.");
        } else if (option == 8){
            int  u = redo(ui->serv, med);
            if (u == 1)
                printf("No more undoes.");
        }
        else
            printf("Invalid output\n");
    }
    destroyMedicine(m);
    destroyVector(med);
}


