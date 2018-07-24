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

int *bubble_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- 冒泡排序 -------------\n");
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (less(cp_arr[i], cp_arr[j]) == 1) {
				swap(cp_arr[i], cp_arr[j]);
			}
		}
	}
	getResult(cp_arr, length);
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

