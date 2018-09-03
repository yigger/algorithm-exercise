#ifndef __DICT_H
#define __DICT_H

#define DICT_OK 0
#define DICT_ERR 1
#define HT_PRIME_1 151
#define HT_PRIME_2 156
#define HT_INITIAL_BASE_SIZE 53

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

    // 已用元素节点
    unsigned long count;
} dictht;

static dictht *createDict();
static dictht *newDict();
static void dictReSize(dictht *dict, const int reSize);
int *dictAdd(dictht *dict, void *key, void *val);
char *dictSearch(dictht *dict, const char *key);
dictEntry *newEntry(void *key, void *value);
static int ht_hash(const char* s, const int a, const int m);
static int ht_get_hash(const char* s, const int num_buckets, const int attempt);

void resize_up (dictht *dict);
void resize_down (dictht *dict);
void dictDeleteKey(dictht *dict, const char *key);
void deleteDict(dictht *dict);
void deleteEntry(dictEntry *entry);
#endif