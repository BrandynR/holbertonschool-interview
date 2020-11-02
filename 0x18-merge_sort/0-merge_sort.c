#include "sort.h"
#include <string.h>

/**
 * merging - merge subarrays into a sorted array
 * @arr: array to be sorted
 * @copy: copy of array
 * @left: starting index of left subarray
 * @right: starting index of right subarray
 * @n: size of array
 */
void merging(int *arr, int *copy, size_t left, size_t right, size_t n)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(copy + left, right - left);
	printf("[right]: ");
	print_array(copy + right, n - right);
	for (i = l = left, r = right; i < n; ++i)
	{
		if (l < right && (r >= n || copy[l] <= copy[r]))
			arr[i] = copy[l++];
		else
			arr[i] = copy[r++];
	}
	printf("[Done]: ");
	print_array(arr + left, n - left);
}

/**
 * split - divide unsorted array into subarrays to merge
 * @arr: array to sort
 * @copy: copy of array to be sorted
 * @beg: beginning index
 * @n: size of the array
 */
void split(int *arr, int *copy, size_t beg, size_t n)
{
	size_t mid;

	if (n - beg <= 1)
		return;
	mid = (beg + n) / 2;
	split(copy, arr, beg, mid);
	split(copy, arr, mid, n);
	merging(arr, copy, beg, mid, n);
}

/**
 * merge_sort - sorts array in ascending order using the Merge Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (!array || size < 2)
		return;
	copy = malloc(size * sizeof(*copy));
	if (copy == NULL)
		return;
	memcpy(copy, array, size * sizeof(*copy));
	split(array, copy, 0, size);
	free(copy);
}
