#ifndef MATRIX
#define MATRIX
#include <stdlib.h>
#include "matrix_int.h"

typedef struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*minus)(void*);
    void* (*multi)(void*, void*);
} RingInfo;

typedef struct Matrix
{
    RingInfo *ringInfo;
    void **x;
    void *n;
    void *m;
} Matrix;

void delete_Matrix(Matrix *mat);
void set_element(Matrix*, void* el);
void *get_element(Matrix*);

Matrix *newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*)
);

#endif
