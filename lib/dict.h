#ifndef __DICT_H
#define __DICT_H

#define DICT_OK 0
#define DICT_ERR 1

typedef struct dictEntry {
    void *key;

    void *value;

    struct dictEntry *next;
} dictEntry;

typedef struct dictht {
    // 哈希表数组
    dictEntry **table;

    // 哈希表大小
    unsigned long size;

    // 已有节点数
    unsigned long used;
} dictht;

// 计算给定键的哈希值
// #define dictHashKey(d, key) (d)->type->hashFunction(key)

dictht *createDict();
int *dictAdd(dictht *dict, void *key, void *val);
static unsigned int _dictKeyIndex(void *key);
dictEntry *dictAddRaw(dictht *dict, void *key);
int *dictAdd(dictht *dict, void *key, void *val);


#endif