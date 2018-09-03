#include <stdlib.h>

#ifndef __HELP_H
#define __HELP_H

#define ARR_LENGTH 10

int temp[ARR_LENGTH + 1];
void swap(int *num1, int *num2);
int less(int num1, int num2);
int *copyArray(int *array);
void getResult(int *arr, int length);
void *zmalloc(size_t size);
void *zcalloc(size_t size);
void zfree(void *ptr);
int compareInt(const void *a, const void *b);
int is_prime(const int x);
int next_prime(int x);
#endif