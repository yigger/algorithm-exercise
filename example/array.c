#include <stdio.h>
#include <stdlib.h>
#include "array.h"

static void printArray(Array *array) {
    printf("-----start print---------\n");
    for(int i = 0;i < array->used; ++i) {
        printf("item: %d\n", *((int*)array->items[i]));
    }
}

static int compare(const void *t1, const void *t2) {
    if (*(int*)t1 > *(int*)t2) {
        return 1;
    } else if (*(int*)t1 < *(int*)t2) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Array *array;
    createArray(&array);

    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    // int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    for(int i = 0;i < len; ++i) {
        arrayAdd(array, &source[i]);
    }

    choseSort(array, &compare);
    printArray(array);

    // int arr[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    // // int arr[] = {15, 16, 4, 13, 32};
    // int len = sizeof(arr)/sizeof(int);
    // for(int i = 0; i < len; ++i) {
    //     arrayAdd(array, &arr[i]);
    //     printf("索引值： %d, 元素： %d, 数组长度: %ld, 空余长度: %ld, 需要扩容: %d\n",
    //         i, (*(int*)array->items[i]), array->len, 
    //         array_empty_size(array), check_expend(array));
    // }
    

    // int w = 1000;
    // arrayAddAt(array, &w, -1);
    // arrayRemoveAt(array, 0);
    // arrayRemoveAt(array, -5);
    // arrayRemoveAt(array, -5);
    // printArray(array);

    // 冒泡排序
    // Array *bubbleArray;
    // arrayCopyShallow(array, &bubbleArray);
    // bubbleSort(bubbleArray, compare);
    // printArray(bubbleArray);

    // // 选择排序
    // Array *choseArray;
    // arrayCopyDeep(array, NULL, &choseArray);
    // choseSort(choseArray, compare);
    // printArray(choseArray);

    // // 插入排序
    // Array *insertArray;
    // arrayCopyDeep(array, NULL, &insertArray);
    // insertSort(insertArray, compare);
    // printArray(insertArray);

    // Array *shell;
    // arrayCopyDeep(array, NULL, &shell);
    // insertSort(shell, compare);
    // printArray(shell);

    // quickSort(array, &compare);
    // printArray(array);

    destroyArray(array);
    return 0;
}