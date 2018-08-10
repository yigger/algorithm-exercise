#include "helper.h"
#include "tree.h"
#include <stdlib.h>
#include <stddef.h>

Tree *initTree() {
    Tree *tree;
    if((tree = zmalloc(sizeof(*tree))) == NULL) {
        return NULL;
    }

    tree->root = NULL;
    tree->height = 0;
    tree->nodeSize = 0;
    return tree;
}

Tree *addNode(Tree *tree, void *value) {
    if (tree->root == NULL) {
        Node *node;
        if ((node = zmalloc(sizeof(*node))) == NULL) {
            return NULL;
        }
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        
        tree->root = node;
        tree->height = 1;
        tree->nodeSize = 1;
    } else {
        // printf("not null");
    }

    return tree;
}

