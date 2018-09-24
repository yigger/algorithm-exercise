#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "array.h"

#define DEFAULT_LEN 12
#define MAX_ELEMENTS_LENGTH ((size_t) - 2)

static enum STATE expendArray(Array *array);

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

enum STATE arrayPush(Array *array, void *item) {
    if (check_expend(array) == 1) {
        if (expendArray(array) != OK) {
            return ERROR;
        }
    }

    array->items[array->used] = item;
    array->used ++;
    return OK;
}

static enum STATE expendArray(Array *array) {
    array->len += DEFAULT_LEN;
    if (array->len > MAX_ELEMENTS_LENGTH) {
        return ERROR; 
    }

    void **newItems = NULL;
    newItems = zmalloc(sizeof(void *) * array->len);
    if (!newItems) {
        return MALLOC_ERR;
    }

    memcpy(newItems, array->items, sizeof(void *) * array->len);
    zfree(array->items);

    array->items = newItems;
    return OK;
}

void destroyArray(Array *array) {
    zfree(array->items);
    zfree(array);
}


