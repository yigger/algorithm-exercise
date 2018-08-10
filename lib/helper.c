#include <stdio.h>
#include "helper.h"
#define PREFIX_SIZE (0)

void *zmalloc(size_t size) {
	void *ptr = malloc(size + PREFIX_SIZE);
	if (ptr == NULL) {
		printf("zmalloc 分配失败\n");
		exit(1);
	}
	return ptr;
}

void *zcalloc(size_t size) {
	void *ptr = calloc(1, size+PREFIX_SIZE);
	if (ptr == NULL) {
		printf("calloc 内存分配失败");
		exit(1);
	}
	return ptr;
}

void zfree(void *ptr) {
	if (ptr == NULL) return ;
	free(ptr);
}

void swap(int *num1, int *num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int less(int num1, int num2) {
	if (num1 < num2) {
		return 1;
	} else if (num1 > num2) {
		return -1;
	} else {
		return 0;
	}
}

int compareInt(const void *a, const void *b) 
{
	int x = *(const int *)a;
	int y = *(const int *)b;
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	return 0;
}

void getResult(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("Index(%d) - %d \n", i, arr[i]);
	}
}
int *copyArray(int *array) {
	int *copy = (int *)malloc(ARR_LENGTH * sizeof(int));
	for (int i = 0; i < ARR_LENGTH; ++i) {
		copy[i] = array[i];
	}
	return copy;
}

