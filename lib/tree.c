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
	tree->compare = NULL;
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
		Node *newNode;
		newNode = zmalloc(sizeof(Node*));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        SearchInsertNewNode(tree, tree->root, newNode);
    }

    return tree;
}

Node *
SearchInsertNewNode(Tree *tree, Node *child, Node *newNode) {
    int compareResult = tree->compare(child->value, newNode->value);
    if (compareResult == 1) {
        // 递归左子树
        if (child->left == NULL) {
            child->left = newNode;
            return child;
        }
        return SearchInsertNewNode(tree, child->left, newNode);
    } else if (compareResult == -1) {
        // 递归右子树
        if (child->right == NULL) {
            child->right = newNode;
            return child;
        }
        return SearchInsertNewNode(tree, child->right, newNode);
    } else {
        // 已存在相同的值
        return NULL;
    }
}

void
preOrderTraverse(Node *node) {
    if(node == NULL) return;
    printf("%d ", (*(int *)node->value));
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
