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

    if(NULL == list)
    {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0u;

    return list;
}

void rightPush(list_t *list, node_t *node)
{
    if (NULL == node || NULL == list)
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

value_type_t rightPop(list_t *list)
{
    node_t *node = list->tail;
    value_type_t value = *(node->value);

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

    node = freeNode(node);

    return value;
}


void leftPush(list_t *list, node_t *node)
{
    if (NULL == node || NULL == list)
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

value_type_t leftPop(list_t *list)
{
    node_t *node = list->tail;
    value_type_t value = *(node->value);

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

    node = freeNode(node);

    return value;
}

node_t *findValue(list_t *list, value_type_t value)
{
    if (NULL == list)
    {
        return NULL;
    }

    node_t *node = list->head;

    while(NULL != node)
    {
        if(*node->value == value)
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

value_type_t valueAtIndex(list_t *list, uint32_t index)
{
    if(NULL == list || index >= list->length)
    {
        return NO_VALUE;
    }

    uint32_t current_index = 0u;
    node_t *node = list->head;

    while(current_index < list->length)
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
    node_t *current = list->head;

    printf("\nList contains %d elements.\n", list->length);

    while(NULL != current)
    {
        printf("Index: %d, Value: %f", index, *current->value);
        current = current->next;
        index++;
    }
}
