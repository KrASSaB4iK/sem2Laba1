#include "matrix.h"
#include "matrixfloat.h"
#include "matrixint.h"
#include <stdio.h>
#include "errors.h"

Matrix* newMatrix(
    size_t size,
    void* (*sum)(Matrix***, Matrix*, Matrix*, int*),
    void* (*minus)(Matrix***, Matrix*, Matrix*, int*),
    void* (*multi)(Matrix***, Matrix*, Matrix*, int*),
    void* (*trans)(Matrix***, Matrix*, int*),
    void* (*add_line)(Matrix***, Matrix*, int*)
) {
	Matrix *mat = malloc(sizeof(Matrix));
    mat->ringInfo = malloc(sizeof(RingInfo));
    mat->ringInfo->size = size;
    mat->ringInfo->sum = sum;
    mat->ringInfo->minus = minus;
    mat->ringInfo->multi = multi;
    mat->ringInfo->trans = trans;
    mat->ringInfo->add_line = add_line;
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
		   	printf("\n");
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

Matrix **choose_type_of_matrix(Matrix **array, int *count){
    int c;
    checkRange(&c, 3);
    if (c == 1) {
        Matrix *a = newMatrix(sizeof(int), &sumInt, &minusInt, &multiInt, &transInt, &add_lineInt);
        add_sizeof_matrix(a);
        set_element(a, (void*)matrix_array_volumeInt(a));
        array = add_memory_array(array, count);
        add_Matrix_in_array(array, a, count);
    }
    else {
        Matrix *a = newMatrix(sizeof(float), &sumFloat, &minusFloat, &multiFloat, &transFloat, add_lineFloat);
        add_sizeof_matrix(a);
        set_element(a, (void*)matrix_array_volumeFloat(a));
        array = add_memory_array(array, count);
        add_Matrix_in_array(array, a, count);
    }
    return array;
}

Matrix *choose_Matrix(Matrix **array,int *count) {
    printf("Enter the matrix number, numbering from 0: ");
    int a;
    checkRange(&a, *count);
    return(array[a]);
}

Matrix **sum_Matrix(Matrix **array, int *count) {
    printf("Enter the matrix number 1, numbering from 0: ");
    int a, b;
    checkRange(&a, *count);
    printf("Enter the matrix number 2, numbering from 0: ");
    checkRange(&b, *count);
    if (array[a]->ringInfo->sum == sumInt) {
        sumInt(&array, array[a], array[b], count);
    }
    else {
        sumFloat(&array, array[a], array[b], count);
    }
    return(array);
}

Matrix **minus_Matrix(Matrix **array, int *count) {
    printf("Enter the matrix number 1, numbering from 0: ");
    int a, b;
    checkRange(&a, *count);
    printf("Enter the matrix number 2, numbering from 0: ");
    checkRange(&b, *count);
    if (array[a]->ringInfo->sum == sumInt) {
        minusInt(&array, array[a], array[b], count);
    }
    else {
        minusFloat(&array, array[a], array[b], count);
    }
    return(array);
}

Matrix **add_line_to_line(Matrix **array, int *count) {
    printf("Enter the matrix number, numbering from 0: ");
    int a;
    checkRange(&a, *count);
    if (array[a]->ringInfo->sum == sumInt) {
        add_lineInt(&array, array[a], count);
    }
    else {
        add_lineFloat(&array ,array[a], count);
    }
    return array;
}

Matrix **multi_Matrix(Matrix **array, int *count) {
    printf("Enter the matrix number 1, numbering from 0: ");
    int a, b;
    checkRange(&a, *count);
    printf("Enter the matrix number 2, numbering from 0: ");
    checkRange(&b, *count);
    if (array[a]->ringInfo->sum == sumInt) {
        multiInt(&array, array[a], array[b], count);
    }
    else {
        multiFloat(&array, array[a], array[b], count);
    }
    return(array);
}

Matrix **trans_Matrix(Matrix **array, int *count) {
    printf("Enter the matrix number, numbering from 0: ");
    int a;
    checkRange(&a, *count);
    if (array[a]->ringInfo->sum == sumInt) {
        transInt(&array, array[a], count);
    }
    else {
        transFloat(&array, array[a], count);
    }
    return(array);
}

void add_sizeof_matrix(Matrix *mat) {
	printf("Enter the number of rows and columns: ");
    checkNumInt(&mat->m);
    checkNumInt(&mat->n);
}
