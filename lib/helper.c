#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
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

