#include "link.h"
#include "common.h"
#include "stack.h"
#include <stdlib.h>

StatusCode createStack(Stack **stack) {
    Stack *s;
    if((s = zmalloc(sizeof(* s))) == NULL) {
        return MALLOC_ERR;
    }
    s->top = s->bottom = NULL;
    s->len = 0;
    *stack = s;
    return OK;
}

// 判断栈是否空
int emptyStack(const Stack * const stack) {
    if (stack->len == 0) {
        return 1;
    } else {
        return 0;
    }
}

// 入栈
StatusCode stackPush(Stack *stack, void *val) {
    listNode *node;
    if(createNode(&node, val) != OK) {
        return ERROR;
    }

    if (stack->len == 0) {
        stack->top = stack->bottom = node;
    } else {
        stack->top->next = node;
        node->prev = stack->top;
        stack->top = node;
    }

    stack->len ++;
    return OK;
}

// 出栈
StatusCode stackPop(Stack *stack, void **val) {
    if (stack->len == 0) {
        return ERROR;
    }
    *val = stack->top->value;
    listNode *prev = NULL;
    if (stack->top->prev != NULL) {
        prev = stack->top->prev;
        prev->next = NULL;
        stack->top->prev = NULL;
    }
    free(stack->top);
    stack->top = prev;
    stack->len --;
    return OK;
}

void destroyStack(Stack *stack) {
    if (stack->len > 0) {
        listNode *node;
        node = stack->bottom;
        while(node) {
            listNode *nextNode = node->next;
            free(node);
            node = nextNode;
        }
    }
    free(stack);
}
