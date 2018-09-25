#include "CppUTest/TestHarness_c.h"
#include "array.h"

static Array *array;
static int stat;

TEST_GROUP_C_SETUP(ArrayTest) {
    stat = createArray(&array);
};

TEST_GROUP_C_TEARDOWN(ArrayTest) {
    destroyArray(array);
};

TEST_C(ArrayTest, addItem) {
    int v = 5;
    int *value;
    stat = arrayAdd(array, &v);
    CHECK_EQUAL_C_INT(stat, OK);
    arrayGetLast(array, (void *)&value);
    CHECK_EQUAL_C_INT(5, *value);
};

TEST_C(ArrayTest, addItemAt) {
    int w = 1000, w1 = 250, *out;
    stat = arrayAddAt(array, &w, 0);
    CHECK_EQUAL_C_INT(stat, OK);

    arrayGetAt(array, 0, (void *)&out);
    CHECK_EQUAL_C_INT(w, *out);

    stat = arrayAddAt(array, &w1, 2);
    CHECK_EQUAL_C_INT(stat, OK);

    arrayGetAt(array, 1, (void *)&out);
    CHECK_EQUAL_C_INT(w1, *out);
};

TEST_C(ArrayTest, removeAll) {
    
};

TEST_C(ArrayTest, removeAt) {
    
};

TEST_C(ArrayTest, copyShallow) {
    
};

TEST_C(ArrayTest, copyDeep) {
    
};
