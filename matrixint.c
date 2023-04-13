#include "matrixint.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include "errors.h"

void *sumInt(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
    mat1->m = m1->m;
    mat1->n = m1->n;
    int *array_mat1 = malloc((m1->n*m2->n)*sizeof(int));
    int *a1 = (int*)m1->x;
    int *a2 = (int*)m2->x;
    for (int i = 0; i < m1->n*m2->n; ++i) {
        array_mat1[i] = a1[i] + a2[i];
    }
    set_element(mat1, (void*)array_mat1);
    *array = add_memory_array(*array, len);
    add_Matrix_in_array(*array, mat1, len);
}



void *minusInt(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
    mat1->m = m1->m;
    mat1->n = m2->n;
    int *array_mat1 = malloc((m1->n*m2->n)*sizeof(int));
    int *a1 = (int*)m1->x;
    int *a2 = (int*)m2->x;
    for (int i = 0; i < m1->n*m2->n; ++i) {
        array_mat1[i] = a1[i] - a2[i];
    }
    set_element(mat1, (void*)array_mat1);
    *array = add_memory_array(*array, len);
    add_Matrix_in_array(*array, mat1, len);
}

void *multiInt(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
    mat1->m = m1->m;
    mat1->n = m2->n;
    int *array_mat1 = malloc((mat1->n*mat1->m)*sizeof(int));
    int *a1 = (int*)m1->x;
    int *a2 = (int*)m2->x;
    int sum = 0, count = 0;
    for (int k = 0; k < mat1->n; k++) {
	    for (int i = 0; i < mat1->m; ++i) {
    		for (int j = 0; j < m2->m; ++j) {
    		sum += a1[k*m1->n + j]*a2[i + j*m2->n];
    	}
        array_mat1[count] = sum;
        sum = 0;
        count++;
    }
    }
    set_element(mat1, (void*)array_mat1);
    *array = add_memory_array(*array, len);
    add_Matrix_in_array(*array, mat1, len);
}

void *transInt(Matrix ***array, Matrix *m, int *len) {
	Matrix *mat1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
	mat1->m = m->n;
	mat1->n = m->m;
	int *array_mat1 = malloc((m->m*m->n)*sizeof(int));
	int *a = (int*)m->x;
	int count = 0;
	for (int i = 0; i < mat1->n; ++i) {
		for (int j = 0; j < mat1->m; ++j) {
			array_mat1[count] = a[i + (mat1->n)*j];
			count++;
		}
	}
	set_element(mat1, (void*)array_mat1);
	*array = add_memory_array(*array, len);
	add_Matrix_in_array(*array, mat1, len);	
}

int *matrix_array_volumeInt(Matrix *mat) {
    int *array = malloc((mat->n*mat->m)*sizeof(int));
    int num;
    for (int i = 0; i < mat->m * mat->n; ++i) {
        checkNumInt(&num);
        array[i] = num;
    }
    return array;
}

void *add_lineInt(Matrix ***array, Matrix *m1, int *len) {
    int l1, l2, status;
    Matrix *mat1 = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
    mat1->m = m1->m;
    mat1->n = m1->n;
    int *array_mat1 = malloc((m1->m*m1->n)*sizeof(int));
    int *a = (int*)m1->x;
    status = checkRange(&l1, m1->m);
    status = checkRange(&l2, m1->m);
    for (int i = 0; i < m1->m*m1->n; ++i) {
    	array_mat1[i] = a[i];
    }
    for (int i = 0; i < m1->n; ++i) {
        array_mat1[l1*m1->n + i] = array_mat1[l1*m1->n + i] + array_mat1[l2*m1->n + i];
    }
    set_element(mat1, (void*)array_mat1);
   	*array = add_memory_array(*array, len);
	add_Matrix_in_array(*array, mat1, len);
}
