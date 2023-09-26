#include "sort.h"
/**
 * max_heap - to build the max heap
 * @array: The array to be sorted
 * @i: The index of the root
 * @max: The size of the array
*/

void max_heap(int *array, size_t i, size_t max)
{
    size_t largest;
    size_t left;
    size_t right;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left <= max && array[left] > array[largest])
    {
        largest = left;
    }
    
    if (right <= max && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, max);
        max_heap(array, largest, max);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @num: The number of elements in the array
 */
void heap_sort(int *array, size_t num)
{
    size_t i;
    
    for (i = num / 2 - 1; i >= 0; i--)
    {
        max_heap(array, i, num - 1);
    }

    for (i = num - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, num - 1);
        max_heap(array, 0, i - 1);
    }
}