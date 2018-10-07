#ifndef __ARRAY_H
#define __ARRAY_H

#include "common.h"

struct array_s {
    // 数组长度
    size_t len;
    // 已用长度
    size_t used;
    // 数组元素
    void **items;
};

typedef struct array_s Array;

// 判断是否需要扩容，如果元素总数已经占据已用长度 60% 则增加存储空间
#define check_expend(array)      \
    ((array)->len == 0 ?         \
        0 :                      \
        ((float)(array)->used / (array)->len > 0.6))

// 数组总长度
#define array_size(array) ((array)->len)
// 已用长度
#define array_used(array) ((array)->used)
// 数组空闲长度
#define array_empty_size(array) ((array)->len - (array)->used)

enum STATE createArray(Array **out);

enum STATE arrayAdd(Array *array, void *item);
enum STATE arrayAddAt(Array *array, void *item, size_t index);

void arrayRemoveAll(Array *array);
enum STATE arrayRemoveAt(Array *array, size_t index);

enum STATE arrayCopyShallow(Array *array, Array **out);
enum STATE arrayCopyDeep(Array *array, void*(*cp)(void *), Array **out);

enum STATE arrayGetLast(Array *array, void **out);
enum STATE arrayGetAt(Array *array, size_t index, void **out);
void destroyArray(Array *array);

void swapItem(void **t1, void **t2);
void choseSort(Array *array, int (*compare)(const void *, const void *));
void bubbleSort(Array *array, int (*compare)(const void *, const void *));
void insertSort(Array *array, int (*compare)(const void *, const void *));
void shellSort(Array *array, int (*compare)(const void *, const void *));
void quickSort(Array *array, int (*compare)(const void *, const void *));
#endif