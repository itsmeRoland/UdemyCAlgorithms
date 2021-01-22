#include <stdio.h>
#include <stdlib.h>

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

    for (uint32_t i = 0; i < num_verticies; i++)
    {
        verticies[i] = NULL;
    }

    graph->verticies = verticies;
    graph->num_verticies = num_verticies;
    graph->num_edges = num_edges;

    return graph;
}

graph_t *freeGraph(graph_t *graph)
{
    if (NULL == graph)
    {
        return NULL;
    }

    if (NULL != graph->verticies)
    {
        free(graph->verticies);
    }

    free(graph);

    return NULL;
}

node_t *createNode(uint32_t node_idx, value_type_t weight, node_t *head)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    node->next = head;
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
    for (unsigned i = 0; i < graph->num_edges; i++)
    {
        int start_ver = edges[i].start_ver;
        int end_ver = edges[i].end_ver;
        value_type_t weight = edges[i].weight;
        node_t *new_node = createNode(end_ver, weight, graph->verticies[start_ver]);
        graph->verticies[start_ver] = new_node;
    }
}

void printGraph(graph_t *graph)
{
    for (uint32_t vertex_idx = 0; vertex_idx < graph->num_verticies; vertex_idx++)
    {
        printf("Vertex %d\n", vertex_idx);
        node_t *current_node = graph->verticies[vertex_idx];

        while (NULL != current_node)
        {
            printf("(%d, %.2f)\n", current_node->node_idx, current_node->weight);
            current_node = current_node->next;
        }
    }
}
