#ifndef GRAPH_H
#define GRAPH_H

/*******************/
/*     INCLUDES    */
/*******************/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)(INFINITY)

typedef struct node
{
    uint32_t node_idx;
    value_type_t weight;
    struct node *next;
} node_t;

typedef struct edge
{
    uint32_t start_node_idx;
    uint32_t end_node_idx;
    value_type_t weight;
} edge_t;

typedef struct graph
{
    uint32_t num_verticies;
    uint32_t num_edges;
    node_t **verticies;
} graph_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

graph_t *createGraph(uint32_t num_verticies, uint32_t num_edges);

graph_t *freeGraph(graph_t *graph);

node_t *createNode(uint32_t node_idx, value_type_t weight, node_t *head);

node_t *freeNode(node_t *node);

void addEdges(graph_t *graph, edge_t edges[]);

void removeEdges(graph_t *graph);

void printGraph(graph_t *graph);

#endif // GRAPH_H
