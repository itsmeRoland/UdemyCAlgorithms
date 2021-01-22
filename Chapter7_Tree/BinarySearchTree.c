#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

node_t *createNode(value_type_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = value;

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

void insertNode(node_t *root, node_t *node)
{
    if (NULL == root || NULL == node)
    {
        return;
    }

    node_t *current_node = root;

    while (true)
    {
        if (node->value < current_node->value)
        {
            if (NULL == current_node->left)
            {
                current_node->left = node;
                break;
            }
            else
            {
                current_node = current_node->left;
            }
        }
        else
        {
            if (NULL == current_node->right)
            {
                current_node->right = node;
                break;
            }
            else
            {
                current_node = current_node->right;
            }
        }
    }
}

node_t *minValueNode(node_t *node)
{
    node_t *current = node;

    if (NULL == node)
    {
        return NULL;
    }

    while (NULL != current->left)
    {
        current = current->left;
    }

    return current;
}

node_t *removeNode(node_t *root, value_type_t value)
{
    if (NULL == root)
    {
        return root;
    }

    if (value < root->value)
    {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = removeNode(root->right, value);
    }
    else
    {
        if (NULL == root->left)
        {
            node_t *temp = root->right;

            return temp;
        }
        else if (NULL == root->right)
        {
            node_t *temp = root->left;

            return temp;
        }

        node_t *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }

    return root;
}

void printTree(node_t *root)
{
    if (NULL == root)
    {
        return;
    }

    node_t *left_node = root->left;
    node_t *right_node = root->right;

    value_type_t left_value = left_node != NULL ? left_node->value : NO_VALUE;
    value_type_t right_value = right_node != NULL ? right_node->value : NO_VALUE;

    printf(
        "%.2f\n"
        "/   \\\n"
        "%.2f %.2f\n\n",
        root->value,
        left_value,
        right_value
    );

    printTree(root->left);
    printTree(root->right);
}
