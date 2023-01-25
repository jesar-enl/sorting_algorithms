#include "sort.h"

void swap(int *a, int *b);
void heapify(int *array, size_t count);
void sift_down(int *array, long start, long end, size_t count);

/**
 * heap_sort - sort the array using this algorithm
 * @array: the array to sort
 * @size: the length of the array
 */
void heap_sort(int *array, size_t size)
{
	long end;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end -= 1;
		sift_down(array, 0, end, size);
	}
}

/**
 * swap - swap two values according to their positions
 * @a: first value
 * @b: second value
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - sort the algorithm in form of a heap
 * @array: array to sort
 * @count: the size
 */
void heapify(int *array, size_t count)
{
	long end, start;

	end = count - 1;
	start = (end - 1) / 2;
	while (start >= 0)
	{
		sift_down(array, start, end, count);
		start -= 1;
	}
}

/**
 * sift_down - start tosort
 * @array: array to sort
 * @start: starting point
 * @end: end point
 * @count: length
 */
void sift_down(int *array, long start, long end, size_t count)
{
	long root, child, to_swap;

	root = start;
	to_swap = root;
	child = 2 * root + 1;
	while (child <= end)
	{
		if (array[to_swap] < array[child])
		{
			to_swap = child;
		}
		if ((child + 1 <= end) && (array[to_swap] < array[child + 1]))
			to_swap = child + 1;
		if (to_swap == root)
		{
			return;
		}
		else
		{
			swap(&array[to_swap], &array[root]);

			print_array(array, count);
			root = to_swap;
			child = 2 * root + 1;
		}
	}
}
