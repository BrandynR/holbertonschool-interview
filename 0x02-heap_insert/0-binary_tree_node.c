#include "binary_trees.h"
/**
 * binary_tree_node - Creating a Binary tree
 * @parent: parent of actual leaf
 * @value: number inside the leaf
 * Return: return the node or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);
	if (parent == NULL)
	{
		new->parent = NULL;
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		return (new);
	}
	else
	{
		new->parent = parent;
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		return (new);
	}
}

