#ifndef MATRIX
#define MATRIX
#include <stdlib.h>

typedef struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*minus)(void*);
    void* (*multi)(void*, void*);
} RingInfo;

RingInfo *Create(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*) 
);

typedef struct matrix
{
    RingInfo *ringInfo;
    void **mat;
};


#endif
