#include "stdio.h"
#include "common.h"
#include "graph.h"
int main() {
  Graph graph;
  createGraph(&graph, 12);
  int stat = addEdgeToGraph(&graph, 0, 1);
  printf("return %d \n", stat);

  return 0;
}