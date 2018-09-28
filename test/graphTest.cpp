#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP_C_WRAPPER(GraphTest) {
  // TEST_GROUP_C_SETUP_WRAPPER(GraphTest);
  // TEST_GROUP_C_TEARDOWN_WRAPPER(GraphTest);
};

TEST_C_WRAPPER(GraphTest, createEdge);
// TEST_C_WRAPPER(GraphTest, addEdgeToGraph);
// TEST_C_WRAPPER(GraphTest, addOverflowEdgeToGraph);
// TEST_C_WRAPPER(GraphTest, dfs);
int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}
