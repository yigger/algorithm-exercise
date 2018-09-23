#ifndef __DEQUE_H
#define __DEQUE_H

#include "common.h"
#include "link.h"

typedef struct deque {
    // 队头
    listNode *front;

    // 队尾
    listNode *rear;
    
    // 队列长度
    size_t len;
} Deque;

enum STATE createQueue(Deque **out);
enum STATE enqueue(Deque *deque, void *val);
enum STATE dequeue(Deque *deque, void **out);
void destroyQueue(Deque *deque);
#endif