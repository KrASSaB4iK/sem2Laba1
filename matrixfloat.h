#ifndef MATRIXFLOAT_H
#define MATRIXFLOAT_H
#include <stdlib.h>
#include "matrix.h"


void *sumFloat(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *minusFloat(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *multiFloat(Matrix ***arr, Matrix *m1, Matrix *m2, int *len);
void *transFloat(Matrix ***arr, Matrix *m, int *len);
float *matrix_array_volumeFloat(Matrix *mat);


#endif
