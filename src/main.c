#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../lib/helper.h"
#include "../lib/sort.h"
#include "../lib/tree.h"
int main() {
	int array[] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	// 排序相关
	chose_sort(array, ARR_LENGTH);
	bubble_sort(array, ARR_LENGTH);
	insert_sort(array, ARR_LENGTH);
	no_swap_insert_sort(array, ARR_LENGTH);
	shell_sort(array, ARR_LENGTH);
	merge_sort(array, ARR_LENGTH);
	quick_sort(array, ARR_LENGTH);

	// 二叉树相关
	Tree *tree = initTree();
	tree->compare = &compareInt;
	for(int i = 0;i < ARR_LENGTH; ++i) {
		addNode(tree, &array[i]);
	}

	// int searchVal = 20;
	// Node *findNode = search(tree, &searchVal);
	// if (findNode != NULL) {
	// 	printf("成功命中节点，节点值 = %d，", (*(int*)findNode->value));
	// 	if (findNode->parent != NULL) {
	// 		printf("父节点： %d", (*(int*)((findNode->parent)->value)));
	// 	}
	// 	printf("\n");
	// }
	
	preOrderTraverse(tree->root);

	
	getchar();
	return 0;
}