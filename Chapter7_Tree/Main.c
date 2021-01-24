#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "BinarySearchTree.h"

int main()
{
    node_t *root = createBST(42.0f);
    node_t *node2 = createBST(22.0f);
    node_t *node3 = createBST(52.0f);
    node_t *node4 = createBST(60.0f);

    printBST(root);

    root = freeBST(root);
    assert(NULL == root);
}
