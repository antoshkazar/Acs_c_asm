//
// Created by Anton Zaripov on 29.11.2021.
//
#include "language.h"

bool InL(language *lang, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch(k) {
        case 1:
            lang->k = PROCEDURE;
            Inp(&(lang->p), ifst);
            return true;
        case 2:
            lang->k = Oop;
            Ino(&(lang->oop), ifst);
            return true;
        case 3:
            lang->k = FUNCTIONAL;
            Inf(&(lang->f),ifst);
            return  true;
        default:
            return false;
    }
}

bool InRndL(language *s) {
    int k = (rand() % 3) + 1;
    switch(k) {
        case 1:
            s->k = PROCEDURE;
            InRndP(&(s->p));
            return true;
        case 2:
            s->k = Oop;
            InRndO(&(s->oop));
            return true;
        case 3:
            s->k = FUNCTIONAL;
            InRndF(&(s->f));
            return true;
        default:
            return false;
    }
}
void OutL(language *s, FILE *ofst){

    switch(s->k) {
        case PROCEDURE:
            OutP(&(s->p), ofst);
            break;
        case Oop:
            OutO(&(s->oop), ofst);
            break;
        case FUNCTIONAL:
            OutF(&(s->f),ofst);
            break;
        default:
            fprintf(ofst, "Incorrect figure!\n");
    }
}
