//
// Created by Anton Zaripov on 05.10.2021.
//

#ifndef ASC_C_FUNCTIONAL_H
#define ASC_C_FUNCTIONAL_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# include "rnd.h"

typedef struct functional {
    enum typization {
        stat, dynamic,
    };
    enum typization typization;
    bool lazy;
    int year;
    double TIOBE;
    int common;
}functional;

void Inf( functional *f, FILE *file);

void InRndF(functional* f);

bool OutF(functional * f, FILE *file);
#endif //ASC_C_FUNCTIONAL_H
