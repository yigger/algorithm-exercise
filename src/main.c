#include <stdio.h>
#include "../lib/helper.h"
#include "../lib/sort.h"
int main() {
	int const array[] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};

	chose_sort(array, ARR_LENGTH);
	bubble_sort(array, ARR_LENGTH);
	getchar();
	return 0;
}