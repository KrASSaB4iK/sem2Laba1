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

Matrix **new_array_Matrixs() {
    Matrix **array = malloc(0);
    return array;
}

void add_Matrix_in_array(Matrix **array, Matrix *mat, int *len_array) {
    array[*len_array - 1] = mat;
}

Matrix **add_memory_array(Matrix **array, int *len_array) {
    *len_array = *len_array + 1;
    array = realloc(array, *len_array * sizeof(Matrix));
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

void delete_array_Matrix(Matrix **array, int *len_array) {
    int i = 0;
    while (i < *len_array) {
        delete_Matrix(array[i]);
    }
    
}

void add_sizeof_matrix(Matrix *mat) {
    scanf("%d %d", &(mat->n), &(mat->m));
}