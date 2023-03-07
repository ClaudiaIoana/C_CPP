//
// Created by dell on 25.04.2022.
//

#ifndef A8_9_914_CLAUDIA_MOISIUC_UI_H
#define A8_9_914_CLAUDIA_MOISIUC_UI_H

#endif //A8_9_914_CLAUDIA_MOISIUC_UI_H
#include "service.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Ui{
private:
    Service service;
    std::vector<Tutorial> ui;

public:
    Ui(Service s);

    void menu();

private:
    void list();
    void same();
    static void printHead();
    static void printElem(const Tutorial& v);
    static void options_admin();
    static void options_mode();
    static void options();
    void addTutorial(int u);
    void removeTutorial();
    void updateTutorial();
    void printUser(int i);
    void listUser();
    void sameUser();
    void lisst(int i);
    void copy();
};