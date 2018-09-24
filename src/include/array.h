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

// 判断是否需要扩容，如果元素总数已经占据已用长度 60% 则增加存储空间
#define check_expend(array)      \
    ((array)->len == 0 ?         \
        0 :                      \
        ((float)(array)->used / (array)->len > 0.6))

#define array_size(array) ((array)->len)
#define array_empty_size(array) ((array)->len - (array)->used)

enum STATE createArray(Array **out);
void destroyArray(Array *array);
enum STATE arrayPush(Array *array, void *item);
// enum STATE arrayRemoveAll(Array *array);
// enum STATE arrayRemoveAt(Array *array, int index);

#endif