#include <stdio.h>
#include <time.h>
#include "helper.h"
/*
* 选择排序
* 先设置一个最小值，然后在后面遍历过程中不断找出比预设值更小的值，与之交换
*/
int *chose_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 选择排序 -------------\n");
	for(int i = 0, minIndex = 0; i < length; ++i) {
		minIndex = i;
		for(int j = i + 1; j < length; ++j) {
			if (less(cp_arr[j], cp_arr[minIndex]) == 1) {
				minIndex = j;
			}
		}
		swap(&cp_arr[i], &cp_arr[minIndex]);
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

/*
* 冒泡排序，每个数与之相邻的对比，若符合条件则交换
*/
int *bubble_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 冒泡排序 -------------\n");
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (less(cp_arr[j], cp_arr[i]) == -1) {
				swap(&cp_arr[i], &cp_arr[j]);
			}
		}
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

/*
*  插入排序01
*  第一层循环可以理解为一个索引循环，第二层循环是保证索引前面的元素都能进行交换，当索引移动到最右端的时候就是数组排序完成的时候
*/
int *insert_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 插入排序 -------------\n");
	for (int i = 1; i < length; ++i) {
		for (int j = i; j > 0 && cp_arr[j] < cp_arr[j - 1]; j--) {
			swap(&cp_arr[j], &cp_arr[j - 1]);
		}
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
}

/*
*  插入排序02
*  不需要交换元素，直接把前一个元素覆盖到后一个元素，前提需要用一个变量保存后一个元素，即当前索引值array[i]
*/
int *no_swap_insert_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 不需要交换元素的插入排序 -------------\n");
	for (int i = 1; i < length; ++i) {
		int temp = cp_arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < cp_arr[j]; j--) {
			cp_arr[j + 1] = cp_arr[j];
		}
		cp_arr[j + 1] = temp;
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
}

int *shell_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 希尔排序 -------------\n");
	int h = 1;
	while (h < ARR_LENGTH / 3) h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < length; ++i) {
			for (int j = i; j >= h && cp_arr[j] < cp_arr[j - h]; --j) {
				swap(&cp_arr[j], &cp_arr[j - h]);
			}
		}
		h = h / 3;
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
}
