#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/*********************/
/*      INCLUDES     */
/*********************/

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/*********************/
/* DEFINES AND TYPES */
/*********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)INFINITY

#define MAX_NAME_SIZE (uint32_t)256u
#define DELETED_KEY "DELETED"

typedef struct item
{
    char key[MAX_NAME_SIZE];
    value_type_t value;
} item_t;

#define TABLE_SIZE (uint32_t)5u

typedef struct hash_table
{
    item_t table[TABLE_SIZE];
} hash_table_t;

/*********************/
/*    FUNCTIONS      */
/*********************/

hash_table_t *createHashTable(void);

hash_table_t *freeHashTable(hash_table_t *hash_table);

uint32_t hash(const char key[MAX_NAME_SIZE]);

void insertItem(hash_table_t *hash_table, item_t *item);

value_type_t removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

value_type_t getValue(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

void printHashTable(hash_table_t *hash_table);

#endif // HASH_TABLE_H
