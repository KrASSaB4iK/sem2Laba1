#include <stdio.h>
#include "matrix.h"
#include "matrix_int.h"
#include <stdlib.h>

int main() {
    Matrix *int_ring = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
    set_element(int_ring, 10);
    int p = get_element(int_ring);
    printf("%d", p);
    free(int_ring); 
    printf("Hello");
    return 0;
}