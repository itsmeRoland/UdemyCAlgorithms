#include <stdio.h>
#include <assert.h>

#include "Queue.h"

int main()
{
    uint32_t capacity = 4;
    queue_t *queue = createQueue(capacity);

    enqueue(queue, 0.0f);
    enqueue(queue, 1.0f);
    enqueue(queue, 2.0f);
    enqueue(queue, 3.0f);

    printQueue(queue);

    assert(0.0f == queue->data[queue->front_idx]);
    assert(1.0f == queue->data[queue->front_idx + 1u]);
    assert(2.0f == queue->data[queue->front_idx + 2u]);
    assert(3.0f == queue->data[queue->front_idx + 3u]);
    assert(4u == queue->capacity);
    assert(4u == queue->length);

    value_type_t value_dequeue1 = dequeue(queue);
    value_type_t value_dequeue2 = dequeue(queue);

    assert(2.0f == queue->data[queue->front_idx]);
    assert(3.0f == queue->data[queue->front_idx + 1u]);
    assert(0.0f == value_dequeue1);
    assert(1.0f == value_dequeue2);
    assert(4u == queue->capacity);
    assert(2u == queue->length);

    value_type_t value_dequeue3 = dequeue(queue);
    value_type_t value_dequeue4 = dequeue(queue);

    assert(2.0f == value_dequeue3);
    assert(3.0f == value_dequeue4);
    assert(4u == queue->capacity);
    assert(0u == queue->length);

    printQueue(queue);

    queue = freeQueue(queue);
    assert(NULL == queue);
}
