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

/*
* ð������ÿ������֮���ڵĶԱȣ������������򽻻�
*/
int *bubble_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- ð������ -------------\n");
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (less(cp_arr[j], cp_arr[i]) == -1) {
				swap(&cp_arr[i], &cp_arr[j]);
			}
		}
	}
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
	return cp_arr;
}

/*
*  ��������01
*  ��һ��ѭ���������Ϊһ������ѭ�����ڶ���ѭ���Ǳ�֤����ǰ���Ԫ�ض��ܽ��н������������ƶ������Ҷ˵�ʱ���������������ɵ�ʱ��
*/
int *insert_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- �������� -------------\n");
	for (int i = 1; i < length; ++i) {
		for (int j = i; j > 0 && cp_arr[j] < cp_arr[j - 1]; j--) {
			swap(&cp_arr[j], &cp_arr[j - 1]);
		}
	}
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
}

/*
*  ��������02
*  ����Ҫ����Ԫ�أ�ֱ�Ӱ�ǰһ��Ԫ�ظ��ǵ���һ��Ԫ�أ�ǰ����Ҫ��һ�����������һ��Ԫ�أ�����ǰ����ֵarray[i]
*/
int *no_swap_insert_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- ����Ҫ����Ԫ�صĲ������� -------------\n");
	for (int i = 1; i < length; ++i) {
		int temp = cp_arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < cp_arr[j]; j--) {
			cp_arr[j + 1] = cp_arr[j];
		}
		cp_arr[j + 1] = temp;
	}
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
}

int *shell_sort(int *array, int length) {
	int cp_arr[ARR_LENGTH];
	copyArray(array, cp_arr, length);
	printf("---------- ϣ������ -------------\n");
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
	printf("---------- ������ -------------\n");
	getResult(cp_arr, length);
}
