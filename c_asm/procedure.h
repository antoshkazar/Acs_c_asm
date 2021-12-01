//
// Created by Anton Zaripov on 05.10.2021.
//

#ifndef ASC_C_PROCEDURE_H
#define ASC_C_PROCEDURE_H


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rnd.h"

//Процедурный яп.
typedef struct procedure {
    bool abstract;//Наличие/отсутвие абстракций.
    double TIOBE;
    int year;
    int common;
} procedure;

void Inp(procedure *p, FILE *file);

void InRndP(procedure *p);

bool OutP(procedure *p, FILE *file);

#endif //ASC_C_PROCEDURE_H
