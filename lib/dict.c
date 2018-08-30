#include "./dict.h"
#include "./helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

dictht *
createDict() {
    dictht *dictht;
    if ((dictht = zmalloc(sizeof(*dictht))) == NULL) {
        return NULL;
    }

    dictht->size = 53;
    dictht->used = 0;
    dictht->count = 0;
    dictht->table = calloc((size_t)dictht->size, sizeof(dictEntry *));
    return dictht;
}

int *
dictAdd(dictht *dict, void *key, void *val) {
    dictEntry *entry = newEntry(key, val);
    int index = ht_get_hash(entry->key, dict->size, 0);
    dictEntry *cur_entry = dict->table[index];
    int i = 1;
    while (cur_entry != NULL) {
        index = ht_get_hash(entry->key, dict->size, i);
        cur_entry = dict->table[index];
        i ++;
    }
    dict->table[index] = entry;
    dict->count ++;
    return DICT_OK;
}

dictEntry *
newEntry(void *key, void *value) {
    dictEntry *item;
    item = zmalloc(sizeof(*item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

static int 
ht_get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static int
ht_hash(const char* s, const int a, const int m) {
    // char *s = (char *)key;
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
