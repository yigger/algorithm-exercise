#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(StackTest) {
  TEST_GROUP_C_SETUP_WRAPPER(StackTest);
  TEST_GROUP_C_TEARDOWN_WRAPPER(StackTest);
};

TEST_C_WRAPPER(StackTest, pushItem);
TEST_C_WRAPPER(StackTest, popItem);
TEST_C_WRAPPER(StackTest, isEmpty);
int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}