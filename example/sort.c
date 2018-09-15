#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "common.h"
#include "sort.h"

int main() {
  int array[] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
  chose_sort(array, ARR_LENGTH);
	bubble_sort(array, ARR_LENGTH);
	insert_sort(array, ARR_LENGTH);
	no_swap_insert_sort(array, ARR_LENGTH);
	shell_sort(array, ARR_LENGTH);
	merge_sort(array, ARR_LENGTH);
	quick_sort(array, ARR_LENGTH);
  
  return 0;
}