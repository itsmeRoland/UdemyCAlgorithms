#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

stack_t *createStack(uint32_t capacity)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if (NULL == stack)
    {
        return NULL;
    }

    size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(stack);

        return NULL;
    }

    stack->size = 0u;
    stack->capacity = capacity;
    stack->data = data;

    return stack;
}

stack_t *freeStack(stack_t *stack)
{
    if (NULL != stack)
    {
        if (NULL != stack->data)
        {
            free(stack->data);
        }

        free(stack);
    }

    return NULL;
}

bool isFull(stack_t *stack)
{
    return (stack->size == stack->capacity);
}

bool isEmpty(stack_t *stack)
{
    return (0u == stack->size);
}

void push(stack_t *stack, value_type_t value)
{
    if (true == isFull(stack))
    {
        return;
    }

    stack->data[stack->size] = value;
    stack->size++;
}

value_type_t pop(stack_t *stack)
{
    if (true == isEmpty(stack))
    {
        return NO_VALUE;
    }

    stack->size--;

    return stack->data[stack->size];
}

value_type_t top(stack_t *stack)
{
    if (true == isEmpty(stack))
    {
        return NO_VALUE;
    }

    return stack->data[stack->size - 1u];
}

void printStack(stack_t *stack)
{
    if (NULL == stack)
    {
        return;
    }

    printf(
        "\nStack contains %u elements with a capcity of %u.\n",
        stack->size,
        stack->capacity);

    for (int32_t i = stack->size - 1; i >= 0; i--)
    {
        printf("Index: %d, Value %f\n", i, stack->data[i]);
    }
}
