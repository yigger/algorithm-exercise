#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "stack.h"

static Stack *stack;

TEST_GROUP_C_SETUP(StackTest) {
    createStack(&stack);
};

TEST_GROUP_C_TEARDOWN(StackTest) {
    destroyStack(stack);
};
