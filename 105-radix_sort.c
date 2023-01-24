#include "sort.h"

/**
 * getMax - return the value of the largest element in the array
 * @array: array to srt
 * @size: length of the array
 *
 * Return: the maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - sort algorithm
 * @array: array to sort
 * @size: length of the array
 */
void radix_sort(int *array, size_t size)
{
	int *count, *res, max, digit = 1;
	long array_size, i;

	array_size = size;
	max = getMax(array, size);
	count = malloc(sizeof(int) * 10);
	res = malloc(sizeof(int) * array_size);

	if (!count || !res)
		return;

	while (max / digit > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < array_size; i++)
			res[i] = 0;
		for (i = 0; i < array_size; i++)
			count[(array[i] / digit) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = array_size - 1; i >= 0; i--)
		{
			res[count[(array[i] / digit) % 10] - 1] = array[i];
			count[(array[i] / digit) % 10]--;
		}
		for (i = 0; i < array_size; i++)
			array[i] = res[i];
		digit *= 10;
		print_array(array, size);
	}
	free(count);
	free(res);
}
