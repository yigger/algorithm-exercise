#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(ArrayTestsWithDefaults)
{
  TEST_GROUP_C_SETUP_WRAPPER(ArrayTestsWithDefaults);
  TEST_GROUP_C_TEARDOWN_WRAPPER(ArrayTestsWithDefaults);
};

TEST_C_WRAPPER(ArrayTestsWithDefaults, ArrayAdd);

int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}
