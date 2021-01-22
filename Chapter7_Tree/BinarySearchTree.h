#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/*********************/
/*      INCLUDES     */
/*********************/

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/*********************/
/* DEFINES AND TYPES */
/*********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)INFINITY

typedef struct node
{
  value_type_t value;
  struct node *left;
  struct node *right;
} node_t;

/*********************/
/*    FUNCTIONS      */
/*********************/

node_t *createNode(value_type_t value);

node_t *freeNode(node_t *node);

void insertNode(node_t *root, node_t *node);

node_t *minValueNode(node_t *node);

node_t *removeNode(node_t *root, value_type_t value);

void printTree(node_t *root);

#endif // BINARY_SEARCH_TREE_H
