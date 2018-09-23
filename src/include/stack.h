#ifndef __STACK_H
#define __STACK_H

#include "link.h"
#include "common.h"

typedef enum STATE StatusCode;

typedef struct {
    // 栈顶指针(链表尾元素)
    listNode *top;
    // 栈底元素(链表首元素)
    listNode *bottom;
    // 栈的元素总数
    unsigned long len;
    
} Stack;

StatusCode createStack(Stack **stack);
int emptyStack(const Stack * const stack);
StatusCode stackPush(Stack *stack, void *val);
StatusCode stackPop(Stack *stack, void **val);
void destroyStack(Stack *stack);
#endif