#include "sort.h"
/**
 * swap - Swap two values
 * @array: array
 * @size: size of array
 * @low: low value
 * @high: high value
 * Return: void
 */
void swap(int *array, size_t size, int low, int high)
{
	int temp;

	if (array[low] != array[high])
	{
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
}
/**
 * partition - using Lomuto partition
 * @array: array
 * @size: size of array
 * @low: low value
 * @high: high value
 * Return: int value
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot_value = array[high];

	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			swap(array, size, i, j);

		}
	}
	swap(array, size, i + 1, high);

	return (i + 1);
}
/**
 * quicksort_recursion - quick sort algorithm
 * @array: array
 * @size: size of array
 * @low: low value
 * @high: high value
 */
void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}
/**
 * quick_sort - quick sort function
 *
 * @array: array
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursion(array, size, 0, size - 1);
}
