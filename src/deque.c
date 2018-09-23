#include <stdlib.h>
#include "common.h"
#include "link.h"
#include "deque.h"

// 初始化队列
enum STATE createQueue(Deque **out) {
    Deque *q = zmalloc(sizeof(q));
    if (!q) {
        return MALLOC_ERR;
    }

    q->front = q->rear = NULL;
    q->len = 0;
    *out = q;
    return OK;
}

// 入队
enum STATE enqueue(Deque *deque, void *val) {
    listNode *node;
    if (createNode(&node, val) != OK) {
        return MALLOC_ERR;
    }
    
    if (deque->len == 0) {
        deque->rear = deque->front = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }

    deque->len ++;
    return OK;
}

// 出队
enum STATE dequeue(Deque *deque, void **out) {
    if (deque->len == 0) {
        return ERROR;
    }

    listNode *delItem = deque->rear;
    *out = deque->rear->value;
    deque->rear = deque->rear->prev;
    removeNode(delItem);
    deque->len --;
    return OK;
}

void destroyQueue(Deque *deque) {
    if (deque->len > 0) {
        listNode *node;
        node = deque->front;
        while(node) {
            listNode *nextNode = node->next;
            free(node);
            node = nextNode;
        }
    }
    free(deque);
}
