#include <stdio.h>
#include <assert.h>

#include "HashTable.h"

int main(void)
{
    hash_table_t *hash_table = createHashTable();

    char name1[] = "Jan";
    char name2[] = "Maxi";
    char name3[] = "Lena";
    char name4[] = "Peter";
    char name5[] = "Lara";

    printf("Key: %s, Idx: %u\n", name1, hash(name1));
    printf("Key: %s, Idx: %u\n", name2, hash(name2));
    printf("Key: %s, Idx: %u\n", name3, hash(name3));
    printf("Key: %s, Idx: %u\n", name4, hash(name4));
    printf("Key: %s, Idx: %u\n", name5, hash(name5));

    hash_table = freeHashTable(hash_table);
    assert(NULL == hash_table);
}
