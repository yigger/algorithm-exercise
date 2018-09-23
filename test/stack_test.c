#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "stack.h"

static Stack *stack;
static int stat;

TEST_GROUP_C_SETUP(StackTest) {
    createStack(&stack);
};

TEST_GROUP_C_TEARDOWN(StackTest) {
    destroyStack(stack);
};

TEST_C(StackTest, pushItem) {
    int intVal = 36;
    stat = stackPush(stack, &intVal);
    CHECK_EQUAL_C_INT(stat, OK);

    char charVal = 's';
    stat = stackPush(stack, &charVal);
    CHECK_EQUAL_C_INT(stat, OK);
}

TEST_C(StackTest, popItem) {
    int inputVal = 20;
    void *outputVal;
    stackPush(stack, &inputVal);
    stackPop(stack, &outputVal);
    CHECK_EQUAL_C_INT(inputVal, (int)*(int*)outputVal);
}

TEST_C(StackTest, isEmpty) {
    CHECK_EQUAL_C_INT(1, emptyStack(stack));
    
    int inputVal = 20;
    stackPush(stack, &inputVal);
    CHECK_EQUAL_C_INT(0, emptyStack(stack));
}