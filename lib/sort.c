#include <stdio.h>
#include "helper.h"
int *chose_sort(int *array, int length) {
  for(int i = 0, minIndex = 0; i < length; ++i) {
    minIndex = i;
    for(int j = i + 1; j < length; ++j) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    swap(&array[i], &array[minIndex]);
  }
  for(int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  return array;
}