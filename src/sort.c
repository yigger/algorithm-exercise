#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "common.h"
/*
* 选择排序
* 先设置一个最小值，然后在后面遍历过程中不断找出比预设值更小的值，与之交换
*/
int *chose_sort(int *array, int length) {
	int *cp_arr = copyArray(array);
	printf("---------- 选择排序 -------------\n");
	for (int i = 0, minIndex = 0; i < length; ++i) {
		minIndex = i;
		for (int j = i + 1; j < length; ++j) {
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
	int *cp_arr = copyArray(array);
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
	int *cp_arr = copyArray(array);
	printf("---------- 插入排序 -------------\n");
	for (int i = 1; i < length; ++i) {
		for (int j = i; j > 0 && cp_arr[j] < cp_arr[j - 1]; j--) {
			swap(&cp_arr[j], &cp_arr[j - 1]);
		}
	}
	printf("---------- 排序结果 -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

/*
*  插入排序02
*  不需要交换元素，直接把前一个元素覆盖到后一个元素，前提需要用一个变量保存后一个元素，即当前索引值array[i]
*/
int *no_swap_insert_sort(int *array, int length) {
	int *cp_arr = copyArray(array);
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
	return cp_arr;
}

/*
* 希尔排序，相当于远距离的插入排序
*/
int *shell_sort(int *array, int length) {
	int *cp_arr = copyArray(array);
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
	return cp_arr;
}

/*
* 归并排序
*/
void merge(int arr[], int start, int m, int r)
{
	int i, j, k;
	int n1 = m - start + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[start + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = start; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else{
			arr[k++] = R[j++];
		}
	}

	while (i < n1)
	{
		arr[k++] = L[i++];
	}

	while (j < n2)
	{
		arr[k++] = R[j++];
	}
}

void sort(int *array, int start, int end) {
	if (start >= end) return;
	int mid = start + (end - start) / 2;
	
	sort(array, start, mid);
	sort(array, mid + 1, end);
	merge(array, start, mid, end);
}

int *merge_sort(int *array, int length) {
	printf("---------- 归并排序 -------------\n");
	int *cp_arr = copyArray(array);
	sort(cp_arr, 0, length - 1);
	getResult(cp_arr, length);
	return temp;
}
/*
* * 快速排序
*/
void quicksort(int *array, int begin, int end)
{
	int value = array[begin];
	int q_start = begin;
	int q_end = end;
	int mid = (q_start + q_end) / 2;
	if (begin >= end) return ;

	while (begin < end) {
		while (begin < end && array[end] <= value) {
			end--;
		}
		swap(&array[begin], &array[end]);
		while (begin < end && array[begin] >= value) {
			begin++;
		}
		swap(&array[begin], &array[end]);
	}
	swap(&array[begin], &value);

	quicksort(array, q_start, mid);
	quicksort(array, mid + 1, q_end);
}

void quick_sort(int *array, int length) {
	printf("---------- 快速排序 -------------\n");
	int *cp_arr = copyArray(array);
	quicksort(cp_arr, 0, length - 1);
	getResult(cp_arr, length);
}