#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

hash_table_t *createHashTable(void)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (NULL == hash_table)
    {
        return NULL;
    }

    for (uint32_t i = 0u; i < TABLE_SIZE; i++)
    {
        hash_table->table[i].value = NO_VALUE;
    }

    return hash_table;
}

hash_table_t *freeHashTable(hash_table_t *hash_table)
{
    if (NULL != hash_table)
    {
        free(hash_table);
    }

    return NULL;
}

uint32_t hash(const char key[MAX_NAME_SIZE])
{
    size_t key_length = strlen(key);
    uint32_t hash_value = 0u;

    for (uint32_t i = 0; i < key_length; i++)
    {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void insertItem(hash_table_t *hash_table, item_t *item)
{
    for (uint32_t i = 0; i < TABLE_SIZE; i++)
    {
        int key_compare = strncmp(hash_table->table[i].key, item->key, MAX_NAME_SIZE);
        if (0 == key_compare)
        {
            hash_table->table[i].value = item->value;

            return;
        }
    }

    uint32_t hash_value = hash(item->key);

    while (NO_VALUE != hash_table->table[hash_value].value)
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
    }

    hash_table->table[hash_value] = *item;
}

value_type_t removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = hash(key);
    item_t *item = &hash_table->table[hash_value];

    while (0 != strncmp(key, item->key, MAX_NAME_SIZE))
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
        item = &hash_table->table[hash_value];
    }

    value_type_t value = hash_table->table[hash_value].value;

    hash_table->table[hash_value].value = NO_VALUE;
    strcpy(hash_table->table[hash_value].key, DELETED_KEY);

    return value;
}

value_type_t getValue(hash_table_t *hash_table, char key[MAX_NAME_SIZE])
{
    for (uint32_t i = 0; i < TABLE_SIZE; i++)
    {
        if (0 == strncmp(hash_table->table[i].key, key, MAX_NAME_SIZE))
        {
            return hash_table->table[i].value;
        }
    }

    return NO_VALUE;
}

void printHashTable(hash_table_t *hash_table)
{
    if (NULL == hash_table)
    {
        return;
    }

    printf("\nHashTable values:\n");

    for (uint32_t i = 0u; i < TABLE_SIZE; i++)
    {
        item_t *item = &hash_table->table[i];
        printf("Index: %d, Key: %s, Value: %f\n", i, item->key, item->value);
    }
}
