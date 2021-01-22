#include <stdio.h>
#include <assert.h>

#include "Graph.h"

int main(void)
{
    int num_verticies = 5;
    int num_edges = 6;

    edge_t edges[] = {
        //  (x, y, w)
            {0, 1, 2.0f},
            {0, 2, 4.0f},
            {1, 4, 3.0f},
            {2, 3, 2.0f},
            {3, 1, 4.0f},
            {4, 3, 3.0f}
    };

    graph_t *graph = createGraph(num_verticies, num_edges);

    addEdges(graph, edges);

    printGraph(graph);
}
