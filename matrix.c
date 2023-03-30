#include "matrix.h"
#include "matrix_int.h"
#include <stdio.h>
Matrix* newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*multi)(void*, void*)
) {
	Matrix *mat = malloc(sizeof(Matrix));
    mat->ringInfo = malloc(sizeof(RingInfo));
    mat->ringInfo->size = size;
    mat->ringInfo->sum = sum;
    mat->ringInfo->minus = minus;
    mat->ringInfo->multi = multi;
    return mat; 
}

Matrixs* new_array_Matrixs() {
    Matrixs *array = malloc(sizeof(Matrixs));
    return array;
}

void *get_element(Matrix *mat) {
    return (void*)(mat->x);
}

void set_element(Matrix *mat, void** el) {
   	mat->x = el;
}

void delete_Matrix(Matrix *mat) {
	free(mat->ringInfo);
    free(mat->x);
    free(mat);
}

void add_sizeof_matrix(Matrix *mat) {
    scanf("%d %d", &(mat->n), &(mat->m));
}