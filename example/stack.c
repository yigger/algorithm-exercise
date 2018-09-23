#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "link.h"
#include "stack.h"

int main () {
    Stack *stack;
    createStack(&stack);
    int array[] = {234, 432, 23, 1, 2, 5, 6, 12, 23, 10};

    // 入栈
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        printf("入栈： %d\n", array[i]);
        stackPush(stack, &array[i]);
    }

    printf("栈内元素： %ld\n", stack->len);
    printf("栈顶指针： %d\n", (int)(*(int*)(stack->top->value)));
    printf("栈底指针： %d\n", (int)(*(int*)(stack->bottom->value)));

    void *value;
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        if (stackPop(stack, &value) == OK) {
            printf("出栈： %d\n", (int)*(int*)value);
        }
    }

    destroyStack(stack);

    return 0;
}
