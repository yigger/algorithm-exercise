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

StatusCode stackPush(Stack *stack, void *val) {
    listNode *node;
    if(createNode(&node, val) != OK) {
        return ERROR;
    }

    if (stack->len == 0) {
        stack->top = stack->bottom = node;
    } else {
        stack->bottom->next = node;
        stack->top = node;
    }

    stack->len ++;
    return OK;
}

void destroyStack(Stack *stack) {
    if (stack->len != 0) {
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
