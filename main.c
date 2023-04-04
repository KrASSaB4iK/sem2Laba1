#include <stdio.h>
#include "matrix.h"
#include "matrixint.h"
#include <stdlib.h>

int main() {
    Matrix *int_ring1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
    Matrix *int_ring2 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt);
    Matrix **array = new_array_Matrixs();
    int count= 1;
    add_sizeof_matrix(int_ring1);
    set_element(int_ring1, (void*)matrix_array_volumeInt(int_ring1));
    add_Matrix_in_array(array, int_ring1, &count);
    add_sizeof_matrix(int_ring2);
    set_element(int_ring2, (void*)matrix_array_volumeInt(int_ring2));
    add_Matrix_in_array(array, int_ring1, &count);
    add_Matrix_in_array(array, sumInt(int_ring1, int_ring2), &count);
    print_Matrix(array[2]);
    delete_array_Matrix(array, &count);

}
