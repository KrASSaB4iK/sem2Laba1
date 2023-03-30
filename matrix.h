#ifndef MATRIX
#define MATRIX
#include <stdlib.h>
#include "matrix_int.h"

typedef struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*minus)(void*, void*);
    void* (*multi)(void*, void*);
} RingInfo;

typedef struct Matrix
{
    RingInfo *ringInfo;
    void **x;
    int n;
    int m;
} Matrix;

typedef struct Matrixs {
    Matrix **array;
    int array_len;
} Matrixs;

Matrixs* new_array_Matrixs();
void delete_Matrix(Matrix *mat);
void set_element(Matrix*, void** el);
void *get_element(Matrix*);
void add_sizeof_matrix(Matrix* mat);

Matrix *newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*multi)(void*, void*)
);

#endif
