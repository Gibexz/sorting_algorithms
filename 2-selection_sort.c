#include "sort.h"

void swap(int *arr1, int *arr2);

/**
 * selection_sort - bubble sort algorithm for an array
 * @array: array pointer
 * @size: array size
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{

    	size_t i, j, mini_idx;

	if (array == NULL)
		return;
	if (size < 2)
		return;

    	/* loop for sorting boundary movement */
   	for (i = 0; i < size - 1; i++)
    	{

        	/* To find the minimum value in the array*/
		mini_idx = i;
        	for (j = i + 1; j < size; j++)
		{
           		if (array[j] < array[mini_idx])
				mini_idx = j;
		}
		if (mini_idx != i)
                {
                        swap(&array[mini_idx], &array[i]);
                        print_array(array, size);
                }
    }
}

/**
 * swap - function to swap two values in an array
 * @arr1: higher value
 * @arr2: lower value
 * 
 * Return: Nothing
 */
void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
