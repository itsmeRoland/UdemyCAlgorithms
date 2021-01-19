#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

/*********************/
/*      INCLUDES     */
/*********************/

#include <math.h>
#include <stdint.h>

/*********************/
/* DEFINES AND TYPES */
/*********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)INFINITY

typedef struct node
{
    struct node *next;
    struct node *prev;
    value_type_t *value;
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

list_t *createList(void);

node_t *createNode(float value);
node_t *freeNode(node_t *node);

void rightPush(list_t *list, node_t *node);
value_type_t rightPop(list_t *list);

void leftPush(list_t *list, node_t *node);
value_type_t leftPop(list_t *list);

node_t *findValue(list_t *list, float value);
value_type_t valueAtIndex(list_t *list, uint32_t index);

void printList(list_t *list);

#endif // DOUBLE_LINKED_LIST_H
