//
// Created by Anton Zaripov on 29.11.2021.
//
#include "functional.h"

void Inf(functional *f, FILE *file) {
    char typiz[255];
    int lazy;
    fscanf(file, "%s%d%lf%d", typiz, &lazy, &(f->TIOBE), &(f->year));
    f->lazy = lazy;
    if (!strcmp(typiz, "stat")) {
        f->typization = stat;
    } else {
        f->typization = dynamic;
    }
}

void InRndF(functional *f) {
    int typiz;
    typiz = rand() % 2;
    if (typiz) {
        f->typization = stat;
    } else {
        f->typization = dynamic;
    }
    f->lazy = rand() % 2;
    f->TIOBE = randomTIOBE();
    f->year = randomYear();
}

extern int functionalCommon(void *f);

bool OutF(functional *f, FILE *file) {
    f->common = functionalCommon(f);
    fprintf(file, "It is a Functional Language: typization = %u, lazy = %d, TIOBE - %f, year - %d, common - %d\n",
            f->typization, f->lazy, f->TIOBE, f->year, f->common);
    return true;
}