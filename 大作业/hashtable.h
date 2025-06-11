#ifndef HASHTABLE_H
#define HASHTABLE_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 1024 //最大表长
#define SMT_HASH_TRUE 1
#define SMT_HASH_FALSE 0


typedef struct hash_node
{
    struct hash_node *next; //如果hash(key)相同，依次往后接
    char *key;              //关键字
    void *value;            //值
    char is_occupyed;       //是否被占用
} Hash_node;

typedef struct hash_table
{
    Hash_node **table; //哈希表
} Hash_Table;

int add_node2HashTable(Hash_Table *Hs_table, char *key, unsigned int key_len, void *value);

void *get_value_from_hstable(Hash_Table *Hs_table, char *key, unsigned int key_len);

void hash_table_delete(Hash_Table *Hs_Table);

Hash_Table *creat_hash_table(void);

#endif