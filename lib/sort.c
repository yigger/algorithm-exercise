#include <stdio.h>
#include <time.h>
#include "helper.h"
/*
* ѡ������
* ������һ����Сֵ��Ȼ���ں�����������в����ҳ���Ԥ��ֵ��С��ֵ����֮����
*/
int *chose_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- ѡ������ -------------\n");
	for(int i = 0, minIndex = 0; i < length; ++i) {
		minIndex = i;
		for(int j = i + 1; j < length; ++j) {
			if (less(cp_arr[j], cp_arr[minIndex]) == 1) {
				minIndex = j;
			}
		}
		swap(&cp_arr[i], &cp_arr[minIndex]);
	}
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

int *bubble_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- ð������ -------------\n");
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (less(cp_arr[i], cp_arr[j]) == 1) {
				swap(cp_arr[i], cp_arr[j]);
			}
		}
	}
	getResult(cp_arr, length);
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

