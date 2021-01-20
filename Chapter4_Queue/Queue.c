#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

queue_t *createQueue(uint32_t capacity)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

    if (NULL == queue)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(queue);
        return NULL;
    }

    queue->length = 0u;
    queue->front_idx = 0u;
    queue->rear_idx = capacity - 1u;
    queue->capacity = capacity;
    queue->data = data;

    return queue;
}

queue_t *freeQueue(queue_t *queue)
{
    if (NULL != queue)
    {
        if (NULL != queue->data)
        {
            free(queue->data);
        }

        free(queue);
    }

    return NULL;
}

bool isFull(queue_t *queue)
{
    return (queue->length == queue->capacity);
}

bool isEmpty(queue_t *queue)
{
    return (0u == queue->length);
}

void enqueue(queue_t *queue, value_type_t value)
{
    if (true == isFull(queue))
    {
        return;
    }

    queue->rear_idx = (queue->rear_idx + 1u) % queue->capacity;
    queue->data[queue->rear_idx] = value;
    queue->length++;
}

value_type_t dequeue(queue_t *queue)
{
    if (true == isEmpty(queue))
    {
        return NO_VALUE;
    }

    value_type_t value = queue->data[queue->front_idx];
    queue->front_idx = (queue->front_idx + 1u) % queue->capacity;
    queue->length--;

    return value;
}

value_type_t front(queue_t *queue)
{
    if (true == isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->front_idx];
}

value_type_t rear(queue_t *queue)
{
    if (true == isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->rear_idx];
}

void printQueue(queue_t *queue)
{
    if (NULL == queue)
    {
        return;
    }

    printf(
        "\nQueue contains %u elements with a capacity of %u.\n",
        queue->length,
        queue->capacity
    );

    for (uint32_t i = 0u; i < queue->length; i++)
    {
        printf("Index: %d, Value: %f\n", i, queue->data[i]);
    }
}
