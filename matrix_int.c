#include "matrix_int.h"

void *sumInt(void *m1, void *m2) {
    int *int_m1 = (int*)m1;
    int *int_m2 = (int*)m2;
    void *resm = *int_m1 + *int_m2;
    return (void*)resm;
}