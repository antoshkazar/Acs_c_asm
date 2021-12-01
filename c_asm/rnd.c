#include <stdlib.h>
#include "rnd.h"

int randomYear() {
    return rand() % 60 + 1950;
}

double randomTIOBE() {
    return rand() % 90 + 1;
}
