#ifndef MATRIX_INT
#define MATRIX_INT
#include <stdlib.h>

typedef struct matrix {
    int *mat;
};

void sumInt(void *m1, void *m2, void *res);


#endif