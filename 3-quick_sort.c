#include "sort.h"

void swap(int *arr1, int *arr2, int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void recursion(int *array, int low, int  high, size_t size);


/**
 * quick_sort - quick sort algorithm for an array.
 * @array: the array to sort.
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, (int)size - 1, size);
}

/**
 * recursion - recuraive part of the quick sort algorithm
 * @array: the array to sort.
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 */
void recursion(int *array, int low, int  high, size_t size)
{
	int part;

	if (low < high)
	{
		/* To get the patition index or pivot */
		part = partition(array, low, high, size);

		/* recursive call to sort array elements before and afte the partition  */
		recursion(array, low, part - 1, size);
		recursion(array, part + 1, high, size);
	}
}

/**
 * partition - code for partitioning for the quick sort.
 * @array: the array to sort
 * @low: index of smaller elements
 * @high: pivot index
 * @size: size of the array
 *
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j;
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j], array, size);
		}
	}
	swap(&array[i + 1], &array[high], array, size);
	return (i + 1);
}

/**
 * swap - function to swap two values in an array
 * @arr1: higher value
 * @arr2: lower value
 * @size: size of the array
 * @array: the array to sort
 *
 * Return: Nothing
 */
void swap(int *arr1, int *arr2, int *array, size_t size)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
	print_array(array, size);
}
