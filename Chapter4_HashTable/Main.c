#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "HashTable.h"

int main()
{
    hash_table_t *hash_table = createHashTable();

    item_t item1 = { .key="Jan", .value=26.0f };
    item_t item2 = { .key="Maxi", .value=27.0f };
    item_t item3 = { .key="Lena", .value=21.0f };
    item_t item4 = { .key="Peter", .value=42.0f };
    item_t item5 = { .key="Lara", .value=31.0f };

    printf("Key: %s, Idx: %u\n", item1.key, hash(item1.key));
    printf("Key: %s, Idx: %u\n", item2.key, hash(item2.key));
    printf("Key: %s, Idx: %u\n", item3.key, hash(item3.key));
    printf("Key: %s, Idx: %u\n", item3.key, hash(item4.key));
    printf("Key: %s, Idx: %u\n", item3.key, hash(item5.key));

    (void)insertItem(hash_table, item1);
    (void)insertItem(hash_table, item2);
    (void)insertItem(hash_table, item3);
    (void)insertItem(hash_table, item4);
    (void)insertItem(hash_table, item5);

    printHashTable(hash_table);

    item_t item1_duplicate = { .key="Jan", .value=-26.0f };
    bool is_inserted = insertItem(hash_table, item1_duplicate);
    assert(false == is_inserted);

    assert(0 == strncmp("Jan", hash_table->table[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Maxi", hash_table->table[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lara", hash_table->table[2].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Peter", hash_table->table[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lena", hash_table->table[4].key, MAX_NAME_SIZE));
 
    value_type_t value_jan = removeItem(hash_table, "Jan");
    value_type_t value_maxi = removeItem(hash_table, "Maxi");
    value_type_t value_lena = removeItem(hash_table, "Lena");
    value_type_t value_peter = removeItem(hash_table, "Peter");
    value_type_t value_lara = removeItem(hash_table, "Lara");

    assert(26.0f == value_jan);
    assert(27.0f == value_maxi);
    assert(21.0f == value_lena);
    assert(42.0f == value_peter);
    assert(31.0f == value_lara);

    assert(0 == strncmp("DELETED", hash_table->table[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("DELETED", hash_table->table[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("DELETED", hash_table->table[2].key, MAX_NAME_SIZE));
    assert(0 == strncmp("DELETED", hash_table->table[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("DELETED", hash_table->table[4].key, MAX_NAME_SIZE));

    assert(NO_VALUE == hash_table->table[0].value);
    assert(NO_VALUE == hash_table->table[1].value);
    assert(NO_VALUE == hash_table->table[2].value);
    assert(NO_VALUE == hash_table->table[3].value);
    assert(NO_VALUE == hash_table->table[4].value);

    printHashTable(hash_table);
}
