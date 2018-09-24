#include <stdio.h>
#include <stdlib.h>
#include "array.h"
int main() {
    Array *array;
    createArray(&array);
    
    int arr[] = {1, 3, 4, 2};
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0; i < len; ++i) {
        arrayAdd(array, &arr[i]);
        printf("索引值： %d, 元素： %d, 数组长度: %ld, 空余长度: %ld, 需要扩容: %d\n",
            i, (*(int*)array->items[i]), array->len, 
            array_empty_size(array), check_expend(array));
    }

    int w = 1000;
    arrayAddAt(array, &w, -1);
    arrayRemoveAt(array, 0);
    arrayRemoveAt(array, -5);
    arrayRemoveAt(array, -5);

    for(int i = 0;i < array->used; ++i) {
        printf("output: %d\n", (*(int*)array->items[i]));
    }
    
    destroyArray(array);
    return 0;
}