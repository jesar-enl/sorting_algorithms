#include "sort.h"

void bitonic_merge(int *array, int l, int r, int direction);
void bitonic_recursion(int *array, int l, int r, int direction, size_t size);

/**
 * bitonic_sort - sort algorithm
 * @array: array to sort
 * @size: length of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function made in the sort
 * @array: array to recurse
 * @l: most left-side element
 * @r: most right-side element
 * @direction: the direction to take when recursing
 * @size: length of the array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - merge the finished parts of the sorting
 * @array: arry to sort
 * @l: left element
 * @r: right element
 * @direction: direction take the sort
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int temp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				temp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = temp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}
}
