#include "redblack_tree.h"
#include "common.h"
#include <stdlib.h>

RedBlackTree *
initRedBlackTree() {
    RedBlackTree *tree;
    tree = zmalloc(sizeof(*tree));
    tree->root = NULL;
    tree->nodeSize = 0;
    tree->compare = NULL;
    return tree;
}

RedBlackNode *
initNode(void *value) {
    RedBlackNode *node;
    if((node = zmalloc(sizeof(*node))) == NULL) {
        return NULL;
    }
    node->value = value;
    node->left = node->right = NULL;
    node->color = Red;
    return node;
}

// 1. 插入的元素为根节点，则直接把该节点颜色改变为黑色
// 2. 插入节点的父节点是黑色节点，则不需要做任何操作
// 3. 插入节点的父节点为红色节点
RedBlackTree *
rbAddNode(RedBlackTree *tree, void *value) {
    RedBlackNode *node = initNode(value);
    if (tree->nodeSize == 0) {
        node->color = Black;
        tree->root = node;
    } else {
        // while ()
    }
    tree->nodeSize ++;
    return tree;
}

// static int
// isRed(RedBlackNode node) {
// 	return node.color == Red;
// }