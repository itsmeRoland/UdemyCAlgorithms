#include <stdio.h>
#include <assert.h>

#include "Heap.h"

int main(void)
{
    heap_t *heap = createHeap(42.0f);

    heap = freeHeap(heap);
}
