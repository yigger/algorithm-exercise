#include "./helper.h"
#include "./tree.h"
#include <stdlib.h>
#include <stddef.h>

Tree *
initTree() {
    Tree *tree;
    if((tree = zmalloc(sizeof(*tree))) == NULL)
        return NULL;
    tree->root = NULL;
    tree->height = 0;
    tree->nodeSize = 0;
	tree->compare = NULL;
    return tree;
}

Tree *
addNode(Tree *tree, void *value) {
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
        insert(tree, tree->root, value);
    }

    return tree;
}

Node *
insert(Tree *tree, Node* node, void *key) {
    /* If the tree is empty, return a new Node */
    if (node == NULL) {
        Node *newNode;
        if ((newNode = zmalloc(sizeof(*newNode))) == NULL) {
            return NULL;
        }
        newNode->value = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        return newNode;
    }

    int compareResult = tree->compare(key, node->value);
    /* Otherwise, recur down the tree */
    if (compareResult == -1) {
        Node *lchild = insert(tree, node->left, key);
        node->left  = lchild;
 
        // Set parent of root of left subtree
        lchild->parent = node;
    }
    else if (compareResult == 1)
    {
        Node *rchild = insert(tree, node->right, key);
        node->right  = rchild;
 
        // Set parent of root of right subtree
        rchild->parent = node;
    }
 
    /* return the (unchanged) Node pointer */
    return node;
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
// Tree *deleteNodeError(Tree *tree, Node *node) {
//     if (tree->root == NULL || node == NULL) return NULL;
//     if (node->left == NULL && node->right == NULL) {
//         // node = NULL;
//         // zfree(node);
//     } else if (node->left != NULL && node->right == NULL) {
//         node->parent->left = node->left;
//         node->left = NULL;
//         // free(node); // why error?
//     } else if (node->right != NULL && node->left == NULL) {
//         node->parent->right = node->right;
//         node->right = NULL;
//     } else {
        
//     }
    
//     return tree;
// }

Node *
minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

Node *
deleteNode(Tree *tree, Node *root, void *key) {
    if (root == NULL) return root;
    int compareResult = tree->compare(key, root->value);
    if (compareResult == -1) {
        root->left = deleteNode(tree, root->left, key);
    } else if (compareResult == 1) {
        root->right = deleteNode(tree, root->right, key);
    } else {
        // 左节点为空或右节点为空
        if (root->left == NULL)
        {
            Node *temp = root->right;
            // free(root); // why error?
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            // free(root); // why error?
            return temp;
        }
        
        // 左右节点均存在，则取右节点部分的最小值，并把该“最小值”替换到要删除的节点的value，最后，删除这个“最小值”
        Node *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(tree, root->right, temp->value);
    }
    return root;
}

Node *
search(Tree const *tree, void *value) {
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
    printf("%d ", (*(int *)node->value));
    // if (node->parent != NULL) {
	// 	printf("parent = %d ", (*(int *)node->parent->value));
    // }
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
	printf("\n");
}
