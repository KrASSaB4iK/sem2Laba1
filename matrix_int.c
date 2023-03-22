#include "matrix_int.h"

void *sumInt(void *m1, void *m2) {
    int *int_m1 = (int*)m1;
    int *int_m2 = (int*)m2;
    int *resm = malloc(sizeof(int));
    *resm = *int_m1 + *int_m2;
    return (void*)resm;
}

int get_elementInt(matrix *mat) {
    return ((matrixInt*)(mat->ringInfo))->x;
}

int set_elementInt(matrix *mat, int el) {
    ((matrixInt*)(mat->ringInfo))->x = el;
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