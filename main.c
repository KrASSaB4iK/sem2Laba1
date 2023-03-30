#include <stdio.h>
#include "matrix.h"
#include "matrix_int.h"
#include <stdlib.h>

int main() {
    Matrix *int_ring = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
	int *array = malloc(5*sizeof(int));
    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }
    set_element(int_ring, (void*)&array);
    //int p = get_element(int_ring);
    delete_Matrix(int_ring);
    return 0;
}
