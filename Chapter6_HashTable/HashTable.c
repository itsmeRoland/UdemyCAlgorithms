#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

hash_table_t *createHashTable(void)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (NULL == hash_table)
    {
        return NULL;
    }

    size_t data_size = TABLE_SIZE * sizeof(item_t);
    item_t *data = (item_t *)malloc(data_size);

    if (NULL == data)
    {
        free(hash_table);

        return NULL;
    }

    hash_table->size = 0u;
    hash_table->capacity = TABLE_SIZE;
    hash_table->data = data;

    return hash_table;
}

hash_table_t *freeHashTable(hash_table_t *hash_table)
{
    if (NULL != hash_table)
    {
        if (NULL != hash_table->data)
        {
            free(hash_table->data);
        }

        free(hash_table);
    }

    return NULL;
}

uint32_t hash(char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = 0u;

    for (uint32_t i = 0; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = (hash_value * 128 + key[i]) % TABLE_SIZE;
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

void printHashTable(hash_table_t *hash_table)
{
    if (NULL == hash_table)
    {
        return;
    }

    printf(
        "\nHashTable contains %u elements with a capcity of %u.\n",
        hash_table->size,
        hash_table->capacity
    );

    for (uint32_t i = 0u; i < hash_table->size; i++)
    {
        item_t *item = &hash_table->data[i];
        printf("Index: %d, Key: %s, Value %f\n", i, item->key, item->value);
    }
}
