#include "sort.h"

void swap(int* xp, int* yp);
/**
 *
 *
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
        /*Last i elements are already in place*/
        for (j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
	    {
                swap(&array[j], &array[j + 1]);
		print_array(array, size);
	    }
}

/**
 *
 *
 *
 *
 */
void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
