#include <stdio.h>
#include "matrix.h"
#include "matrix_int.h"
#include <stdlib.h>

int main() {
    RingInfo *int_ring = Create(sizeof(int), &sumInt, &minusInt, &multiInt);
    free(int_ring); 
    printf("Hello");
    return 0;
}