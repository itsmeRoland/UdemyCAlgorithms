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
    struct node *front;
    struct node *back;
    uint32_t size;
} list_t;

/*********************/
/*    FUNCTIONS      */
/*********************/

node_t *createNode(float value);

node_t *freeNode(node_t *node);

list_t *createList(void);

list_t *freeList(list_t *list);

void pushBack(list_t *list, node_t *node);

value_type_t popBack(list_t *list);

void frontPush(list_t *list, node_t *node);

value_type_t frontPop(list_t *list);

void removeNode(list_t *list, node_t *node);

node_t *findValue(list_t *list, float value);

value_type_t valueAtIndex(list_t *list, uint32_t index);

void printList(list_t *list);

#endif // DOUBLE_LINKED_LIST_H
