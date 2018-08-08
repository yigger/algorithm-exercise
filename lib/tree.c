#include "helper.h"
#include "tree.h"
#include <stdlib.h>
#include <stddef.h>

Tree *initTree() {
    Tree *tree;
    if(tree = zmalloc(sizeof(*tree) == NULL)) {
        return NULL;
    }

    tree->root = NULL;
    tree->height = 0;
    tree->nodeSize = 0;
    return tree;
}

