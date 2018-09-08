#include "./redblack_tree.h"
#include "./helper.h"
#include <stdlib.h>

RedBlackTree *
initTree() {
    RedBlackTree *tree;
    tree = zmalloc(sizeof(*tree));
    tree->root = NULL;
    tree->nodeSize = 0;
    tree->compare = NULL;
    return tree;
}
