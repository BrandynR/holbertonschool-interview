#include "binary_trees.h"

static int NOMEMORY;

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the heap
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		insert = *root;
	}
	else
	{
		insert = tree_level(root, value);
		maxheapify(&insert);
	}
	return (insert);
}

/**
 * tree_level - moveesthrough the tree in level order
 * @root: double pointer to root node
 * @value: value stored in the node to be inserted
 *
 * Return: a pointer to the inserted node, or return NULL on failure
 */
heap_t *tree_level(heap_t **root, int value)
{
	queue *curq = NULL;
	heap_t *insert, *cur = *root;

	if (push_to_que(&curq, cur) == NULL)
		return (NULL);
	insert = NULL;
	while (curq != NULL)
	{
		cur = curq->node;
		//if (inserted == NULL)
		//	node_insert(cur, &curq, &inserted, &cur->left, value);
		if (insert == NULL)
			node_insert(cur, &curq, &inserted, &cur->right, value);
		if (NOMEMORY != NULL)
			return (NULL);
		pop_que(&curq);
	}
	return (insert);
}

/**
 * push_to_que - pushes address of cur to queue
 * @que_node: double pointer to queue node
 * @cur: pointer to current node
 *
 * Return: pointer to newly created queue node
 */
queue *push_to_que(queue **que_node, heap_t *cur)
{
	queue **curq, *newq = malloc(sizeof(*newq));

	if (newq == NULL)
		return (NULL);
	newq->node = cur;
	newq->next = NULL;

	curq = que_node;
	while (*curq != NULL)
		curq = &(*curq)->next;
	newq->next = *curq;
	*curq = newq;
	return (newq);
}

/**
 * pop_que - pops node from queue
 * @que_node: double pointer to queue node
 */
void pop_que(queue **qnode)
{
	queue *tmp;

	if (*que_node != NULL)
	{
		tmp = *que_node;
		*que_node = (*que_node)->next;
		free(tmp);
	}
}

/**
 * node_insert - pushes a node to the queue, then inserts to binary tree
 * @cur: pointer to current node
 * @curq: double pointer to current queue node
 * @insert: double pointer to inserted node
 * @dir: double pointer to cur direction
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node
 */
heap_t *node_insert(heap_t *cur, queue **curq, heap_t **inserted, heap_t **dir,
		int value)
{
	if (*dir != NULL)
	{
	        if (push_to_que(curq, *dir) == NULL)
			NOMEMORY = 1;
	}
	else
	{
		*dir = binary_tree_node(cur, value);
		if (*dir == NULL)
			NOMEMORY = 1;
		*insert = *dir;
	}
	return (*insert);
}

/**
 * max_heap - swaps the node values so parent is greater than child values
 * @insert: node value 'n' to be swapped
 */
void max_heap(heap_t **insert)
{
	heap_t *cur;
	int tmp;

	for (cur = *insert; cur->parent; cur = cur->parent)
		if (cur->n > cur->parent->n)
		{
			tmp = cur->parent->n;
			cur->parent->n = cur->n;
			cur->n = tmp;
			*insert = (*insert)->parent;
		}
}

