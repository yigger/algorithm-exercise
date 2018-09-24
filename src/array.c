#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "array.h"

#define DEFAULT_LEN 12
#define MAX_ELEMENTS_LENGTH ((size_t) - 2)

static enum STATE expendArray(Array *array);

/**
 * 创建新的数组 
 * @param[out] 指向数组的指针的指针
 * @return OK || MALLOC_ERR 返回成功或者内存分配失败的状态码 
*/
enum STATE createArray(Array **out) {
    Array *array;
    array = zmalloc(sizeof(array));
    if (!array) {
        return MALLOC_ERR;
    }

    array->len = DEFAULT_LEN;
    array->used = 0;
    // 分配存储元素的数组长度，默认值为 DEFAULT_LEN
    array->items = zmalloc(sizeof(void*) * array->len);
    // 分配失败则销毁后退出
    if (!array->items) {
        zfree(array);
        return MALLOC_ERR;
    }
    *out = array;
    return OK;
}

/**
 * 往数组追加一个元素，如果数组已用长度超过 60%，则增加数组容量
 * @params[array] 数组指针
 * @params[item] 无类型的地址
 * @return OK || ERROR
*/
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

/**
 * 追加数组的容量， 每次默认增加 DEFAULT_LEN 的长度
 * @params[array] 数组指针
 * @return OK || ERROR || MALLOC_ERR
*/
static enum STATE expendArray(Array *array) {
    array->len += DEFAULT_LEN;
    // 长度不能超过最大限度
    if (array->len > MAX_ELEMENTS_LENGTH) {
        return ERROR; 
    }

    void **newItems = NULL;
    newItems = zmalloc(sizeof(void *) * array->len);
    if (!newItems) {
        return MALLOC_ERR;
    }

    // 将存储在 array 的旧元素全部迁移到扩容后的数组中去，然后销毁旧的内存空间
    memcpy(newItems, array->items, sizeof(void *) * array->len);
    zfree(array->items);

    array->items = newItems;
    return OK;
}

/**
 * 销毁数组
 * @params[array] 数组指针 
*/
void destroyArray(Array *array) {
    zfree(array->items);
    zfree(array);
}


