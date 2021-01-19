#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

stack_t *createStack(uint32_t capacity)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if(NULL == stack)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if(NULL == data)
    {
        free(stack);
        return NULL;
    }

    stack->length = 0u;
    stack->capacity = capacity;
    stack->data = data;

    return stack;
}

stack_t *freeStack(stack_t* stack)
{
    if (NULL != stack)
    {
        if(NULL != stack->data)
        {
            free(stack->data);
        }

        free(stack);
    }

    return NULL;
}

bool isFull(stack_t *stack)
{
    return (stack->length == stack->capacity);
}

bool isEmpty(stack_t *stack)
{
    return (0u == stack->length);
}

void push(stack_t* stack, value_type_t value)
{
    if (true == isFull(stack))
    {
        return;
    }

    stack->data[stack->length] = value;
    stack->length++;
}

value_type_t pop(stack_t *stack)
{
    if (true == isEmpty(stack))
    {
        return NO_VALUE;
    }

    stack->length--;

    return stack->data[stack->length];
}

value_type_t peek(stack_t *stack)
{
    if (true == isEmpty(stack))
    {
        return NO_VALUE;
    }

    return stack->data[stack->length - 1u];
}

void printStack(stack_t *stack)
{
    if (NULL == stack)
    {
        return;
    }

    printf(
        "\nStack contains %u elements with a capacity of %u.\n",
        stack->length,
        stack->capacity
    );

    for (uint32_t i = 0u; i < stack->length; i++)
    {
        printf("Index: %d, Value: %f\n", i, stack->data[i]);
    }
}
