//
// Created by Anton Zaripov on 29.11.2021.
//
#include "procedure.h"



void Inp(procedure *p, FILE *file) {
    int abstr;
    fscanf(file, "%d%lf%d", &abstr, &(p->TIOBE), &(p->year));
    p->abstract = abstr;
}

void InRndP(procedure *p) {
    p->abstract = rand() % 2;
    p->TIOBE = randomTIOBE();
    p->year = randomYear();
}

extern int procedureCommon(void *p);

bool OutP(procedure *p, FILE *file) {
    p->common = procedureCommon(p);
    bool abstr = false;
    if(p->abstract)
        abstr = true;
   fprintf(file, "It is a Procedure Language: abstract = %d, TIOBE - %f, year - %d, common - %d\n", abstr, p->TIOBE, p->year,
            p->common);
    return true;
}