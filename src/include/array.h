#ifndef __ARRAY_H
#define __ARRAY_H

#include "common.h"


typedef struct {
    // 数组长度
    size_t len;
    // 已用长度
    size_t used;
    // 数组元素
    void **items;
} Array;

#define array_size(array) ((array)->len)
#define array_empty_size(array) ((array)->len - (array)->used)

enum STATE createArray(Array **out);
// void destroyArray(Array *array);
// enum STATE arrayPush(Array *array, void *item);
// enum STATE arrayRemoveAll(Array *array);
// enum STATE arrayRemoveAt(Array *array, int index);

#endif