#include "matrix.h"
#include "matrix_int.h"
struct Matrix* newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*)
) {
    RingInfo *mat = malloc(sizeof(RingInfo));
    mat->size = size;
    mat->sum = sum;
    mat->minus = minus;
    mat->multi = multi;
    return mat;    
}

void *get_element(Matrix *mat) {
    return (void*)(((matrixInt*)(mat->ringInfo))->x);
}

void set_elementInt(Matrix *mat, int el) {
    ((matrixInt*)(mat->ringInfo))->x = el;
}
