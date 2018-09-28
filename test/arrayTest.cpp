#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(ArrayTest) {
    TEST_GROUP_C_SETUP_WRAPPER(ArrayTest);
    TEST_GROUP_C_TEARDOWN_WRAPPER(ArrayTest);
};

TEST_C_WRAPPER(ArrayTest, addItem);
TEST_C_WRAPPER(ArrayTest, addItemAt);
TEST_C_WRAPPER(ArrayTest, removeAll);
TEST_C_WRAPPER(ArrayTest, removeAt);
TEST_C_WRAPPER(ArrayTest, copyShallow);
TEST_C_WRAPPER(ArrayTest, copyDeep);

int main(int argc, char **argv) {
    return RUN_ALL_TESTS(argc, argv);
}