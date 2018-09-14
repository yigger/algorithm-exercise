#include "CppUTest/TestHarness_c.h"

TEST_GROUP_C_SETUP(ArrayTestsWithDefaults)
{

}

TEST_GROUP_C_TEARDOWN(ArrayTestsWithDefaults)
{

}

TEST_C(ArrayTestsWithDefaults, ArrayAdd)
{
    int a = 5;
    CHECK_EQUAL_C_INT(a, 5);
};
