#include "CppUTest/TestHarness_c.h"
#include <stdio.h>
#include "common.h"
#include "graph.h"


// static int edgeSize = 4;

// TEST_GROUP_C_SETUP(GraphTest) {
//     createGraph(&graph, edgeSize);
// };

// TEST_GROUP_C_TEARDOWN(GraphTest) {
//     destroyGraph(graph);
// };

TEST_C(GraphTest, createEdge) {
    Graph *graph;
    int stat = createGraph(&graph, 4);
    CHECK_EQUAL_C_INT(OK, stat);
    destroyGraph(graph);
};

// TEST_C(GraphTest, addEdgeToGraph) {
//     addEdgeToGraph(graph, 0, 3);
//     CHECK_EQUAL_C_INT(OK, stat);
// };

// TEST_C(GraphTest, addOverflowEdgeToGraph) {
//     stat = addEdgeToGraph(graph, 0, 13);
//     CHECK_EQUAL_C_INT(ERROR, stat);
// };

// TEST_C(GraphTest, dfs) {
//     addEdgeToGraph(graph, 0, 1);
//     addEdgeToGraph(graph, 0, 2);
//     addEdgeToGraph(graph, 1, 3);
//     addEdgeToGraph(graph, 2, 3);
//     int *res = iterator(graph, 0, 0);
//     for(int i = 0; i < graph->vertexSize; ++i) {
//         CHECK_EQUAL_C_INT(res[i], 1);
//     }
// };

