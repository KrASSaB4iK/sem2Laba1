#ifndef MATRIX_INT
#define MATRIX_INT
#include <stdlib.h>
#include "matrix.h"

typedef struct matrixInt {
    int x;
} matrixInt;

int set_elementInt(matrix *mat, int el);
int get_elementInt(matrix *mat);
void *sumInt(void *m1, void *m2);
void *minusInt(void *m1, void *m2);
void *multiInt(void *m1, void *m2);


#endif