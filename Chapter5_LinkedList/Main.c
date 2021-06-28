#include <assert.h>
#include <stdio.h>

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

    printList(list);

    assert(a == list->front);
    assert(NULL == list->front->prev);
    assert(b == list->front->next);
    assert(c == list->back);
    assert(NULL == list->back->next);
    assert(3u == list->size);

    value_type_t value_c = popBack(list);
    value_type_t value_b = popBack(list);
    value_type_t value_a = popBack(list);

    printList(list);

    assert(1.0f == value_a);
    assert(2.0f == value_b);
    assert(3.0f == value_c);
    assert(NULL == list->front);
    assert(NULL == list->back);
    assert(0u == list->size);

    node_t *d = createNode(4.0f);
    pushFront(list, d);
    node_t *e = createNode(5.0f);
    pushFront(list, e);
    popNode(list, 0);

    printList(list);

    assert(d == list->front);
    assert(NULL == list->front->prev);
    assert(d == list->back);
    assert(NULL == list->back->next);
    assert(1u == list->size);

    (void)popFront(list);

    printList(list);

    assert(NULL == list->front);
    assert(NULL == list->back);
    assert(0u == list->size);

    node_t *f = createNode(6.0f);
    node_t *g = createNode(7.0f);
    node_t *h = createNode(8.0f);
    pushBack(list, f);
    pushBack(list, g);
    pushFront(list, h);
    popNode(list, 1);

    printList(list);

    assert(h == list->front);
    assert(g == list->back);
    assert(2u == list->size);

    list = freeList(list);
    assert(NULL == list);

    return 0;
}
