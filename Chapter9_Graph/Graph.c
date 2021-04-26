#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

graph_t *createGraph(uint32_t num_verticies, uint32_t num_edges)
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));

    if (NULL == graph)
    {
        return NULL;
    }

    size_t verticies_size = num_verticies * sizeof(node_t *);
    node_t **verticies = (node_t **)malloc(verticies_size);

    if (NULL == verticies)
    {
        free(graph);

        return NULL;
    }

    for (uint32_t i = 0u; i < num_verticies; i++)
    {
        verticies[i] = NULL;
    }

    graph->verticies = verticies;
    graph->num_edges = num_edges;
    graph->num_verticies = num_verticies;

    return graph;
}

graph_t *freeGraph(graph_t *graph)
{
    if (NULL != graph->verticies)
    {
        free(graph->verticies);
    }

    if (NULL != graph)
    {
        free(graph);
    }

    return NULL;
}

node_t *createNode(uint32_t node_idx, value_type_t weight, node_t *previous_node)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    node->next = previous_node;
    node->weight = weight;
    node->node_idx = node_idx;

    return node;
}

node_t *freeNode(node_t *node)
{
    if (NULL == node)
    {
        return NULL;
    }

    free(node);

    return NULL;
}

void addEdges(graph_t *graph, edge_t edges[])
{
    for (uint32_t i = 0u; i < graph->num_edges; i++)
    {
        uint32_t start_node_idx = edges[i].start_node_idx;
        uint32_t end_node_idx = edges[i].end_node_idx;
        value_type_t weight = edges[i].weight;

        node_t *start_node = graph->verticies[start_node_idx];
        node_t *end_node = createNode(end_node_idx, weight, start_node);
        graph->verticies[start_node_idx] = end_node;
    }
}

void removeEdges(graph_t *graph)
{
    for (uint32_t i = 0u; i < graph->num_verticies; i++)
    {
        node_t *current_node = graph->verticies[i];

        while (NULL != current_node)
        {
            node_t *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
}

void printGraph(graph_t *graph)
{
    if (NULL == graph)
    {
        return;
    }

    for (uint32_t i = 0u; i < graph->num_verticies; i++)
    {
        printf("Vertex: %u\n", i);
        node_t *current_node = graph->verticies[i];

        while (NULL != current_node)
        {
            printf("(%u, %f)\n", current_node->node_idx, current_node->weight);

            current_node = current_node->next;
        }
    }
}
