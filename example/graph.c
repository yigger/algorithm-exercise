#include "stdio.h"
#include "common.h"
#include "graph.h"

int main() {
  Graph *graph;
  createGraph(&graph, 4);
  addEdgeToGraph(graph, 0, 1);
  addEdgeToGraph(graph, 0, 2);
  addEdgeToGraph(graph, 1, 3);
  addEdgeToGraph(graph, 2, 3);
  int *marked;
  marked = zcalloc(sizeof(int) * graph->vertexSize);
  dfs(graph, 0, marked);
  destroyGraph(graph);
  return 0;
}