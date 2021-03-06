#include "CppUTest/TestHarness_c.h"
#include "array.h"

static Array *array;
static int stat;

static void *cp(void *val) {
    int *value = (int*)malloc(sizeof(int));
    *value = *(int*)val;
    return value;
}

static int compare(const void *t1, const void *t2) {
    if (*(int*)t1 > *(int*)t2) {
        return 1;
    } else if (*(int*)t1 < *(int*)t2) {
        return -1;
    } else {
        return 0;
    }
}

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
    arrayRemoveAll(array);
    CHECK_EQUAL_C_INT(array->used, 0);
};

TEST_C(ArrayTest, removeAt) {
    stat = arrayRemoveAt(array, 0);
    CHECK_EQUAL_C_INT(stat, OK);
};

TEST_C(ArrayTest, copyShallow) {
    int arr[] = {1, 3, 4, 2, 32, 12, 34, 25, 16};
    int len = 9;
    for(int i = 0;i < len; ++i) {
        arrayAdd(array, &arr[i]);
    }
    Array *copy;
    arrayCopyShallow(array, &copy);
    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)copy->items[i], arr[i]);
    }
};

TEST_C(ArrayTest, copyDeep) {
    int arr[] = {1, 3, 4, 2, 32, 12, 34, 25, 16};
    int len = 9;
    for(int i = 0;i < len; ++i) {
        arrayAdd(array, &arr[i]);
    }
    
    Array *copy;
    arrayCopyDeep(array, &cp, &copy);
    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)copy->items[i], arr[i]);
    }

    Array *copy2;
    arrayCopyDeep(array, NULL, &copy2);
    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)copy2->items[i], arr[i]);
    }
};

TEST_C (ArrayTest, choseSortFunc) {
    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    Array *choseArray;
    createArray(&choseArray);
    for(int i = 0;i < len; ++i) {
        arrayAdd(choseArray, &source[i]);
    }
    
    choseSort(choseArray, &compare);

    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)choseArray->items[i], target[i]);
    }
}

TEST_C (ArrayTest, bubbleSortFunc) {
    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    Array *choseArray;
    createArray(&choseArray);
    for(int i = 0;i < len; ++i) {
        arrayAdd(choseArray, &source[i]);
    }
    
    bubbleSort(choseArray, &compare);

    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)choseArray->items[i], target[i]);
    }
}

TEST_C (ArrayTest, insertSortFunc) {
    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    Array *choseArray;
    createArray(&choseArray);
    for(int i = 0;i < len; ++i) {
        arrayAdd(choseArray, &source[i]);
    }
    
    insertSort(choseArray, &compare);

    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)choseArray->items[i], target[i]);
    }
}

TEST_C (ArrayTest, shellSortFunc) {
    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    Array *choseArray;
    createArray(&choseArray);
    for(int i = 0;i < len; ++i) {
        arrayAdd(choseArray, &source[i]);
    }
    
    shellSort(choseArray, &compare);

    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)choseArray->items[i], target[i]);
    }
}

TEST_C (ArrayTest, quickSortFunc) {
    int source[] = {15, 3, 4, 2, 32, 12, 34, 25, 14};
    int target[] = {2,3,4,12,14,15,25,32,34};
    int len = 9;

    Array *choseArray;
    createArray(&choseArray);
    for(int i = 0;i < len; ++i) {
        arrayAdd(choseArray, &source[i]);
    }
    
    quickSort(choseArray, &compare);

    for(int i = 0;i < len; ++i) {
        CHECK_EQUAL_C_INT(*(int *)choseArray->items[i], target[i]);
    }
}