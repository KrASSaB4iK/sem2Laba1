#include "matrix.h"
#include "matrixfloat.h"
#include <stdlib.h>
#include <stdio.h>
#include "errors.h"


void *sumFloat(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, &add_lineFloat);
    mat1->m = m1->m;
    mat1->n = m1->n;
    float *array_mat1 = malloc((m1->n*m2->n)*sizeof(float));
    float *a1 = (float*)m1->x;
    float *a2 = (float*)m2->x;
    for (int i = 0; i < m1->n*m2->n; ++i) {
        array_mat1[i] = a1[i] + a2[i];
    }
    set_element(mat1, (void*)array_mat1);
    *array = add_memory_array(*array, len);
    add_Matrix_in_array(*array, mat1, len);
}

void *minusFloat(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, &add_lineFloat);
    mat1->m = m1->m;
    mat1->n = m1->n;
    float *array_mat1 = malloc((m1->n*m2->n)*sizeof(float));
    float *a1 = (float*)m1->x;
    float *a2 = (float*)m2->x;
    for (int i = 0; i < m1->n*m2->n; ++i) {
        array_mat1[i] = a1[i] - a2[i];
    }
    set_element(mat1, (void*)array_mat1);
    *array = add_memory_array(*array, len);
    add_Matrix_in_array(*array, mat1, len);
}

void *multiFloat(Matrix ***array, Matrix *m1, Matrix *m2, int *len) {
    Matrix *mat1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, &add_lineFloat);
    mat1->m = m1->m;
    mat1->n = m2->n;
    float *array_mat1 = malloc((mat1->n*mat1->m)*sizeof(float));
    float *a1 = (float*)m1->x;
    float *a2 = (float*)m2->x;
    float sum = 0;
    int count = 0;
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

void *transFloat(Matrix ***array, Matrix *m, int *len) {
	Matrix *mat1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, &add_lineFloat);
	mat1->m = m->n;
	mat1->n = m->m;
	float *array_mat1 = malloc((m->m*m->n)*sizeof(float));
	float *a = (float*)m->x;
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

float *matrix_array_volumeFloat(Matrix *mat) {
    float *array = malloc((mat->n*mat->m)*sizeof(float));
    float num;
    printf("Заполните матрицу: ");
    for (int i = 0; i < mat->m * mat->n; ++i) {
        checkNumFloat(&num);
        array[i] = num;
    }
    cleaner();
    return array;
}

void *add_lineFloat(Matrix ***array, Matrix *m1, int *len) {
    int l1, l2, status;
    Matrix *mat1 = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, &add_lineFloat);
    mat1->m = m1->n;
    mat1->n = m1->m;
    float *array_matrix = malloc(m1->m*m1->n*sizeof(float));
    float *a = (float*)m1->x;
    status = checkRange(&l1, m1->m);
    status = checkRange(&l2, m1->m);
    for (int i = 0; i < m1->m*m1->n; ++i) {
    	array_matrix[i] = a[i];
    }
    for (int i = 0; i < m1->n; ++i) {
        array_matrix[l1*m1->n + i] = array_matrix[l1*m1->n + i] + array_matrix[l2*m1->n + i];
    }
    set_element(mat1, (void*)array_matrix);
   	*array = add_memory_array(*array, len);
	add_Matrix_in_array(*array, mat1, len);
}
