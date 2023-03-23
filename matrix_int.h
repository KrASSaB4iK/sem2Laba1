#ifndef MATRIX_INT
#define MATRIX_INT
#include <stdlib.h>
#include "matrix.h"

typedef struct matrixInt {
    int x;
} matrixInt;

void set_elementInt(Matrix *mat, int el);
void *get_elementInt(Matrix *mat);
void *sumInt(void *m1, void *m2);
void *minusInt(void *m1, void *m2);
void *multiInt(void *m1, void *m2);


#endif