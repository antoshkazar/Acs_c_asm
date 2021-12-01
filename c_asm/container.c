//
// Created by Anton Zaripov on 29.11.2021.
//
#include "container.h"

void InitContainer(container *c) {
    c->len = 0;
}

void ClearContainer(container *c) {
    c->len = 0;
}

void InContainer(container *c, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    for (int i = 0; i < k; i++) {
        if (InL(&((c->cont)[c->len]), ifst)) {
            c->len++;
        }
    }
}

void InRndContainer(container *c, int size) {
    while (c->len < size) {
        if (InRndL(&((c->cont)[c->len]))) {
            c->len++;
        }
    }
}


void OutContainer(container *c, FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", c->len);
    for (int i = 0; i < c->len; i++) {
        fprintf(ofst, "%d: ", i+1);
        OutL(&(c->cont)[i], ofst);
    }
}
