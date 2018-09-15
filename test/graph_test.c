#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "graph.h"

static Graph graph;
static int stat;

// TEST_GROUP_C_SETUP(GraphTest) {};

// TEST_GROUP_C_TEARDOWN(GraphTest){};

TEST_C(GraphTest, InitGraph) {
    stat = createGraph(&graph, 12);
    CHECK_EQUAL_C_INT(OK, stat);
};

TEST_C(GraphTest, createEdge) {
    EdgeNode node;
    stat = createEdge(&node, 0);
    CHECK_EQUAL_C_INT(OK, stat);
};

TEST_C(GraphTest, addEdgeToGraph) {
    // stat = addEdgeToGraph(&graph, 0, 1);
    // CHECK_EQUAL_C_INT(OK, stat);
};


