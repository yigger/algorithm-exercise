#include <stdio.h>
#include <stdlib.h>
#include "array.h"
int main() {
    Array *array;
    createArray(&array);
    
    int arr[] = {1, 23, 242, 432, 432, 122, 32, 32, 21, 21, 453, 43, 23, 32, 32, 4, 2};
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0; i < len; ++i) {
        arrayPush(array, &arr[i]);
        printf("数组长度: %ld, 空余长度: %ld, 需要扩容: %d\n", array->len, array_empty_size(array), check_expend(array));
    }

    for(int i = 0;i < array->used; ++i) {
        printf("output: %d\n", (*(int*)array->items[i]));
    }
    destroyArray(array);
    return 0;
}