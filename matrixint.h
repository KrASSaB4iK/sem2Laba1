#ifndef MATRIXINT_H
#define MATRIXINT_H
#include <stdlib.h>
#include "matrix.h"


void *sumInt(Matrix *m1, Matrix *m2);
void *minusInt(void *m1, void *m2);
void *multiInt(void *m1, void *m2);
int *matrix_array_volumeInt(Matrix *mat);


#endif
