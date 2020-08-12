#include "search.h"

/**
 * len - returns length of the list
 * @list: pointer to the head of the list
 * Return: the length of the list
 */
int len(skiplist_t *list)
{
	skiplist_t *ptr = list;
	int len = 0;

	while (ptr->next)
	{
		ptr = ptr->next;
		len += 1;
	}
	return (len);
}

/**
 * linear_skip - finds value in a linked list with an express lane
 * @list: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 * Return: pointer with value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t cur_dex = 0, future_dex = 0;
	int found_area = 0;
	skiplist_t *ptr = list, *future;

	while (ptr)
	{
		cur_dex = ptr->index;
		if (ptr->express && !found_area)
		{
			future = ptr->express;
			future_dex = future->index;
			printf("Value checked at index [%ld] = [%d]\n", future_dex, future->n);
			if (future->n >= value)
			{
				printf("Value found between indexes [%ld] and [%ld]\n", cur_dex, future_dex);
				found_area = 1;
			}
			else
				ptr = future;
		}
		else
		{
			if (found_area == 0)
			{
				future_dex = len(list);
				printf("Value found between indexes [%ld] and [%ld]\n", cur_dex, future_dex);
				found_area = 1;
			}
			printf("Value checked at index [%ld] = [%d]\n", cur_dex, ptr->n);
			if (ptr->n == value)
				return (ptr);

			ptr = ptr->next;
		}
	}
	return (NULL);
}
