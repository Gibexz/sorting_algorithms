#include "sort.h"

/**
 * swap - swaps positions of two elements in an array
 * @arr1: index of first element
 * @arr2: pointer to second element mem space
 *
 */
void swap(int *arr1, int *arr2)
{
	int temp;

	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 *
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (idx = i; idx >= gap &&
			 (array[idx] < array[idx - gap]); idx -= gap)
				swap(&array[idx], &array[idx - gap]);
		print_array(array, size);
		gap /= 3;
	}
}
