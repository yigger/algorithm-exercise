#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

int main() {
    Deque *deque;
    createQueue(&deque);

    int array[] = {20, 15, 23, 1, 2, 5, 6, 12, 23, 10};
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        printf("入队: %d\n", array[i]);
        enqueue(deque, &array[i]);
    }

    int *value;
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        dequeue(deque, (void*)&value);
        printf("出队: %d\n", *value);
    }
    
    destroyQueue(deque);

    return 0;
}