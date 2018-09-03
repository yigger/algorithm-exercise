#include "./dict.h"
#include "./helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static dictEntry HS_DELETED_ITEM = { NULL, NULL };

dictht *
createDict() {
    dictht *dictht;
    if ((dictht = zmalloc(sizeof(*dictht))) == NULL) {
        return NULL;
    }

    dictht->size = 53;
    dictht->count = 0;
    dictht->table = calloc((size_t)dictht->size, sizeof(dictEntry *));
    return dictht;
}

int *
dictAdd(dictht *dict, void *key, void *val) {
    dictEntry *entry = newEntry(key, val);
    int index = ht_get_hash(entry->key, dict->size, 0);
    dictEntry *curEntry = dict->table[index];
    int i = 1;
    while (curEntry != NULL && curEntry != &HS_DELETED_ITEM) {
        index = ht_get_hash(entry->key, dict->size, i);
        curEntry = dict->table[index];
        i ++;
    }
    dict->table[index] = entry;
    printf("元素 %s, index = %d\n", (char*)key, index);
    dict->count ++;
    return DICT_OK;
}

char *
dictSearch(dictht *dict, const char *key) {
    int index = ht_get_hash(key, dict->size, 0);
    int findHashIndex = 0;
    dictEntry *curEntry = dict->table[index];
    while(curEntry != NULL && curEntry != &HS_DELETED_ITEM) {
        if (strcmp((char *)curEntry->key, key) == 0) {
            return (char *)curEntry->value;
        }
        findHashIndex ++;
        index = ht_get_hash(key, dict->size, findHashIndex);
        curEntry = dict->table[index];
    }
    return NULL;
}

void dictDeleteKey(dictht *dict, const char *key) {
    int index = ht_get_hash(key, dict->size, 0);
    int findHashIndex = 0;
    dictEntry *curEntry = dict->table[index];
    while(curEntry != NULL) {
        if (curEntry != &HS_DELETED_ITEM) {
            if (strcmp((char *)curEntry->key, key) == 0) {
                // 释放空间
                deleteEntry(curEntry);
                // 标记该位置已被删除
                dict->table[findHashIndex] = &HS_DELETED_ITEM;
            }
        }
        findHashIndex ++;
        index = ht_get_hash(key, dict->size, findHashIndex);
        curEntry = dict->table[index];
    }
    dict->count --;
}

dictEntry *
newEntry(void *key, void *value) {
    dictEntry *item;
    item = zmalloc(sizeof(*item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

void
deleteEntry(dictEntry *entry) {
    free(entry->key);
    free(entry->value);
    free(entry);
}

// 使用 rehash 的方法
static int 
ht_get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static int
ht_hash(const char* s, const int a, const int m) {
    const int len_s = strlen(s);
    long hash = 0;
    for(int i = 0; i < len_s; ++i) {
        long pw = 1;
        for(int j = 0; j < (len_s - (i+1)); ++j) {
            pw = a * pw; 
        }
        hash += pw * s[i];
        hash = hash % m;
    }
    return (int)hash;
}
