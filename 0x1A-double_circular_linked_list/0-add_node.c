#include "list.h"

/**
 * new_node - creates a node in linked list
 * @str: string for list of data
 * Return: newly created node
 */
List *new_node(char *str)
{
	List *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);
	return (new);
}

/**
 * new_pointer - pointers are updated
 * @list: linked list
 * @new: pointer to new node
 */
void new_pointer(List **list, List *new)
{
	if (!*list)
	{
		*list = new, (*list)->next = (*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev, new->next = *list;
		(*list)->prev = (*list)->prev->next = new;
	}
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = new_node(str);
	if (!new)
		return (NULL);
	new_pointer(list, new);
	return (new);
}

/**
 * add_node_begin - Add a new node to beginning of double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = new_node(str);
	if (!new)
		return (NULL);
	new_pointer(list, new);
	*list = new;
	return (new);
}
