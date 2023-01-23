#include "sort.h"

void list_split_merge(int *array, int start, int end, int *copy);
void top_down_merge(int *array, int beg, int mid, int end, int *copy);
void print_range(int *array, int start, int stop);

/**
 * merge_sort - function to sort the list using the merge algorithm
 *
 * @array: the the array to sort
 * @size: the length of the aray
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];

	list_split_merge(array, 0, size, copy);
	free(copy);
}

/**
 * list_split_merge - split the array into simpler small arrays
 * @array: array to split
 * @start: the starting point of the array
 * @end: the last element of the array
 * @copy: a copy of the array being sorted
 */
void list_split_merge(int *array, int start, int end, int *copy)
{
	int mid;

	if (end - start <= 1)
		return;
	mid = (start + end) / 2;

	list_split_merge(array, start, mid, copy);
	list_split_merge(array, mid, end, copy);
	top_down_merge(copy, start, mid, end, array);
}

/**
 * top_down_merge - merging the sorted arrays
 * @array: the array to sort
 * @beg: the beginning of the array
 * @mid: the middle part of the array
 * @end: the end of the array
 * @copy: a copy of the array
 */
void top_down_merge(int *array, int beg, int mid, int end, int *copy)
{
	int i = beg, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_range(copy, beg, mid);
	printf("\n");
	printf("[right]: ");
	print_range(copy, mid, end);
	printf("\n");
	for (k = beg; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i += 1;
		}
		else
		{
			copy[k] = array[j];
			j += 1;
		}
	}
	for (k = beg; k < end; k++)
	{
		array[k] = copy[k];
	}
	printf("[Done]: ");
	print_range(copy, beg, end);
	printf("\n");
}

/**
 * print_range - print the elements of the array
 * @array: the array to print
 * @start: starting point
 * @stop: the end point
 */
void print_range(int *array, int start, int stop)
{
	int i;

	for (i = start; i < stop; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
}
