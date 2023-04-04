#include "matrixint.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

Matrix *sumInt(Matrix *m1, Matrix *m2) {
    Matrix *mat1 = malloc(sizeof(Matrix));
    mat1->m = m1->m;
    mat1->n = m1->n;
    int *array_mat1 = malloc((m1->n*m2->n)*sizeof(int));
    for (int i = 0; i < m1->n*m2->n; ++i) {
        array_mat1[i] = ((int*)m1->x)[i] + ((int*)m2->x)[i];
    }
    set_element(mat1, (void*)matrix_array_volumeInt(mat1));
    return mat1;
}

void *minusInt(void *m1, void *m2) {
    int *int_m1 = (int*)m1;
    int *int_m2 = (int*)m2;
    int *resm = malloc(sizeof(int));
    *resm = *int_m1 - *int_m2;
    return (void*)resm;
}

void *multiInt(void *m1, void *m2) {
    int *int_m1 = (int*)m1;
    int *int_m2 = (int*)m2;
    int *resm = malloc(sizeof(int));
    *resm = (*int_m1) * (*int_m2);
    return (void*)resm;
}

int *matrix_array_volumeInt(Matrix *mat) {
    int *array = malloc((mat->n*mat->m)*sizeof(int));
    int num;
    for (int i = 0; i < mat->m * mat->n; ++i) {
        scanf("%d", &num);
        array[i] = num;
    }
    return array;
}