#include "search_algos.h"

/**
 * print_search - print part of array being searched
 * @a: array being searched
 * @l: left boundary index
 * @r: right boundary index
 */
void print_search(int *a, int l, int r)
{
	int i;

	printf("Searching in array: ");
	for (i = l; i <= r; ++i)
		printf("%d%s", a[i], i < r ? ", " : "");
	printf("\n");
}

/**
 * binary_search - a binary search algorithm
 * @a: pointer to the array to search through
 * @target: is the target to find
 * @left: is the left index boundary
 * @right: is the right index boundary
 *
 * Return: index where target found or -1 if target not found
 */
int binary_search(int *a, int target, int left, int right)
{
	int i;

	if (left == right)
	{
		if (a[left] != target)
		{
			print_search(a, left, right);
			return (-1);
		}
		return (left);
	}
	print_search(a, left, right);
	i = (left + right) / 2;
	if (a[i] < target)
		left = i + 1;
	else
		right = i;
	return (binary_search(a, target, left, right));
}

/**
 * advanced_binary - find leftmost value in array using binary search
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: index where value is located
 * -1 if array is NULL, size is 0, or value not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	return (binary_search(array, value, 0, size - 1));
}
