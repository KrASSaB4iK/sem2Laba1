#include "matrix_float.h"
#include "matrix.h"

void *sumFloat(void *mat1, void *mat2) {
    float *float_mat1 = (float*)mat1;
    float *float_mat2 = (float*)mat2;
    float *resmat = malloc(sizeof(float));
    *resmat = *float_mat1 + *float_mat2;
    return (void*)resmat;
}


void *minusFloat(void *mat1, void *mat2) {
    float *float_mat1 = (float*)mat1;
    float *float_mat2 = (float*)mat2;
    float *resmat = malloc(sizeof(float));
    *resmat = *float_mat1 - *float_mat2;
    return (void*)resmat;
}

void *multiFloat(void *mat1, void *mat2) {
    float *float_mat1 = (float*)mat1;
    float *float_mat2 = (float*)mat2;
    float *resmat = malloc(sizeof(float));
    *resmat = (*float_mat1) * (*float_mat2);
    return (void*)resmat;
}

Matrix *matrix_array_volumeFloat(Matrix *mat) {
    float num;
    for (int i = 0; i < mat->m * mat->n; ++i) {
        scanf("%f", &num);
        mat->x[i] = (void*)&num;
    }
    return mat;
}