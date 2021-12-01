#include <stdio.h>
#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include <string.h>
#include <signal.h>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile\n"
           "  Or:\n"
           "     command -n number outfile\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile\n"
           "  Or:\n"
           "     command -n number outfile\n");
}

extern double PerimeterSumContainer(void *c, int len);


int main(int argc, char *argv[]) {
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    printf("Starting...\n");
    clock_t start = clock();
    container c;
    InitContainer(&c);
    if (!strcmp(argv[1], "-f")) {
        FILE *ifst = fopen(argv[2], "r");
        InContainer(&c, ifst);
        printf("Container filled, len - %d\n", c.len);
        fclose(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n",
                   size);
            return 3;
        }
        srand((unsigned int) (time(0)));
        InRndContainer(&c, size);
        printf("Container filled, size: %d\n", c.len);
    } else {
        errMessage2();
        return 2;
    }

    FILE *ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    OutContainer(&c, ofst1);
    ClearContainer(&c);
    clock_t end = clock();
    double calcTime = ((double) (end - start)) / (CLOCKS_PER_SEC + 1.0);
    printf("Calculation went in %f sec\n", calcTime);
    printf("Finished!\n");
    return 0;
}
