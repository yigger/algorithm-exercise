#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../lib/helper.h"
#include "../lib/sort.h"
#include "../lib/tree.h"
#include "../lib/link.h"
#include "../lib/dict.h"
int main() {
	int array[] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	// 排序相关
	puts("-----------排序相关--------------");
	chose_sort(array, ARR_LENGTH);
	bubble_sort(array, ARR_LENGTH);
	insert_sort(array, ARR_LENGTH);
	no_swap_insert_sort(array, ARR_LENGTH);
	shell_sort(array, ARR_LENGTH);
	merge_sort(array, ARR_LENGTH);
	quick_sort(array, ARR_LENGTH);

	// 二叉树相关
	puts("-----------二叉树相关--------------");
	Tree *tree = initTree();
	tree->compare = &compareInt;
	int treeArray[10] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	for(int i = 0;i < 10; ++i) {
		addNode(tree, &treeArray[i]);
	}
	// Node *findNode = search(tree, &array[5]);
	deleteNode(tree, tree->root, &treeArray[1]);
	preOrderTraverse(tree->root);

	// 双端链表相关
	puts("-----------双端链表相关--------------");
	list *list;
	int linkArray[10] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	list = listCreate();
	for(int i = 0;i < 10; ++i) {
		// 在尾部追加元素
		listAddNodeToTail(list, &linkArray[i]);
	}

	int insertVal = 200;
	// 在头部追加元素、尾部追加元素、删除指定元素
	listAddNodeToHead(list, &insertVal);
	listAddNodeToTail(list, &insertVal);
	listDelNode(list, listSearchKey(list, &insertVal));

	// 指定元素前后插入新元素
	int insertAfterVal = 3000;
	listInsertNode(list, listSearchKey(list, &linkArray[0]), &insertAfterVal, 0);
	listInsertNode(list, listSearchKey(list, &linkArray[9]), &insertAfterVal, 1);

	// 遍历链表结果
	listNode *node = list->head;
	while(node != NULL) {
		printf("%d ", (*(int *)node->value));
		node = node->next;
	}
	printf("\n元素寻找结果 - %d\n", (*(int *) listSearchKey(list, &insertVal)->value));

	puts("-----------字典相关， 使用 rehash 实现--------------");
	dictht *dict;
	dict = createDict();
	char *key[128];
	char *value[128];
	for(int i = 0;i < 128; ++i) {
		char str_key[20];
		char str_value[20];
		sprintf(str_key, "key_%d_dict", i);
		key[i] = str_key;
		sprintf(str_value, "value_%d_dict", i);
		value[i] = str_value;
		dictAdd(dict, key[i], value[i]);
	}

	printf("已成功添加 %d 个hash\n", dict->count);

	dictSearch(dict, key[0]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
	puts("更改第一个元素的值");
	dictAdd(dict, key[0], value[2]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
	printf("查询 %s, 结果：%s\n", key[2], dictSearch(dict, key[2]));
	puts("删除第一个元素");
	dictDeleteKey(dict, key[0]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
	
	


	getchar();
	return 0;
}