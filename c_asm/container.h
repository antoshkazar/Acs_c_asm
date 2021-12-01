//
// Created by Anton Zaripov on 29.11.2021.
//

#ifndef C_ASM_CONTAINER_H
#define C_ASM_CONTAINER_H
#include "language.h"
#include <stdlib.h>
#include <stdio.h>

enum {max_len = 10000}; // максимальная длина

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
typedef struct container {
    int len; // текущая длина
    language cont[max_len];
} container;

// Инициализация контейнера
void InitContainer(container *c);

// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(container *c);

// Ввод содержимого контейнера из указанного потока
void InContainer(container *c, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(container *c, int size);

// Вывод содержимого контейнера в указанный поток
void OutContainer(container *c, FILE *ofst);

#endif //C_ASM_CONTAINER_H
