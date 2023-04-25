#include "sort.h"

void swap(int *arr1, int *arr2);
int partition(int *array, int low, int high);


/**
 * quick_sort - quick sort algorithm for an array.
 * @array: the array to sort.
 * @size: sizeof the array
 *
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = int(size) - 1;

	if (low < high)
	{
		/* To get the patition index or pivot */
		part = partition(array, low, high);

		/* recursive call to sort array elements before and afte the partition  */
		quick_sort(array, low, part - 1);
		quick_sort(array, part + 1, high);
	}
}

/**
 * partition - code for partitioning for the quick sort.
 * @array: the array to sort
 * @low: index of smaller elements
 * @high: pivot index
 *
 * Return: partition index
 */
int partition(int *array, int low, int high)
{
	/* choosing a pivot */
	int pivot = array[high];
	int j;
	int i = low - 1;/* index of smaller element*/

	for (j = 0, j <= high - 1, j++)
	{
		/* If current array element is smaller than the pivot */
		if (array[j] < pivot)
		{
			/*increament smaller element index and swap*/
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], array[high]);
	print_array(array, size);
	return (i + 1);
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
