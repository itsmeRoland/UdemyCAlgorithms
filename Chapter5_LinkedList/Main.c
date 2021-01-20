#include <stdio.h>
#include <assert.h>

#include "DoubleLinkedList.h"

int main()
{
    list_t *list = createList();

    node_t *a = createNode(1.0f);
    node_t *b = createNode(2.0f);
    node_t *c = createNode(3.0f);

    assert(NULL != a);
    assert(NULL != b);
    assert(NULL != c);

    rightPush(list, a);
    rightPush(list, b);
    rightPush(list, c);

    assert(a == list->head);
    assert(b == list->head->next);
    assert(c == list->tail);
    assert(3u == list->length);

    float value_c = rightPop(list);
    float value_b = rightPop(list);
    float value_a = rightPop(list);

    assert(1.0f == value_a);
    assert(2.0f == value_b);
    assert(3.0f == value_c);

    assert(NULL == list->head);
    assert(NULL == list->tail);
    assert(0u == list->length);

    node_t *d = createNode(4.0f);
    leftPush(list, d);

    assert(d == list->head);
    assert(d == list->tail);
    assert(1u == list->length);

    printList(list);

    (void)leftPop(list);

    assert(NULL == list->head);
    assert(NULL == list->tail);
    assert(0u == list->length);

    list = freeList(list);
    assert(NULL == list);

    return 0;
}
