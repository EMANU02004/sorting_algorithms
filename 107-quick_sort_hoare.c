#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Performs the Hoare partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The pivot index after partitioning
 */

int partition(int* arr, int low, int high)
{
    int pivot;
    int i;
    int j;
    
    pivot = arr[high];
 
    
    i = (low - 1);
 
    for (j = low; j <= high - 1; j++) {
 
       
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick Sort (Hoare)
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void quick_sort_hoare(int* arr, size_t size)
{
    int low = 0;
    int high = size - 1;


    while (low < high) {
        int pivot = partition(arr, low, high);

        if (pivot - low < high - pivot) {
            quick_sort_hoare(arr, pivot - low);
            low = pivot + 1;
        }
        else {
            quick_sort_hoare(arr + pivot + 1, high - pivot);
            high = pivot - 1;
        }
         print_array(arr, size);
    }
}