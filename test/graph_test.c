#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "graph.h"

static Graph *graph;
static int stat;
static int edgeSize = 12;

TEST_GROUP_C_SETUP(GraphTest) {
    stat = createGraph(&graph, edgeSize);
};

TEST_GROUP_C_TEARDOWN(GraphTest) {
    destroyGraph(graph);
};

TEST_C(GraphTest, createEdge) {
    EdgeNode *node;
    stat = createEdge(&node, 0);
    CHECK_EQUAL_C_INT(node->adjvex, 0);
    CHECK_EQUAL_C_INT(OK, stat);
};

TEST_C(GraphTest, addEdgeToGraph) {
    addEdgeToGraph(graph, 0, 5);
    CHECK_EQUAL_C_INT(OK, stat);
};

TEST_C(GraphTest, addOverflowEdgeToGraph) {
    stat = addEdgeToGraph(graph, 0, 13);
    CHECK_EQUAL_C_INT(ERROR, stat);
};


