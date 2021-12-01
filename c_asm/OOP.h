//
// Created by Anton Zaripov on 05.10.2021.
//

#ifndef ASC_C_OOP_H
#define ASC_C_OOP_H

//#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rnd.h"

typedef struct OOP {
    enum inheritance {
        one, plural, interface
    };
    enum inheritance inheritance;
    int year;
    double TIOBE;
    int common;
} OOP;

void Ino(OOP *oop, FILE *file);

void InRndO(OOP *oop);

bool OutO(OOP *oop, FILE *file);

#endif //ASC_C_OOP_H
