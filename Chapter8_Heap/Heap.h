#ifndef HEAP_H
#define HEAP_H

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

#define DEFAULT_CAPACITY (uint32_t)10u

typedef struct heap
{ 
  uint32_t length;
  uint32_t capacity;
  value_type_t *data;
} heap_t;

heap_t *createHeap();

heap_t *freeHeap(heap_t* heap);

uint32_t parentNode(uint32_t idx);

uint32_t leftChildNode(uint32_t idx);

uint32_t rightChildNode(uint32_t idx);

void insertValue(heap_t *heap, value_type_t value);

value_type_t removeMinimum(heap_t *heap);

void heapify(heap_t *heap, uint32_t idx);

void swap(value_type_t *a, value_type_t *b);

void printHeap(heap_t *heap);

#endif //HEAP_H
