#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include "../lib/graph.h"
#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"
TEST(group, name) {
    int a = 5;
    CHECK_EQUAL_C_INT(a, 5);
}

int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}
