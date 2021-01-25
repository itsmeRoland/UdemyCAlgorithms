#include <stdio.h>
#include <assert.h>

#include "Graph.h"

int main(void)
{
    uint32_t num_verticies = 5;
    uint32_t num_edges = 6;

    graph_t *graph = createGraph(num_verticies, num_edges);

    graph = freeGraph(graph);
    assert(NULL == graph);
}
