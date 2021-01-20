#include <stdio.h>
#include <stdint.h>

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

void swap(float *a, float * b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(float arr[], uint32_t length)
{
    for (uint32_t i = 0; i < length - 1; i++)
    {
        for (uint32_t j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    float data[] = {-10, 20, -20, 40, 12};

    printArray(data, 5);
    bubbleSort(data, 5);
    printArray(data, 5);

    return 0;
}
