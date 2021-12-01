//
// Created by Anton Zaripov on 29.11.2021.
//
#include "OOP.h"

void Ino(OOP *oop, FILE *file) {
    char inher[255];
    fscanf(file, "%s%lf%d", inher, &(oop->TIOBE), &(oop->year));
    if (!strcmp(inher, "one")) {
        oop->inheritance = one;
    } else if (!strcmp(inher, "plural")) {
        oop->inheritance = plural;
    } else {
        oop->inheritance = interface;
    }
}

void InRndO(struct OOP *oop) {
    int inher = rand() % 3;
    if (inher == 1) {
        oop->inheritance = one;
    } else if (inher == 2) {
        oop->inheritance = plural;
    } else
        oop->inheritance = interface;
    oop->year = randomYear();
    oop->TIOBE = randomTIOBE();
}

extern int oopCommon(void *o);

bool OutO(OOP *oop, FILE *file) {
    oop->common = oopCommon(oop);
    fprintf(file, "It is a OOP Language: inheritance = %u, TIOBE - %f, year - %d, common - %d\n", oop->inheritance,
            oop->TIOBE, oop->year, oop->common);
    return true;
}
