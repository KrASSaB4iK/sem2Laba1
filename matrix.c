#include "matrix.h"

struct RingInfo* Create(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*) 
) {
    RingInfo *mat = malloc(sizeof(RingInfo));
    mat->size = size;
    mat->sum = sum;
    mat->minus = minus;
    mat->multi = multi;    
}
