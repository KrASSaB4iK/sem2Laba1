#include <stdio.h>
#include "matrix.h"
#include "matrixint.h"
#include "matrixfloat.h"
#include <stdlib.h>
#include "menu.h"

int main() {
    // Matrix *int_ring1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt);
    // Matrix *int_ring2 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt);
    // // Matrix *float_ring1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat);
    // // Matrix *float_ring2 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat);
    // Matrix **array = new_array_Matrixs();
    // int count= 0;
    // add_sizeof_matrix(int_ring1);
    // set_element(int_ring1, (void*)matrix_array_volumeInt(int_ring1));
    // array = add_memory_array(array, &count);
    // add_Matrix_in_array(array, int_ring1, &count);
    // //transInt(&array, int_ring1, &count);
    // add_sizeof_matrix(int_ring2);
    // array = add_memory_array(array, &count);
    // set_element(int_ring2, (void*)matrix_array_volumeInt(int_ring2));
    // add_Matrix_in_array(array, int_ring2, &count);
    // // add_sizeof_matrix(float_ring1);
    // // set_element(float_ring1, (void*)matrix_array_volumeFloat(float_ring1));
    // // array = add_memory_array(array, &count);
    // // add_Matrix_in_array(array, float_ring1, &count);
    // // add_sizeof_matrix(float_ring2);
    // // set_element(float_ring2, (void*)matrix_array_volumeFloat(float_ring2));
    // // array = add_memory_array(array, &count);
    // // add_Matrix_in_array(array, float_ring2, &count);
    // // sumFloat(&array, float_ring1, float_ring2, &count);
    // // minusFloat(&array, float_ring1, float_ring2, &count);
    // // multiFloat(&array, float_ring1, float_ring2, &count);
    // //transFloat(&array, float_ring1, &count);
	// multiInt(&array, int_ring1, int_ring2, &count);
    // print_Matrix(array[2]);
    // // print_Matrix(array[0]);
    // // print_Matrix(array[5]);
    // // print_Matrix(array[6]);
    // delete_array_Matrix(array, &count);
    menu();
}
