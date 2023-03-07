//
// Created by dell on 20.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_UI_H
#define A5_6_914_CLAUDIA_MOISIUC1_UI_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_UI_H
#include "service.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Ui{
private:
    Service service;
    DynamicVector<Tutorial> ui;

public:
    Ui(Service s);

    void menu();

private:
    void list();
    void same();
    void printHead();
    void printElem(const Tutorial& v);
    void options_admin();
    void options_mode();
    void options();
    void addTutorial(int u);
    void removeTutorial();
    void updateTutorial();
    void printUser(int i);
    void listUser();
    void sameUser();
    void lisst(int i);
    void copy();
};
//