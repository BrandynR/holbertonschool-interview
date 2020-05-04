#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to parent node of node to create
 * @value: is the value to put in the new node
 *
 * Return: must return a pointer to new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->n = value;
	if (parent == NULL)
		new->parent = NULL;
	else
		new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
