#include "sort.h"

/**
 * swap - swap position in array of two specified values
 * @a: pointer to the first position
 * @b: pointer to the second position
 */
void swap(int *a, int *b)
{
	*a ^= *b, *b ^= *a, *a ^= *b;
}

/**
 * sift_down - move value down the tree if its children is greater than the value
 * @array: array (represents binary tree)
 * @size: size of array
 * @n: size of array that is still unsorted
 * @i: node to sift-down
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t max, l, r;

	do {
		max = i;
		l = 2 * i + 1;
		r = 2 * i + 2;
		if (l < n && array[l] > array[max])
			max = l;
		if (r < n && array[r] > array[max])
			max = r;
		if (max != i)
		{
			swap(array + i, array + max);
			print_array(array, size);
			i = max, max = 0;
		}
	} while (max != i);
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || !size)
		return;
	for (i = size / 2 - 1; i > -1; --i)
		sift_down(array, size, size, i);
	for (i = size - 1; i > 0; --i)
	{
		swap(array, array + i);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
