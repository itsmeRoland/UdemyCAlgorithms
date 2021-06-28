#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "HashTable.h"

int main()
{
    hash_table_t *hash_table = createHashTable();

    item_t item1 = {.key = "Jan", .value = 26.0f};
    item_t item2 = {.key = "Maxi", .value = 27.0f};
    item_t item3 = {.key = "Lena", .value = 21.0f};
    item_t item4 = {.key = "Peter", .value = 42.0f};
    item_t item5 = {.key = "Lara", .value = 31.0f};

    printf("Key: %s, Idx: %u\n", item1.key, hash(item1.key));
    printf("Key: %s, Idx: %u\n", item2.key, hash(item2.key));
    printf("Key: %s, Idx: %u\n", item3.key, hash(item3.key));
    printf("Key: %s, Idx: %u\n", item4.key, hash(item4.key));
    printf("Key: %s, Idx: %u\n", item5.key, hash(item5.key));

    insertItem(hash_table, &item1);
    insertItem(hash_table, &item2);
    insertItem(hash_table, &item3);
    insertItem(hash_table, &item4);
    insertItem(hash_table, &item5);

    printHashTable(hash_table);

    assert(0 == strncmp("Jan", hash_table->data[4].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Maxi", hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lara", hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Peter", hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lena", hash_table->data[11].key, MAX_NAME_SIZE));

    item_t item1_duplicate = {.key = "Jan", .value = -26.0f};
    insertItem(hash_table, &item1_duplicate);
    value_type_t new_value_jan = getValue(hash_table, "Jan");
    assert(-26.0f == new_value_jan);

    printHashTable(hash_table);

    assert(0 == strncmp("Jan", hash_table->data[4].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Maxi", hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lara", hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Peter", hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lena", hash_table->data[11].key, MAX_NAME_SIZE));

    value_type_t value_jan = removeItem(hash_table, "Jan");
    value_type_t value_maxi = removeItem(hash_table, "Maxi");
    value_type_t value_lena = removeItem(hash_table, "Lena");
    value_type_t value_peter = removeItem(hash_table, "Peter");
    value_type_t value_lara = removeItem(hash_table, "Lara");

    assert(-26.0f == value_jan);
    assert(27.0f == value_maxi);
    assert(21.0f == value_lena);
    assert(42.0f == value_peter);
    assert(31.0f == value_lara);

    assert(0 == strncmp(DELETED_KEY, hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[2].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[4].key, MAX_NAME_SIZE));

    assert(NO_VALUE == hash_table->data[0].value);
    assert(NO_VALUE == hash_table->data[1].value);
    assert(NO_VALUE == hash_table->data[2].value);
    assert(NO_VALUE == hash_table->data[3].value);
    assert(NO_VALUE == hash_table->data[4].value);

    printHashTable(hash_table);

    hash_table = freeHashTable(hash_table);
    assert(NULL == hash_table);
}
