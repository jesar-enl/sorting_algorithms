#include "sort.h"

void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort - function to sort using quick sort
 *
 * @array: array to sort
 * @size: the length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper to quick sort
 *
 * @array: array to sort
 * @lo: lowest value in array
 * @hi: highest value in array
 * @size: length of array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * partition - function to partition the array in smaller arrays
 *
 * @array: array to sort
 * @lo: low value
 * @hi: high value
 * @size: length of array
 *
 * Return: the new value
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j;
	int pivot;
	int swap = 0;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
