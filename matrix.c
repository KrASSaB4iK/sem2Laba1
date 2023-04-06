#include "matrix.h"
#include "matrixfloat.h"
#include "matrixint.h"
#include <stdio.h>

Matrix* newMatrix(
    size_t size,
    void* (*sum)(Matrix***, Matrix*, Matrix*, int*),
    void* (*minus)(Matrix***, Matrix*, Matrix*, int*),
    void* (*multi)(Matrix***, Matrix*, Matrix*, int*),
    void* (*trans)(Matrix***, Matrix*, int*)
) {
	Matrix *mat = malloc(sizeof(Matrix));
    mat->ringInfo = malloc(sizeof(RingInfo));
    mat->ringInfo->size = size;
    mat->ringInfo->sum = sum;
    mat->ringInfo->minus = minus;
    mat->ringInfo->multi = multi;
    mat->ringInfo->trans = trans;
    return mat; 
}

Matrix **new_array_Matrixs() {
    Matrix **array = malloc(0);
    return array;
}

void add_Matrix_in_array(Matrix **array, Matrix *mat, int *len_array) {
    array[*len_array - 1] = mat;
}

Matrix **add_memory_array(Matrix **array, int *len_array) {
    *len_array = *len_array + 1;
    array = realloc(array, *len_array * sizeof(Matrix));
    return array;
}

void print_Matrix(Matrix *m) {
if (m->ringInfo->sum == sumInt){
	int *a = (int*)m->x;
	int count = 0;
		for (int i = 0; i < m->n; ++i) {
		 	for (int j = 0; j < m->m; ++j) {
		   		printf("%d ",a[count]);
		   		count++;
		   	}
		   	printf("lkgnodfn\n");
		}
	}
	else {
		float *a = (float*)m->x;
		int count = 0;
		for (int i = 0; i < m->n; ++i) {
		    for (int j = 0; j < m->m; ++j) {
		   		printf("%f ",a[count]);
		   		count++;
		   	}
		   	printf("\n");
		}
	}
}	


void *get_element(Matrix *mat) {
    return (void*)(mat->x);
}

void set_element(Matrix *mat, void** el) {
   	mat->x = el;
}

void delete_Matrix(Matrix *mat) {
	free(mat->ringInfo);
    free(mat->x);
    free(mat);
}

void delete_array_Matrix(Matrix **array, int *len_array) {
    int i = 0;
    while (i < *len_array) {
        delete_Matrix(array[i]);
        i++;
    }
    free(array);
}

void add_sizeof_matrix(Matrix *mat) {
    scanf("%d %d", &(mat->m), &(mat->n));
}
