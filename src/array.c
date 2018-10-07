#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "array.h"

#define DEFAULT_LEN 12
#define MAX_ELEMENTS_LENGTH ((size_t) - 2)

static enum STATE expendArray(Array *array);
static size_t indexAbs(Array *array, size_t index);
static void qSort(Array *array, int begin, int end, int (*compare)(const void *, const void *));

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
	array_used(array) = 0;
	// 分配存储元素的数组长度，默认值为 DEFAULT_LEN
	array->items = zcalloc(sizeof(void*) * array->len);
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
enum STATE arrayAdd(Array *array, void *item) {
	if (check_expend(array) == 1 && expendArray(array) != OK) {
		return ERROR;
	}

	array->items[array_used(array)] = item;
	array_used(array) ++;
	return OK;
}

/**
 * 向数组的索引位置 index 填入新值
 * @params[array] 数组指针
 * @params[item] 待插入的值
 * @params[index] 待填入的索引值
 * @return OK || ERROR 
*/
enum STATE arrayAddAt(Array *array, void *item, size_t index) {
	// 将数值转为合法的索引
	index = indexAbs(array, index);

	// 首先，需要确保数组索引值不会溢出
	// 其次，如果元素大于等于最后一个元素，则直接调用 arrayAdd 即可
	if (index >= array_used(array)) {
		return arrayAdd(array, item);
	}

	if (index > MAX_ELEMENTS_LENGTH) {
		return ERROR;
	}

	// 扩容检查
	if (check_expend(array) == 1 && expendArray(array) != OK) {
		return ERROR;
	}

	// 计算需要移动的长度
	size_t shift = (array->len - index) * sizeof(int);
	// 把当前索引的地址向后移一位，目的腾出位置插入新值
	memmove(&(array->items[index + 1]),
			&(array->items[index]),
			shift);
	// 填入新值
	array->items[index] = item;
	array_used(array) ++;
	return OK;
}

/**
 * 浅拷贝。并不复制数据，只复制指向数据的指针，因此是多个指针指向同一份数据
 * @params[array] 数组指针
 * @params[out] 作为输出返回值
*/
enum STATE arrayCopyShallow(Array *array, Array **out) {
	Array *copy;
	copy = zmalloc(sizeof(copy));
	if (!copy) {
		return MALLOC_ERR;
	}

	copy->items = zcalloc(sizeof(void *) * array->len);
	if (!copy->items) {
		zfree(copy);
		return MALLOC_ERR;
	}

	copy->len = array->len;
	copy->used = array_used(array);

	// 复制一份数组所有元素的地址
	memcpy(copy->items,
		   array->items,
		   sizeof(void *) * array->len);

	*out = copy;
	return OK;
}

/**
 * 深拷贝会复制原始数据，每个指针指向一份独立的数据
 * @params[array] 数组指针
 * @params[cp] 函数指针，用于复制元素的值
 * @params[out] 作为输出返回值
*/
enum STATE arrayCopyDeep(Array *array, void*(*cp)(void *), Array **out) {
	Array *copy;
	copy = zmalloc(sizeof(copy));
	if (!copy) {
		return MALLOC_ERR;
	}

	copy->items = zcalloc(sizeof(void *) * array_used(array));
	if (!copy->items) {
		zfree(copy);
		return MALLOC_ERR;
	}

	copy->len = array_used(array);
	copy->used = array_used(array);
	for(int i = 0; i < array_used(array); ++i) {
		// 如果有复制函数传入，则根据复制函数返回值，否则，按默认 int 类型进行复制值
		// 当然，这是不严谨的，理论上应当强迫调用者输入复制处理函数
		if (cp) {
			copy->items[i] = cp(array->items[i]);
		} else {
			int *value = (int*)malloc(sizeof(int));
			*value = *((int*)array->items[i]);
			copy->items[i] = value;
		}
	}

	*out = copy;
	return OK;
}

/**
 * 移除数组中所有元素（伪）
 * @params[array] 数组指针 
*/
void arrayRemoveAll(Array *array) {
	array_used(array) = 0;
}

/**
 * 移除指定位置的元素
 * @params[array] 数组指针
 * @params[index] 索引值
*/
enum STATE arrayRemoveAt(Array *array, size_t index) {
	index = indexAbs(array, index);
	if (index < 0 || index > array_used(array)) {
		return ERROR;
	}

	size_t size = (array->len - index) * sizeof(int);
	memmove(&(array->items[index]),
			&(array->items[index+1]),
			size);

	array_used(array) --;
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
	newItems = zcalloc(sizeof(void *) * array->len);
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
 * 获取数组最后一个数字 
 * @params[array] 数组指针
 * @params[out] 接受返回值
 * @return OK || ERROR
*/
enum STATE arrayGetLast(Array *array, void **out) {
	if (array_used(array) == 0) {
		*out = NULL;
		return ERROR;
	}
	*out = array->items[array_used(array) - 1];
	return OK;
}

enum STATE arrayGetAt(Array *array, size_t index, void **out) {
	if (array_used(array) == 0) {
		*out = NULL;
		return ERROR;
	}
	index = indexAbs(array, index);
	*out = array->items[index];
	return OK;
}

/**
 * 负数索引转换为有效的索引..
 * eg:  array: 1, 3, 5, 7
 *      index = -1, value = 7
 *      index = -2, value = 5
 *      index = -5, value = 7
 * @params[array] 数组指针
 * @params[index] 索引值
 * @return index 返回索引值 
*/
static size_t indexAbs(Array *array, size_t index) {
	if (index == -1) {
		return array_used(array);
	}

	while ((int)index < 0) {
		index = array_used(array) + index;
	}

	if (index > array->len || index > array_used(array)) {
		index = array_used(array);
	}

	return index;
}

/**
 * 销毁数组
 * @params[array] 数组指针 
*/
void destroyArray(Array *array) {
	zfree(array->items);
	zfree(array);
}

/*
 * 选择排序
 *  每一轮只发生一次交换操作
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 * @params[array] 数组地址
 * @params[compare] 比较元素大小的函数指针
*/ 
void choseSort(Array *array, int (*compare)(const void *, const void *)) {
	if (array_used(array) == 0) {
		return ;
	} 
	
	int i = 0, minIndex = 0;
	for (; i < array_used(array); ++i) {
		minIndex = i;
		for (int j = i + 1; j < array_used(array); ++j) {
			if (compare(array->items[minIndex], array->items[j]) == 1) {
				minIndex = j;
			}
		}
		swapItem(&array->items[i], &array->items[minIndex]);
	}
}

/*
 * 冒泡排序
 *  每一次比较都可能发生一次交换操作
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 * @params[array] 数组地址
 * @params[compare] 比较元素大小的函数指针
*/ 
void bubbleSort(Array *array, int (*compare)(const void *, const void *)) {
	if (array_used(array) == 0) {
		return ;
	} 
	
	for(int i = 0;i < array_used(array); ++i) {
		for(int j = i + 1; j < array_used(array); ++j) {
			if (compare(array->items[i], array->items[j]) == 1) {
				swapItem(&array->items[i], &array->items[j]);
			}
		}
	}
}

/**
 * 插入排序
*/
void insertSort(Array *array, int (*compare)(const void *, const void *)) {
	if (array_used(array) == 0) {
		return ;
	}

	for (int i = 1; i < array_used(array); ++i) {
		for (int j = i; j > 0 && compare(array->items[j - 1], array->items[j]) == 1; j--) {
			swapItem(&array->items[j], &array->items[j - 1]);
		}
	}
}

/**
 * 希尔排序 
*/
void shellSort(Array *array, int (*compare)(const void *, const void *)) {
	if (array_used(array) == 0) {
		return ;
	}

	int h = 1;
	while (h < array_used(array)) h = 3 * h + 1;

	while (h >= 1) {
		for(int i = h; i < array->used; ++i) {
			for(int j = i; j - h >= 0 && compare(array->items[j - h], array->items[j]) == 1; j --) {
				swapItem(&array->items[j], &array->items[j - h]);
			}
		}
		h = h / 3;
	}
}

/**
 * 快速排序 
*/
void quickSort(Array *array, int (*compare)(const void *, const void *)) {
	qSort(array, 0, array->used - 1, compare);
}

/**
 * 快排辅助方法，递归排序
*/
static void qSort(Array *array, int begin, int end, int (*compare)(const void *, const void *)) {
	if (begin >= end) {
		return ;
	}
	
	// 设置基准值
	void *baseValue = array->items[begin];
	int left = begin;
	int right = end;

	// 从基准值的下一个数开始比较
	while (left < right) {
		// 找出比基准值小的数，然后停下
		while(left < right && compare(array->items[right], baseValue) != -1) {
			right --;
		}
		// 找出比基准值大的数字，然后停下
		while(left < right && compare(array->items[left], baseValue) != 1) {
			left ++;
		}
		// 交换这两个值
		swapItem(&array->items[left], &array->items[right]);
	}
	// 把基值放置在正确的位置
	swapItem(&array->items[begin], &array->items[left]);
	qSort(array, begin, left, compare);
	qSort(array, left + 1, end, compare);
}

/**
 *  交换地址
*/
void swapItem(void **t1, void **t2) {
	void *temp;
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}
