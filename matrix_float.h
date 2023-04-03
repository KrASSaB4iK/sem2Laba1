#ifndef MATRIX_FLOAT
#define MATRIX_FLOAT
#include <stdlib.h>
#include "matrix.h"


void *sumFloat(void *m1, void *m2);
void *minusFloat(void *m1, void *m2);
void *multiFloat(void *m1, void *m2);
float *matrix_array_volumeFloat(int m, int n);


#endif