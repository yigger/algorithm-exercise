#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(GraphTest) {
  // TEST_GROUP_C_SETUP_WRAPPER(GraphTest); /** optional */
  // TEST_GROUP_C_TEARDOWN_WRAPPER(GraphTest);
};

TEST_C_WRAPPER(GraphTest, InitGraph);

int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}
