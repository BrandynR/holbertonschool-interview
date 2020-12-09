#include <limits.h>
#include <stddef.h>
#include "binary_trees.h"


/**
 * bt_height - height of binary tree
 * @tree: tree to check
 * @height: height
 * Return: height of the binary tree
 */
int bt_height(binary_tree_t const *tree, int height)
{
	int left = 0, right = 0;

	if (!tree)
	  {
		return (height);
	  }
	
	height++;
	left = bt_height(tree->left, height);
	right = bt_height(tree->right, height);

	if (left - right > 1 || left - right < -1)
	  {
		return (-1);
	  }

	return (left > right ? left : right);
}


/**
 * sort_tree  - checks to see tree is sorted like binary search tree
 * @tree: tree
 * @small: smallest value in subtree
 * Return: 1 if binary search tree, else 0
 */
int sort_tree(binary_tree_t const *tree, int *vsmall)
{
	int base = INT_MIN;

	if (!small)
		small = &base;
	
	if (!tree)
		return (1);
	
	if (!sort_tree(tree->left, small))
		return (0);
	
	if (tree->n <= *small)
		return (0);
	
	*small = tree->n;
	return (sort_tree(tree->right, val));
}


/**
 * binary_tree_is_avl - check if a binary tree is an AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is AVL tree, 0 otherwise
 */
int binary_tree_is_avl(binary_tree_t const *tree)
{
	if (!tree)
		return (0);
	if (!sort_tree(tree, NULL))
		return (0);
	if (bt_height(tree, 0) < 0)
		return (0);
	return (1);
}
