#include "matrix.h"

struct RingInfo* newMatrix(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*minus)(void*),
    void* (*multi)(void*, void*),
    void* (set_element)(RingInfo*, int el),
    void* (get_element)(RingInfo*)
) {
    RingInfo *mat = malloc(sizeof(RingInfo));
    mat->size = size;
    mat->sum = sum;
    mat->minus = minus;
    mat->multi = multi;
    mat->set_element = set_element;
    mat->get_element = get_element;
    return mat;    
}
