#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef float value_type_t;

void printArray(value_type_t arr[], uint32_t size)
{
    for (uint32_t i = 0u; i < size; i++)
    {
        if (i < size - 1u)
        {
            printf("%.2f, ", arr[i]);
        }
        else
        {
            printf("%.2f\n", arr[i]);
        }
    }
}

int32_t partition(value_type_t arr[], int32_t low, int32_t high)
{
    value_type_t temp;
    value_type_t pivot = arr[high];
    int32_t i = (low - 1);

    for (int32_t j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(value_type_t arr[], int32_t low, int32_t high)
{
    if (low < high)
    {
        int32_t p_idx = partition(arr, low, high);

        quickSort(arr, low, p_idx - 1);
        quickSort(arr, p_idx + 1, high);
    }
}

int main(void)
{
    value_type_t data[] = { -10, 20, -20, 40, 12 };

    printArray(data, 5u);
    quickSort(data, 0u, 4u);
    printArray(data, 5u);

    return 0;
}
