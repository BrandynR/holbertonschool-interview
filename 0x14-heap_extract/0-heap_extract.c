#include "binary_trees.h"

/**
 * swap_nodes - swap two specified nodes
 * @a: pointer to first node
 * @b: pointer to second node
 * Return: pointer to node containing node a
 */
heap_t *swap_nodes(heap_t *a, heap_t *b)
{
	a->n ^= b->n;
	b->n ^= a->n;
	a->n ^= b->n;

	return (b);
}

/**
 * max_heap - restore max-heap for binary tree
 * @node: pointer to root node
 * Return: pointer to tree node containing data of original node
 */
heap_t *max_heap(heap_t *node)
{
	heap_t *greatest;

	if (node == NULL)
		return (NULL);
	do {
		greatest = NULL;
		if (node->left && node->n <= node->left->n)
			greatest = node->left;
		if (node->right && node->n <= node->right->n &&
				(!greatest || greatest->n < node->right->n))
			greatest = node->right;
		if (greatest != NULL)
			node = swap_nodes(node, greatest);
	} while (greatest != NULL);
	return (node);
}

/**
 * n_node - find n-th node of tree
 * @node: pointer to root node
 * @n: indexed n-th node to find
 * Return: pointer to node, or NULL if error
 */
heap_t *n_node(heap_t *node, int n)
{
	int bit_idx, mask;

	if (!node || n < 0)
		return (NULL);
	for (bit_idx = 0; 1 << (bit_idx + 1) <=  n; ++bit_idx)
		;
	for (--bit_idx; bit_idx >= 0; --bit_idx)
	{
		mask = 1 << bit_idx;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	if (bit_idx > -1)
		return (NULL);
	return (node);
}

/**
 * getSize - gets the size of binary tree
 * @node: pointer to root node ofthe tree
 * Return: size of tree
 */
int getSize(heap_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + getSize(node->left) + getSize(node->right));
}

/**
 * heap_extract - extract root node from max binary heap
 * @root: is a double pointer to root node of heap
 * Return: the value stored in root node
 */
int heap_extract(heap_t **root)
{
	static heap_t *prev_root;
	heap_t *node;
	static int size;
	int data;

	if (root == NULL || *root == NULL)
		return (0);
	if (prev_root != *root || (n_node(*root, size + 1)))
	{
		prev_root = *root;
		size = getSize(*root);
	}
	node = n_node(*root, size);
	if (node->parent)
	{
		data = swap_nodes(*root, node)->n;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
	{
		data = (*root)->n;
		*root = NULL;
	}
	free(node);
	--size;
	max_heap(*root);
	return (data);
}
