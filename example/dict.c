#include <stdio.h>
#include "dict.h"

int main() {
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

	printf("已成功添加 %ld 个hash\n", dict->count);

	dictSearch(dict, key[0]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
	puts("更改第一个元素的值");
	dictAdd(dict, key[0], value[2]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
	printf("查询 %s, 结果：%s\n", key[2], dictSearch(dict, key[2]));
	puts("删除第一个元素");
	dictDeleteKey(dict, key[0]);
	printf("查询 %s, 结果：%s\n", key[0], dictSearch(dict, key[0]));
}