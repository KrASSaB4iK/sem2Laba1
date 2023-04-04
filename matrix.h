#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>

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

Matrix **new_array_Matrixs();
Matrix **add_memory_array(Matrix **array, int *len_array);

void add_Matrix_in_array(Matrix **array, Matrix *mat, int *len_array);
void delete_Matrix(Matrix *mat);
void delete_array_Matrix(Matrix **array, int *len_array);
void set_element(Matrix*, void** el);
void *get_element(Matrix*);
void add_sizeof_matrix(Matrix* mat);
void print_Matrix(Matrix *m)

Matrix *newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*multi)(void*, void*)
);

#endif
