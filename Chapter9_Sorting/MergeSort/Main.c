#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printArray(float arr[], uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            printf("%.2f, ", arr[i]);
        }
        else
        {
            printf("%.2f\n", arr[i]);
        }
    }
}

void merge(float arr[], uint32_t start, uint32_t mid, uint32_t end)
{
    uint32_t num1 = mid - start + 1;
    uint32_t num2 = end - mid;

    float *arr1 = (float *)malloc(num1 * sizeof(float));
    float *arr2 = (float *)malloc(num2 * sizeof(float));

    for (uint32_t i = 0; i < num1; i++)
    {
        arr1[i] = arr[start + i];
    }

    for (uint32_t j = 0; j < num2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = start;

    while (i < num1 && j < num2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < num1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < num2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}

void divide(float arr[], uint32_t start, uint32_t end)
{
    if (start < end)
    {
        uint32_t mid = (start + end) / 2u;
        divide(arr, start, mid);
        divide(arr, mid + 1u, end);
        merge(arr, start, mid, end);
    }
}

void mergeSort(float arr[], uint32_t length)
{
    divide(arr, 0u, length - 1u);
}

int main()
{
    float data[] = { -10, 20, -20, 40, 12 };

    printArray(data, 5);
    mergeSort(data, 4);
    printArray(data, 5);

    return 0;
}
