#ifndef MATRIXINT_H
#define MATRIXINT_H
#include <stdlib.h>
#include "matrix.h"


void *sumInt(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *minusInt(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *multiInt(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *transInt(Matrix ***arr, Matrix *m, int *len);
int *matrix_array_volumeInt(Matrix *mat);
void *add_lineInt(Matrix *m1);

#endif
