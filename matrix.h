#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>

typedef struct Matrix Matrix;

typedef struct RingInfo
{
    size_t size;
	void* (*sum)(Matrix***, Matrix*, Matrix*, int*);
	void* (*minus)(Matrix***, Matrix*, Matrix*, int*);
    void* (*multi)(Matrix***, Matrix*, Matrix*, int*);
    void* (*trans)(Matrix***, Matrix*, int*);
    void* (*add_line)(Matrix*);
} RingInfo;

typedef struct Matrix
{
    RingInfo *ringInfo;
    void **x;
    int n;
    int m;
} Matrix;

Matrix **new_array_Matrixs();
Matrix **add_memory_array(Matrix **array, int *len_array);
Matrix **choose_type_of_matrix(Matrix**, int *count);
Matrix *choose_Matrix(Matrix **array, int *count);
Matrix **sum_Matrix(Matrix **array, int *count);
Matrix **minus_Matrix(Matrix **array, int *count);
Matrix **multi_Matrix(Matrix **array, int *count);
Matrix **trans_Matrix(Matrix **array, int *count);


void add_Matrix_in_array(Matrix **array, Matrix *mat, int *len_array);
void delete_Matrix(Matrix *mat);
void delete_array_Matrix(Matrix **array, int *len_array);
void set_element(Matrix*, void** el);
void *get_element(Matrix*);
void add_sizeof_matrix(Matrix* mat);
void print_Matrix(Matrix *m);
void add_line_to_line(Matrix **array, int *count);


Matrix *newMatrix(
    size_t size,
	void* (*sum)(Matrix***, Matrix*, Matrix*, int*),
    void* (*minus)(Matrix***, Matrix*, Matrix*, int*),
    void* (*multi)(Matrix***, Matrix*, Matrix*, int*),
    void* (*trans)(Matrix***, Matrix*, int*), 
    void* (*add_line)(Matrix*)
);

#endif
