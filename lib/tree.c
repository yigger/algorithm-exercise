#include "helper.h"
#include "tree.h"
#include <stdlib.h>
#include <stddef.h>

Tree
*initTree() {
    Tree *tree;
    if((tree = zmalloc(sizeof(*tree))) == NULL)
        return NULL;
    tree->root = NULL;
    tree->height = 0;
    tree->nodeSize = 0;
	tree->compare = NULL;
    return tree;
}

Tree
*addNode(Tree *tree, void *value) {
    if (tree->root == NULL) {
        Node *node;
        if ((node = zmalloc(sizeof(*node))) == NULL) {
            return NULL;
        }
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        tree->root = node;
        tree->height = 1;
        tree->nodeSize = 1;
    } else {
        Node *newNode, *node;
		if ((newNode = zmalloc(sizeof(Node*))) == NULL) {
            return NULL;
        }
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        node = tree->root;
        while (1) {
            int compareResult = tree->compare(value, node->value);
            if (compareResult == 0) {
                // free(newNode);
                return NULL;
            }

            if (compareResult == -1) {
                if (node->left == NULL) {
                    node->left = newNode;
                    break;
                }
                node = node->left;
            } else  {
                if (node->right == NULL) {
                    node->right = newNode;
                    break;
                }
                node = node->right;
            }
        }
        newNode->parent = zmalloc(sizeof(Node*));
        newNode->parent = node;
        tree->nodeSize = tree->nodeSize + 1;
    }

    return tree;
}

// 删除节点
// 需要考虑 3 种情况
// 1. 该节点无左右节点，直接删除此节点
// 2. 该节点有左节点或者右节点，删除的节点的父节点连接此左/右节点
// 3. 该节点有左右节点，需要往下找孩子节点，找到最大的孩子节点，删除此节点，然后修改原来要删除的值，如
//    30          35
//   /  \   =>   /
//  25  35      25
// 第三种情况需要考虑递归
Tree *deleteNode(Tree *tree, Node *node) {
    if (tree->root == NULL || node == NULL) return NULL;
    if (node->left == NULL && node->right == NULL) {
        zfree(node);
    } else if (node->left != NULL && node->right == NULL) {
        
    } else if (node->right != NULL && node->left == NULL) {

    } else {

    }
    
    return tree;
}

Node *search(Tree const *tree, void *value) {
    Node *node = tree->root;
    if (node == NULL) return NULL;
    while (1) {
        if (node->left == NULL && node->right == NULL) {
            break;
        }
        int compareResult = tree->compare(node->value, value);
        if (compareResult == 1) {
            node = node->left;
        } else if (compareResult == -1) {
            node = node->right;
        } else {
            break;
        }
    }
    if(node != NULL && tree->compare(node->value, value) != 0) return NULL;
    return node;
}

void
preOrderTraverse(Node *node) {
    if(node == NULL) return;
    printf("value = %d ", (*(int *)node->value));
    // if (node->parent != NULL) {
	// 	printf("parent = %d ", (*(int *)node->parent->value));
    // }
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
