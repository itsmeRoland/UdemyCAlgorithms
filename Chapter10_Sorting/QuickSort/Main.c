#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef float value_type_t;

void printArray(value_type_t arr[], uint32_t size)
{
    for (uint32_t i = 0u; i < size; i++)
    {
        if (i < size - 1u)
        {
            printf("%f, ", arr[i]);
        }
        else
        {
            printf("%f\n", arr[i]);
        }
    }
}

void swap(value_type_t *a, value_type_t *b)
{
    value_type_t temp = *a;
    *a = *b;
    *b = temp;
}

int32_t partition(value_type_t arr[], int32_t start, int32_t end)
{
    value_type_t pivot = arr[end];
    int32_t i = start - 1;

    for (int32_t j = start; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return i + 1;
}

void quickSort(value_type_t arr[], int32_t start, int32_t end)
{
    if (start < end)
    {
        int32_t p = partition(arr, start, end);

        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main(void)
{
    value_type_t data[] = {-10, 20, -20, 40, 12};

    printArray(data, 5u);
    quickSort(data, 0u, 4u);
    printArray(data, 5u);
}
