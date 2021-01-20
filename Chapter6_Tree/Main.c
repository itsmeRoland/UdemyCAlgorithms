#include <stdio.h>
#include <assert.h>

#include "BinarySearchTree.h"

int main()
{
    node_t *root = createNode(42.0f);
    node_t *node2 = createNode(22.0f);
    node_t *node3 = createNode(52.0f);
    node_t *node4 = createNode(60.0f);

    insertNode(root, node2);
    insertNode(root, node3);
    insertNode(root, node4);

    printf("Start print!\n");
    printTree(root);

    root = removeNode(root, 60.0f);

    printf("Start print!\n");
    printTree(root);

    root = removeNode(root, 42.0f);

    printf("Start print!\n");
    printTree(root);

    node4 = freeNode(node4);
    node3 = freeNode(node3);
    node2 = freeNode(node2);
    root = freeNode(root);
    assert(NULL == root);
    assert(NULL == node2);
    assert(NULL == node3);
    assert(NULL == node4);
}
