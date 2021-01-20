#ifndef QUEUE_H
#define QUEUE_H

/*********************/
/*      INCLUDES     */
/*********************/

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/*********************/
/* DEFINES AND TYPES */
/*********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)INFINITY

typedef struct queue
{
    uint32_t front_idx;
    uint32_t rear_idx;
    uint32_t length;
    uint32_t capacity;
    value_type_t * data;
} queue_t;

/*********************/
/*    FUNCTIONS      */
/*********************/

queue_t *createQueue(uint32_t capacity);

queue_t *freeQueue(queue_t* queue);

bool isFull(queue_t* queue);

bool isEmpty(queue_t* queue);

void enqueue(queue_t* queue, value_type_t value);

value_type_t dequeue(queue_t *queue);

value_type_t front(queue_t *queue);

value_type_t rear(queue_t *queue);

void printQueue(queue_t *queue);

#endif // QUEUE_H
