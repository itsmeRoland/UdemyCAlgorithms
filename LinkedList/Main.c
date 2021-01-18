#include <stdio.h>
#include <stdlib.h>
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

    clearList(list);

    assert(NULL != a); // attention: a does not hold valid values!
    assert(NULL != b); // attention: b does not hold valid values!
    assert(NULL != c); // attention: c does not hold valid values!

    a = NULL;
    b = NULL;
    c = NULL;

    assert(NULL == list->head);
    assert(NULL == list->tail);
    assert(0u == list->length);

    node_t *d = createNode(4.0f);
    leftPush(list, d);

    assert(d == list->head);
    assert(d == list->tail);
    assert(1u == list->length);

    printList(list);

    node_t *popped_d = leftPop(list);

    assert(NULL != popped_d);
    assert(NULL != popped_d->value);
    assert(NULL == list->head);
    assert(NULL == list->tail);
    assert(0u == list->length);

    popped_d = freeNode(popped_d);
    assert(NULL == popped_d);

    return 0;
}
