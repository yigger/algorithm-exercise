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
        Node *node = SearchInsertPosition(tree, value);
        if (node->value > value) {
            // 插入到左子树
            
        } else {
            // 插入到右子树

        }
    }

    return tree;
}

Node *SearchInsertPosition(const Tree *tree, void *value) {
    if(tree->root == NULL) return NULL;
    Node *node = tree->root;
    return searchNode(node, value);
}

Node *searchNode(const Node *node, void *value) {
    if (value < node->value && node->left != NULL) {
        searchNode(node->left, value);
    } else if (value > node->value && node->right != NULL) {
        searchNode(node->right, value);
    } else {
        return node;
    }
}

