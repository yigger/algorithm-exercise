#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "deque.h"

static Deque *deque;
static int stat;

TEST_GROUP_C_SETUP(DequeTest) {
    stat = createQueue(&deque);
};

TEST_GROUP_C_TEARDOWN(DequeTest) {
    destroyQueue(deque);
};

TEST_C(DequeTest, enqueItem) {
    int val = 5;
    stat = enqueue(deque, &val);
    CHECK_EQUAL_C_INT(stat, OK);
}

TEST_C(DequeTest, dequeItem) {
    int val = 5;
    enqueue(deque, &val);

    int *out;
    dequeue(deque, (void*)&out);
    CHECK_EQUAL_C_INT(val, *out);
}



