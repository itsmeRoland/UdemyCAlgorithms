#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printArray(float arr[], uint32_t length)
{
    for (uint32_t i = 0u; i < length; i++)
    {
        if (i < length - 1u)
        {
            printf("%.2f, ", arr[i]);
        }
        else
        {
            printf("%.2f\n", arr[i]);
        }
    }
}

void swapLargest(float arr[], int32_t length, int32_t i)
{
    int32_t largest = i; // Initialize largest as root 
    int32_t left = 2 * i + 1;
    int32_t right = 2 * i + 2;

    // If left child is larger than root 
    if (left < length && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    if (right < length && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        float temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively call the swapLargest 
        swapLargest(arr, length, largest);
    }
}

void heapSort(float arr[], int32_t length)
{
    // Build heap from an unsorted array (rearrange array) 
    for (int32_t i = length / 2 - 1; i >= 0; i--)
        swapLargest(arr, length, i);

    // One by one extract an element from heap 
    for (int32_t i = length - 1; i >= 0; i--)
    {
        // Move current root to end 
        float temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call swapLargest on the reduced heap 
        swapLargest(arr, i, 0);
    }
}

int main()
{
    float data[] = { -10, 20, -20, 40, 12 };

    printArray(data, 5u);
    heapSort(data, 5u);
    printArray(data, 5u);

    return 0;
}
