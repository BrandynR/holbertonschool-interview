#include "binary_trees.h"
/**
 * change - change two nodes in order to respect max heap order
 * @small: leaf with smaller n
 * @big: leaf with bigger n
 * @n: 1 if the change was to be in left side or 2 in right side
 * @root: set the pointer to head in some circunstances
 * Return: the new updated node
 */
heap_t *change(heap_t *small, heap_t *big, int n, heap_t **root)
{
	heap_t *aux = small->parent, *r = small->right, *l = small->left;
	heap_t *r1 = big->right, *l1 = big->left;

	big->parent = aux;
	small->parent = big;
	if (aux != NULL)
	{
		if (aux->left == small)
			aux->left = big;
		if (aux->right == small)
			aux->right = big;
	}
	if (big->left != NULL)
		big->left->parent = small;
	if (big->right != NULL)
		big->right->parent = small;
	if (n == 1)
	{
		big->right = r;
		big->left = small;
		if (r != NULL)
			r->parent = big;
	}
	else
	{
		big->left = l;
		big->right = small;
		if (l != NULL)
			l->parent = big;
	}
	small->left = l1;
	small->right = r1;
	if (aux == NULL)
		*root = big;
	return (big);
}

/**
 * depth - return the depth of a binary tree
 * @tree: binary tree to go through
 * Return: 0 if it is already null or 1 or bigger of not
 */
int depth(heap_t *tree)
{
	int left = 1, right = 1, result;

	if (!tree)
		return (0);
	left += depth(tree->left);
	right += depth(tree->right);
	if (right == left)
		result = left + 1;
	else
		result = right < left ? right : left;
	return (result);
}
/**
 * insert_order - insert the node w/o heap order, levels one by one just
 *
 * @head: actual leaf
 * @value: value to save
 * Return: the node in the binary tree
 */
heap_t *insert_order(heap_t *head, int value)
{
	int depthl, depthr;
	heap_t *new = NULL;

	depthl = depth(head->left);
	depthr = depth(head->right);
	if (depthl == 0 || depthr == 0)
	{
		new = malloc(sizeof(heap_t));
		if (new == NULL)
			return (NULL);
		new->n = value;
		if (depthl == 0)
			head->left = new;
		else
			head->right = new;
		new->parent = head;
		new->left = NULL;
		new->right = NULL;
	}
	else if (depthl <= depthr && depthl != 0)
		new = insert_order(head->left, value);
	else if (depthl > depthr)
		new = insert_order(head->right, value);
	return (new);
}
/**
 * sort - sort the binary tree
 * @head: leaf
 * @root: pointer to the head of the binary tree
 * Return: the node updated or the original
 * if it respects the order of max heap
 */
heap_t *sort(heap_t *head, heap_t **root)
{
	heap_t *left, *right;

	if (!head)
		return (head);
	left = sort(head->left, root);
	right = sort(head->right, root);
	if (left == NULL && right == NULL)
		return (head);
	if (left && left->n > head->n)
		return (change(head, head->left, 1, root));
	if (right && right->n > head->n)
		return (change(head, head->right, 2, root));
	return (head);
}
/**
 * heap_insert - Creating a max heap Binary tree
 * @root: pointer to head of binary tree
 * @value: number inside the heap
 * Return: return the node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree;

	if (*root == NULL)
	{
		tree = malloc(sizeof(heap_t));
		if (!tree)
			return (NULL);
		tree->parent = NULL;
		tree->n = value;
		tree->left = NULL;
		tree->right = NULL;
		*root = tree;
		return (tree);
	}
	tree = insert_order(*root, value);
	sort(*root, root);
	return (tree);
}
