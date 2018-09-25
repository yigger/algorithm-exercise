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

};

TEST_C(ArrayTest, addItemAt) {
    
};

TEST_C(ArrayTest, removeAll) {
    
};

TEST_C(ArrayTest, removeAt) {
    
};

TEST_C(ArrayTest, copyShallow) {
    
};

TEST_C(ArrayTest, copyDeep) {
    
};
