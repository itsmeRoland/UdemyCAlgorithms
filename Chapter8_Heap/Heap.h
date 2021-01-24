#ifndef HEAP_H
#define HEAP_H

/*******************/
/*     INCLUDES    */
/*******************/

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)INFINITY

#define DEFAULT_CAPACITY (uint32_t)10u

typedef struct heap
{
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} heap_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

heap_t *createHeap(value_type_t value);

heap_t *freeHeap(heap_t *heap);

void printHeap(heap_t *heap);

#endif // HEAP_H
