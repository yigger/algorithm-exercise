#include <stdio.h>
#include <math.h>
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

/*
 * 判断一个数是不是素数
 * 一个大于1的正整数，如果除了1和它本身以外，不能被其他正整数整除，就叫素数。如2，3，5，7，11，13，17…。
 *
 * Returns:
 *   1  - prime
 *   0  - not prime
 *   -1 - undefined (i.e. x < 2)
 */
int is_prime(const int x) {
	if (x < 2) return -1;
	if (x < 4) return 1;
	if((x % 2) == 0) return 0;
	for(int i = 3; i <= floor(sqrt((double) x)); i += 2) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int next_prime(int x) {
	while(is_prime(x) == 0) {
		x++;
	}
	return x;
}
