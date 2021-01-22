#include <stdio.h>
#include <stdlib.h>

#include "DoubleLinkedList.h"

/*********************/
/*    FUNCTIONS      */
/*********************/

node_t *createNode(value_type_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    value_type_t *p_value = (value_type_t *)malloc(sizeof(value_type_t));

    if (NULL == p_value)
    {
        free(node);
        return NULL;
    }

    *p_value = value;

    node->prev = NULL;
    node->next = NULL;
    node->value = p_value;

    return node;
}

node_t *freeNode(node_t *node)
{
    if (NULL == node)
    {
        return NULL;
    }

    free(node->value);
    free(node);

    return NULL;
}

list_t *createList(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (NULL == list)
    {
        return NULL;
    }

    list->front = NULL;
    list->back = NULL;
    list->size = 0u;

    return list;
}

list_t *freeList(list_t *list)
{
    if (NULL == list)
    {
        return NULL;
    }

    free(list);

    return NULL;
}

void pushBack(list_t *list, node_t *node)
{
    if (NULL == node || NULL == list)
    {
        return;
    }

    if (list->size > 0u)
    {
        node->next = NULL;
        node->prev = list->back;
        list->back->next = node;
        list->back = node;
    }
    else
    {
        node->next = NULL;
        node->prev = NULL;
        list->front = node;
        list->back = node;
    }

    list->size++;
}

value_type_t popBack(list_t *list)
{
    node_t *node = list->back;
    value_type_t value = *(node->value);

    if (list->size > 1u)
    {
        list->back = node->prev;
        list->back->next = NULL;
    }
    else
    {
        list->back = NULL;
        list->front = NULL;
    }

    list->size--;

    node = freeNode(node);

    return value;
}


void frontPush(list_t *list, node_t *node)
{
    if (NULL == node || NULL == list)
    {
        return;
    }

    if (list->size > 0u)
    {
        node->prev = NULL;
        node->next = list->front;
        list->front->prev = node;
        list->front = node;
    }
    else
    {
        list->front = node;
        list->back = node;
        node->prev = NULL;
        node->next = NULL;
    }

    list->size++;
}

value_type_t frontPop(list_t *list)
{
    node_t *node = list->back;
    value_type_t value = *(node->value);

    if (list->size > 1u)
    {
        list->front = node->next;
        list->front->prev = NULL;
    }
    else
    {
        list->back = NULL;
        list->front = NULL;
    }

    list->size--;

    node = freeNode(node);

    return value;
}

void removeNode(list_t *list, node_t *node)
{
    if (NULL == list || NULL == node)
    {
        return;
    }

    if(NULL != node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        list->front = node->next;
        list->front->prev = NULL;
    }

    if (NULL != node->next)
    {
        node->next->prev = node->prev;
    }
    else
    {
        list->back = node->prev;
        list->back->next = NULL;
    }

    freeNode(node);

    list->size--;
}

node_t *findValue(list_t *list, value_type_t value)
{
    if (NULL == list)
    {
        return NULL;
    }

    node_t *node = list->front;

    while (NULL != node)
    {
        if (*node->value == value)
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

value_type_t valueAtIndex(list_t *list, uint32_t index)
{
    if (NULL == list || index >= list->size)
    {
        return NO_VALUE;
    }

    uint32_t current_index = 0u;
    node_t *node = list->front;

    while (current_index < list->size)
    {
        if (current_index == index)
        {
            return *(node->value);
        }

        node = node->next;
        current_index++;
    }

    return NO_VALUE;
}

void printList(list_t *list)
{
    if (NULL == list)
    {
        return;
    }

    uint32_t index = 0u;
    node_t *current = list->front;

    printf("\nList contains %d elements.\n", list->size);

    while (NULL != current)
    {
        printf("Index: %d, Value: %f", index, *current->value);
        current = current->next;
        index++;
    }
}
