#include <stdio.h>
#include "matrix.h"
#include "matrix_int.h"
#include <stdlib.h>

int main() {
    Matrixs *som = new_array_Matrixs();
    Matrix *int_ring = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
    som->array[0] = int_ring;
	int *array = malloc(5*sizeof(int));
    add_sizeof_matrix(int_ring);
    printf("%d", int_ring->n);
    set_element(int_ring, (void*)array);
    delete_Matrix(int_ring);
    return 0;
}
