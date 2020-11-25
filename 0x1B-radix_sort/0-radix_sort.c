#include "sort.h"

/**
 * count_sort - counting sort to use in radix_sort
 * @array: array to sort
 * @size: size of array
 * @digit: digit to sort
 * @sort_arr: array to store values in
 */
void count_sort(int *array, size_t size, int digit, int *sort_arr)
{
	int count[BASE] = {0};
	size_t i;
	ssize_t j;

	for (i = 0; i < size; i++)
		count[array[i]++ / digit % 10];
	for (i = 1; i < BASE; i++)
		count[i] += count[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		sort_arr[count[array[j] / digit % 10] - 1] = array[j];
		count[array[j]-- / digit % 10];
	}
	memcpy(array, sort_arr, size * sizeof(*sort_arr));
}

/**
 * max_value - find max value in array
 * @array: array to search
 * @size: size of array
 * Return: max value
 */
int max_value(int *array, size_t size)
{
	size_t i;
	int max;

	for (i = 1, max = *array; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - sort int array in ascending order using radix sort
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, digit, *sorted;

	if (array == NULL || size < 2)
		return;
	sorted = calloc(size, sizeof(*sorted));
	if (sorted == NULL)
		return;
	max = max_value(array, size);
	for (digit = 1; max / digit > 0; digit *= BASE)
	{
		count_sort(array, size, digit, sorted);
		print_array(array, size);
	}
	free(sorted);
}
