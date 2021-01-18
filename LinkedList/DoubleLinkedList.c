#include <stdio.h>
#include <stdlib.h>

#include "DoubleLinkedList.h"

/*********************/
/*    FUNCTIONS      */
/*********************/

node_t *createNode(float value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (NULL == node)
    {
        return NULL;
    }

    float *p_value = (float *)malloc(sizeof(float));
    if (!p_value)
    {
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

list_t *createList()
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if(list == NULL)
    {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0u;

    return list;
}

void clearList(list_t *list)
{
    if (list == NULL)
    {
        return;
    }

    uint32_t length = list->length;
    node_t *next;
    node_t *current = list->head;

    while(length > 0u)
    {
        next = current->next;

        current = freeNode(current);

        current = next;
        length--;
    }

    list->length = 0u;
    list->head = NULL;
    list->tail = NULL;
}

void rightPush(list_t *list, node_t *node)
{
    if (NULL == node || list == NULL)
    {
        return;
    }

    if(list->length > 0u)
    {
        node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        node->next = NULL;
        node->prev = NULL;
        list->head = node;
        list->tail = node;
    }

    list->length++;
}

node_t *rightPop(list_t *list)
{
    node_t *node = list->tail;

    if(list->length > 1u)
    {
        list->tail = node->prev;
        list->tail->next = NULL;
    }
    else
    {
        list->tail = NULL;
        list->head = NULL;
    }

    list->length--;

    return node;
}


void leftPush(list_t *list, node_t *node)
{
    if (NULL == node || list == NULL)
    {
        return;
    }

    if(list->length > 0u)
    {
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }

    list->length++;
}

node_t *leftPop(list_t *list)
{
    node_t *node = list->head;

    if(list->length > 1u)
    {
        list->head = node->next;
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
        list->head = NULL;
    }

    list->length--;

    return node;
}

node_t *findValue(list_t *list, float value)
{
    if (list == NULL)
    {
        return NULL;
    }

    node_t *node = list->head;

    while(node != NULL)
    {
        if(*node->value == value)
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

node_t *valueAtIndex(list_t *list, uint32_t index)
{
    if(list == NULL || index >= list->length)
    {
        return NULL;
    }

    uint32_t current_index = 0u;
    node_t *node = list->head;

    while(current_index < list->length)
    {
        if (current_index == index)
        {
            return node;
        }

        node = node->next;
        current_index++;
    }

    return NULL;
}

void printList(list_t *list)
{
    if (list == NULL)
    {
        return;
    }

    uint32_t index = 0;
    node_t *current = list->head;

    printf("\nList contains %d elements.\n", list->length);

    while(NULL != current)
    {
        printf("Index: %d, Value: %f", index, *current->value);
        current = current->next;
        index++;
    }
}
