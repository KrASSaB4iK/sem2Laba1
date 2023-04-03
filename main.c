#include <stdio.h>
#include "matrix.h"
#include "matrix_int.h"
#include <stdlib.h>

int main() {
    Matrix *int_ring = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
    Matrix **array = new_array_Matrixs();
    int count= 1;
    add_sizeof_matrix(int_ring);
    int_ring = matrix_array_volumeInt(int_ring);
    add_Matrix_in_array(array, int_ring, count);
    delete_array_Matrix(array, count);

}
