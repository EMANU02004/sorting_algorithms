#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays in a bitonic manner
 * @array: The array to be sorted
 * @low: Starting index of the first subarray
 * @count: Number of elements to merge
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void merge(int *array, int low, int count, int dir)
{
    int i;
    if (count > 1)
    {
        int k = count / 2;
        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Swap: %d <-> %d\n", array[i], array[i + k]);
            }
        }
        merge(array, low, k, dir);
        merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort implementation
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
    if (count > 1)
    {
        int k;
        k = count / 2;

        
        bitonic_sort_recursive(array, low, k, 1);

        
        bitonic_sort_recursive(array, low + k, k, 0);

        
        merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort
 * @array: The array to be sorted
 * @size: The size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}


