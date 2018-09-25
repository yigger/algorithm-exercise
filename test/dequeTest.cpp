#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(DequeTest) {
    TEST_GROUP_C_SETUP_WRAPPER(DequeTest);
    TEST_GROUP_C_TEARDOWN_WRAPPER(DequeTest);
};

TEST_C_WRAPPER(DequeTest, enqueItem);
TEST_C_WRAPPER(DequeTest, dequeItem);

int main (int argc, char **argv) {
    return RUN_ALL_TESTS(argc, argv);
}