#include <stdlib.h>
#include "binary_trees.h"


/**
 * build_avl - recursive helper function to build sorted_array_to_avl
 * @arr: array to build from
 * @left: first index to consider
 * @right: first index to ignore
 * @parent: parent of new node
 * Return: 1 on success, else return 0 on failure
 */
int build_avl(int *arr, size_t left, size_t right, avl_t *parent)
{
	avl_t *node;
	size_t index;

	index = left + (right - left - 1) / 2;
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (0);
	node->parent = parent;
	node->n = arr[index];
	node->left = NULL;
	node->right = NULL;
	if (arr[index] < parent->n)
		parent->left = node;
	else
		parent->right = node;
	if (index - left > 0)
		if (!build_avl(arr, left, index, node))
		{
			free(node);
			return (0);
		}
	if (right - index > 1)
		if (!build_avl(arr, index + 1, right, node))
		{
			free(node);
			return (0);
		}
	return (1);
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: array is a pointer to the first element of the array to be converted
 * @size: size is the number of element in the array
 * Return: pointer to root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mid;

	if (size < 1)
		return (NULL);
	mid = (size - 1) / 2;
	root = malloc(sizeof(*root));
	if (root == NULL)
		return (NULL);
	root->parent = NULL;
	root->n = array[mid];
	root->left = NULL;
	root->right = NULL;
	if (mid > 0)
		if (!build_avl(array, 0, mid, root))
		{
			free(root);
			return (NULL);
		}
	if (size - mid > 1)
		if (!build_avl(array, mid + 1, size, root))
		{
			free(root);
			return (NULL);
		}
	return (root);
}
