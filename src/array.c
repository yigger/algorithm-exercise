#include <stdlib.h>
#include "common.h"
#include "array.h"

#define DEFAULT_LEN 12

enum STATE createArray(Array **out) {
    Array *array;
    array = zmalloc(sizeof(array));
    if (!array) {
        return MALLOC_ERR;
    }
    array->len = DEFAULT_LEN;
    array->used = 0;
    array->items = zmalloc(sizeof(void*) * array->len);
    if (!array->items) {
        zfree(array);
        return MALLOC_ERR;
    }
    *out = array;
    return OK;
}


