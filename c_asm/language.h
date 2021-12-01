//
// Created by Anton Zaripov on 29.11.2021.
//

#ifndef C_ASM_LANGUAGE_H
#define C_ASM_LANGUAGE_H

#include <stdbool.h>
#include <stdio.h>

#include "procedure.h"
#include "OOP.h"
#include "functional.h"

//------------------------------------------------------------------------------
// значения ключей для каждой из фигур

const int PROCEDUR;
const int OOp ;
const int FUNC;
typedef enum key {PROCEDURE, Oop, FUNCTIONAL} key;
//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
typedef struct language {

    int k;
    union {
        struct procedure p;
        struct OOP oop;
        struct functional f;
    };
} language;

// Ввод обобщенной фигуры
bool InL(language *lang, FILE *ifst);

// Случайный ввод обобщенной фигуры
bool InRndL(language *s);

// Вывод обобщенной фигуры
void OutL(language *s, FILE *ofst);

// Вычисление периметра обобщенной фигуры
double PerimeterShape(language *s);

#endif //C_ASM_LANGUAGE_H
