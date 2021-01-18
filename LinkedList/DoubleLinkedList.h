#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdint.h>

/*********************/
/* DEFINES AND TYPES */
/*********************/

typedef struct node
{
    struct node *next;
    struct node *prev;
    float *value;
} node_t;

typedef struct list
{
    struct node *head;
    struct node *tail;
    uint32_t length;
} list_t;

/*********************/
/*    FUNCTIONS      */
/*********************/

list_t *createList();
void clearList(list_t *list);

node_t *createNode(float value);
node_t *freeNode(node_t *node);

void rightPush(list_t *list, node_t *node);
node_t *rightPop(list_t *list);

void leftPush(list_t *list, node_t *node);
node_t *leftPop(list_t *list);

node_t *findValue(list_t *list, float value);
node_t *valueAtIndex(list_t *list, uint32_t index);

void printList(list_t *list);

#endif // DOUBLE_LINKED_LIST_H
