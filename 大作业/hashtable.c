#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int JSHash(char *key, unsigned int key_len)
{
    unsigned int hash = 1315423911;
    unsigned int i = 0;

    for (i = 0; i < key_len; key++, i++)
    {
        hash ^= ((hash << 5) + (*key) + (hash >> 2));
    }

    return hash;
}

static void init_hs_node(Hash_node *node)
{
    node->next = NULL;
    node->key = NULL;
    node->value = NULL;
    node->is_occupyed = SMT_HASH_FALSE;
}

Hash_Table *creat_hash_table(void) //创建一张哈希表
{
    Hash_Table *Hs_table = (Hash_Table *)malloc(sizeof(Hash_Table)); //分配哈希表起始地址
    if (!Hs_table)
    {
        printf("no enough memory\n");
        return NULL;
    }

    Hs_table->table = (Hash_node **)malloc(sizeof(Hash_node *) * MAX_TABLE_SIZE); //为哈希表的所有存储节点分配内存
    if (!Hs_table->table)
    {
        printf("no enough memory for table\n");
        free(Hs_table);
        Hs_table = NULL;
        return NULL;
    }

    memset(Hs_table->table, 0, sizeof(Hash_node *) * MAX_TABLE_SIZE);
    return Hs_table;
}

//返回值：	0 成功   -1 失败
int add_node2HashTable(Hash_Table *Hs_table, char *key, unsigned int key_len, void *value)
{
    if (!Hs_table || !key)
    {
        if (!Hs_table)
            printf("Hs_table is null\n");
        else
            printf("key is NULL\n");
        return -1;
    }

    unsigned int i = JSHash(key, key_len) % MAX_TABLE_SIZE; //通过jhash取其键值对应的哈希表下标

    Hash_node *p = Hs_table->table[i];
    Hash_node *pri = p;

    while (p) //该点已经有哈希节点了，需要走到这条链的最后
    {
        if (strncmp(key, p->key, key_len) == 0) //该键值已经存在，更新value
        {
            if (p->is_occupyed)
            {
                free(p->value);
                p->value = value;
                p->is_occupyed = 1;
                break;
            }
        }
        pri = p; // pri始终指向p的上一个位置，用于保留最后一个table[i]的最后一个哈希节点
        p = p->next;
    }

    if (!p) //走到最后或者该点一直没有被占用
    {
        Hash_node *tmp = (Hash_node *)malloc(sizeof(Hash_node));
        if (!tmp)
        {
            printf("no enough memory\n");
            return -1;
        }
        init_hs_node(tmp);
        char *tmp_key = (char *)malloc(key_len + 1);
        if (!tmp_key)
        {
            free(tmp);
            tmp = NULL;
            return -1;
        }
        strncpy(tmp_key, key, key_len);
        tmp_key[key_len] = '\0';
        tmp->key = tmp_key;
        tmp->value = value;
        tmp->is_occupyed = SMT_HASH_TRUE; //更新占用标记

        if (pri == NULL) //该点没有被占用过，直接指
        {
            Hs_table->table[i] = tmp;
        }
        else //该点被占用过，已经走到这条链最后
        {
            pri->next = tmp;
        }
    }

    return 0;
}

/*
    功能：		从哈希表中获取数据
    Hs_table：	哈希表，不能为空
    key：		键值，不能为空
    key_len:	键值长度
    返回值：	存储内容，未找到则为NULL
*/
void *get_value_from_hstable(Hash_Table *Hs_table, char *key, unsigned int key_len)
{
    if (!Hs_table || !key)
    {
        if (!Hs_table)
            printf("Hs_table is null\n");
        else
            printf("key is NULL\n");
        return NULL;
    }

    int i = JSHash(key, key_len) % MAX_TABLE_SIZE;
    Hash_node *tmp = Hs_table->table[i];

    while (tmp)
    {
        if (strncmp(tmp->key, key, key_len) == 0)
        {
            return tmp->value;
        }
        tmp = tmp->next;
    }

    return NULL;
}

void hash_table_delete(Hash_Table *Hs_Table)
{
    if (Hs_Table)
    {
        if (Hs_Table->table)
        {
            int i = 0;
            for (i = 0; i < MAX_TABLE_SIZE; i++) //遍历每一个table
            {
                Hash_node *p = Hs_Table->table[i];
                Hash_node *q = NULL;
                while (p) //该点存在存储内容
                {
                    q = p;
                    free(p->value);
                    free(p->key);
                    p = p->next;
                    free(q);
                }
            }
            free(Hs_Table->table); //释放表存储指针的内存占用
            Hs_Table->table = NULL;
        }
        free(Hs_Table); //释放表指针
        Hs_Table = NULL;
    }
    return;
}
