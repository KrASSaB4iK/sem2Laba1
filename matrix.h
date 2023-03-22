#ifndef MATRIX
#define MATRIX
#include <stdlib.h>

typedef struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*minus)(void*);
    void* (*multi)(void*, void*);
    void* (set_element)(RingInfo*, int el);
    void* (get_element)(RingInfo*);
} RingInfo;

RingInfo *newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*), 
    void* (set_element)(RingInfo*, int el),
    void* (get_element)(RingInfo*)
);

typedef struct matrix
{
    RingInfo *ringInfo;
    void *x;
} matrix;


#endif
