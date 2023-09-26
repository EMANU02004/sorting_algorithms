#include "sort.h"

/**
 * merge - the function to merge the subarrays
 * @array: the final array
 * @left: left subarray
 * @right: right subarray
 * @size_left: size of the left subarray
 * @size_right: size of the right subarray
 * Return: nothing
 */

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i, j, k;
    i = j = k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        array[k++] = left[i++];
    }

    while (j < right_size)
    {
        array[k++] = right[j++];
    }
}
/**
 * merge_sort - sorts an array in ascending order
 * @array: array to be sorted
 * @size: size of elements
 * Returns: void
 */

void merge_sort(int *array, size_t size)
{
    size_t mid;
    size_t i;
    int* left;
    int* right;

    if (size <= 1)
    {
        return;
    }

    mid = size / 2;
    /*
        int left[mid];
        int right[size - mid];
        */
    left = (int *)malloc(mid * sizeof(int));
    right = (int *)malloc((size - mid) * sizeof(int));

    if (!left || !right)
    {
        if (left)
            free(left);
        if (right)
            free(right);
        return;
    }

    /*Split the array into two*/
    for (i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }
    for (i = mid; i < size; i++)
    {
        right[i - mid] = array[i];
    }

    /*Recursively sort the two arrays*/
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < mid; i++)
    {
        printf("%d", left[i]);
        if (i < mid - 1)
            printf(", ");
    }
    printf("\n[right]: ");
    for (i = 0; i < size - mid; i++)
    {
        printf("%d", right[i]);
        if (i < size - mid - 1)
            printf(", ");
    }
    printf("\n");

    /*Perform a merge*/
    merge(array, left, mid, right, size - mid);

     printf("[Done]: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}