#include "stdio.h"
#include "common.h"
#include "graph.h"
int main() {
  Graph *graph;
  createGraph(&graph, 12);
  addEdgeToGraph(graph, 0, 2);
  destroyGraph(graph);
  return 0;
}