#include <stdio.h>
#include <assert.h>

#include "DoubleLinkedList.h"

int main(void)
{
    list_t *list = createList();

    node_t *a = createNode(1.0f);
    node_t *b = createNode(2.0f);
    node_t *c = createNode(3.0f);

    assert(NULL != a);
    assert(NULL != b);
    assert(NULL != c);
    assert(NULL == a->next);
    assert(NULL == a->prev);
    assert(1.0f == *a->value);

    pushBack(list, a);
    pushBack(list, b);
    pushBack(list, c);

    assert(a == list->front);
    assert(NULL == list->front->prev);
    assert(b == list->front->next);
    assert(c == list->back);
    assert(NULL == list->back->next);
    assert(3u == list->size);

    value_type_t value_c = popBack(list);
    value_type_t value_b = popBack(list);
    value_type_t value_a = popBack(list);

    assert(1.0f == value_a);
    assert(2.0f == value_b);
    assert(3.0f == value_c);
    assert(NULL == list->front);
    assert(NULL == list->back);
    assert(0u == list->size);

    node_t *d = createNode(4.0f);
    frontPush(list, d);

    node_t *e = createNode(5.0f);
    frontPush(list, e);
    node_t *f = createNode(6.0f);
    frontPush(list, f);

    removeNode(list, e);
    assert(list->front->next == list->back);
    assert(list->front == list->back->prev);
    removeNode(list, f);

    assert(d == list->front);
    assert(NULL == list->front->prev);
    assert(d == list->back);
    assert(NULL == list->back->next);
    assert(1u == list->size);

    printList(list);

    (void)frontPop(list);

    assert(NULL == list->front);
    assert(NULL == list->back);
    assert(0u == list->size);

    list = freeList(list);
    assert(NULL == list);

    return 0;
}
