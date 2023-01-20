#include "sort.h"

/**
 * selection_sort - function to sort using selection mode
 *
 * @array: array to sort
 * @size: the length of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min_index = j - 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}

		swap = array[i];
		array[i] = array[min_index];
		array[min_index] = swap;

		print_array(array, size);
		i++;
	}
}
