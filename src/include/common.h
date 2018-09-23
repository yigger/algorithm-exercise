﻿#include <stdlib.h>

#ifndef __HELP_H
#define __HELP_H

#define ARR_LENGTH 10

enum STATE {
	OK = 0,
	MALLOC_ERR = 1,
	ALLOC_ERR = 2,
	ERROR = 3
};

int temp[ARR_LENGTH + 1];
void swap(int *num1, int *num2);
int less(int num1, int num2);
int *copyArray(int *array);
void *zmalloc(size_t size);
void *zcalloc(size_t size);
void zfree(void *ptr);
#endif