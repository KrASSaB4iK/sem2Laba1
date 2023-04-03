#include "matrix_int.h"
#include "matrix.h"

void *sumInt(void *m1, void *m2) {
    int *int_m1 = (int*)m1;
    int *int_m2 = (int*)m2;
    int *resm = malloc(sizeof(int));
    *resm = *int_m1 + *int_m2;
    return (void*)resm;
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

Matrix *matrix_array_volumeInt(Matrix *mat) {
    int num;
    for (int i = 0; i < mat->m * mat->n; ++i) {
        scanf("%d", &num);
        mat->x[i] = (void*)num;
    }
    return mat;
}